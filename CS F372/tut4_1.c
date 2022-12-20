#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int s ;
    if(fork() == 0)
    {
        execlp("ls", "ls", "-la", NULL);
        printf("child done..\n");
    }
        
    else
    {
        wait(&s);
        printf("parent done..\n");
    }
    return 0 ;
}