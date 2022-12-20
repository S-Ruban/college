#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        fprintf(stderr, "Fail");
        return 1 ;
    }
    if(pid)
    {
        int *arr ;
        parent:
        arr = (int* )malloc(5*sizeof(int));
        arr[0] = 10 ;
        printf("Parent\nValue = %d\nvariable address : %p\ntext location : %p\n\n", arr[0], &arr, &&parent);
    }
    else
    {
        int *arr ;
        child:
        arr = (int* )malloc(5*sizeof(int));
        arr[0] = 10 ;
        printf("Child\nValue = %d\nvariable address : %p\ntext location : %p\n\n", arr[0], &arr, &&child);
    }
    return 0 ;
}