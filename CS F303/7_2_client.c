#define _REENTRANT
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/uio.h>
#include <unistd.h>
#include <pthread.h>
/* function prototypes and global variables */
void * senddata(void *arg);
int service_count;
int sock, status;
socklen_t socklen;
struct sockaddr_in saddr;
pthread_t thread1;
int broadcast=1;
char server_message[100], client_message[100];
int FAIL = -1 ;

int main(int argc, char *argv[])
{
    FILE *fp1;
    char ch = {0};
    int ccount = 0 ;
    // SET CONTENT OF STRUCT SADDR AND BUFFER TO NULL VALUES
    memset(&saddr, 0, sizeof(struct sockaddr_in));
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));
    // OPEN A UDP SOCKET
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0)
        perror("Error creating socket");
    //SETTING THE ADDRESS STRUCTURE PARAMETERS
    saddr.sin_family = AF_INET ;
    saddr.sin_port = htons (5880);
    // this ip may be specific or any ......
    saddr.sin_addr.s_addr = INADDR_ANY;
    //saddr.sin_addr.s_addr =inet_addr("192.9.200.199");
    socklen = sizeof(struct sockaddr_in);
    //SETTING THE SOCKET OPTIONS
    status = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char*)&broadcast, sizeof (broadcast));
    perror("setsockopt::");
    status = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char*) &broadcast, sizeof(broadcast));
    if(status < 0)
        perror ("Error bind:");
    //send data to the server
    while(1)
    {
        printf("Client: ");
        gets(client_message);
        // Send the message to server:
        if(sendto(sock, client_message, strlen(client_message), 0, (struct sockaddr*)&saddr, socklen) < 0)
        {
            printf("Unable to send message\n");
            return -1;
        }
        if(!strcmp(client_message, "exit"))
            break ;
        // Receive the server's response:
        memset(server_message, '\0', sizeof(server_message));
        if(recvfrom(sock, server_message, sizeof(server_message), 0, (struct sockaddr*)&saddr, &socklen) < 0)
        {
            printf("Error while receiving server's msg\n");
            return -1;
        }
        printf("Server: %s\n", server_message);
    }
    close(sock);
    return 0;
}