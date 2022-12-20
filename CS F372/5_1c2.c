#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int pfds[2];
    char buf[30];
    pipe(pfds);
    if(!fork()) /* child process */ {
        printf("CHILD: writing to the pipe\n");
        write(pfds[1], "test", 5);
        close(pfds[0]);
        printf("Child exiting\n");
        exit(0);
    }
    else /* parent process */{
        printf("PARENT: reading from the pipe\n");
        read(pfds[0], buf, 5);
        close(pfds[1]);
        printf("PARENT: read the string %s\n", buf);
        wait(NULL);
    }
    return 0 ;
}