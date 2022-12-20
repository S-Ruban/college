#define _REENTRANT
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/uio.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <arpa/inet.h>
#define MAXBUFSIZE 500
#define num 5
/* function prototypes and global variables */
void * process(void *);
int sock, status;
socklen_t socklen;
unsigned char buffer[MAXBUFSIZE]={0};
struct sockaddr_in saddr;
pthread_t thread[num];
void *thread_result;
int broadcast=1;
int res1,res;
int FAIL = -1;
//using namespace std;
int main(int argc, char *argv[])
{
    FILE *fp1 ;
    char ch = {0};
    int ccount = 0 ;
    // SET CONTENT OF STRUCT SADDR AND BUFFER TO ZERO
    memset(&saddr, 0, sizeof(struct sockaddr_in));
    // OPEN A UDP socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
        perror("Error creating socket" );
    saddr.sin_family = AF_INET ;
    saddr.sin_port = htons(5880); //(8904);
    //saddr.sin_addr.s_addr =inet_addr("192.9.200.159");
    saddr.sin_addr.s_addr = INADDR_ANY ;
    socklen = sizeof(struct sockaddr_in);
    //BINDING PROCESS TO PORT
    status = bind(sock, (struct sockaddr * ) &saddr, socklen);
    if(status<0)
        perror("bind error:");
    //SET SOCKET OPTIONS
    status = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char*)&broadcast, sizeof(broadcast));
    perror ("setsockopt::");
    for(int i = 0; i < num; i++)
    {
        /* create a new thread to process the incomming request */
        res = pthread_create(&thread[i], NULL, process, &sock);
        //pthread_create(&readerthreads[i++], NULL, reader, &newSocket)
        if(res)
            printf("\nthread[%ld] creation failed",thread[i]);
        else
            res1 = pthread_join(thread[i], &thread_result);
        sleep(2);
        if(res)
            perror("\nfailed to join");
    } /* the server is now free to accept another socket request */
    return 0;
}
//handling of request by thread
void * process(void *arg)
{
    char server_message[100], client_message[100];
    //pthread_mutex_t lock;
    int mysocfd = *(int *) arg;
    unsigned char buf[MAXBUFSIZE]={0};
    //struct sockaddr_in server_addr, client_addr;
    while(1)
    {
        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));
        printf("Listening for incoming messages...\n\n");
        int len = recvfrom(mysocfd, client_message, MAXBUFSIZE, 0, ( struct sockaddr * )(&saddr), &socklen);
        printf("Child thread [%ld]: My data = %s\n", pthread_self(), client_message);
        // service_count++ ;
        // printf("Child thread [%ld]: The total sockets served = %d\n", pthread_self(), service_count);
        printf("Received message from IP: %s and port: %i\n", inet_ntoa(saddr.sin_addr), ntohs(saddr.sin_port));
        printf("Msg from client: \"%s\"\n", client_message);
        // Change to uppercase:
        for(int i = 0; client_message[i]; ++i)
            client_message[i] = toupper(client_message[i]);
        // Respond to client:
        memset(server_message, '\0', sizeof(server_message));
        strcpy(server_message, client_message);
        if(sendto(mysocfd, server_message, strlen(server_message), 0, (struct sockaddr*)&saddr, sizeof(saddr)) < 0)
        {
            printf("Can't send\n");
            return(&FAIL);
            pthread_exit("client exit");
        }
        if(strcmp(client_message,"exit") == 0 || strcmp(client_message,"EXIT") == 0)
        {
            printf("loop breaks\n");
            break;
        }
        else
            printf("loop continues\n");
        ///////////////////////////////
    }
    /* close the socket and exit this thread */
    close(mysocfd);
    pthread_exit("thread returned");
}