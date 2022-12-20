#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>
int main()
{
    int pfds[2][2];
    int s ;
    pipe(pfds[0]);
    pipe(pfds[1]);
    if(fork())
    {
        if(fork())
        {
            if(fork())
            {
                wait(&s);
                wait(&s);
                wait(&s);
            }
            else
            {
                dup2(pfds[1][0], 0);
                close(pfds[1][1]);
                execlp("wc", "wc", "-l", NULL);
            }
        }
        else
        {
            pfds[1][0] = pfds[0][1];
            pfds[1][1] = pfds[0][0];
            execlp("grep", "grep", "OS", NULL);
        }
    }
    else
    {
        dup2(pfds[0][1], 1);
        close(pfds[0][0]);
        execlp("ls", "ls", "-l", NULL);
    }
}