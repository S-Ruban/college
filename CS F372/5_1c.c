#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int pfds[2];
    char buf[30];
    if(pipe(pfds) == -1)
    {
        perror("error creating pipe");
        exit(1);
    }
    printf("Writing to the file descriptor %d\n", pfds[1]);
    write(pfds[1], "test", 5);
    printf("Reading from file descriptor %d\n", pfds[0]);
    read(pfds[1], buf, 5);
    return 0 ;
}