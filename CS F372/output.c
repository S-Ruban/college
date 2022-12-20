#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t p ;
    p = fork();
    if(p == 0) {
        execlp("a.out", "./", "a.out", NULL);
        printf("\nHello");
        printf("\nHello");
    }
    else {
        printf("\nHello");
        printf("\nHello");
    }
    printf("\nHello");
}