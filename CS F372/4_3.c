#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    pid_t child_pid = fork();
    if(child_pid > 0) {
        sleep(10);
        wait(NULL);
        sleep(1);
    }
    else {
        printf("Child PID : %d\n", getpid());
        exit(0);
    }
    return 0 ;
}