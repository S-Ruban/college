#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
char server_message[100], client_message[100], user[32], sub1[100], sub2[100], day[10];
char intro[13] = "Hi, this is " ;
char whatday[10] = "Is today " ;
char *days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
time_t t ;
struct tm tm ;
int d, m, y ;
void datereset()
{
    d = tm.tm_mday ;
    m = tm.tm_mon ;
    y = tm.tm_year + 1900 ;
}
bool ai()   // AI is just glorified if-else statements
{
    if(!strcmp(client_message, "exit"))
        return false ;
    strncpy(sub1, &client_message[0], 12);
    strncpy(sub2, &client_message[0], 9);
    sub1[12] = '\0' ;
    sub2[9] = '\0' ;
    if(!strcmp(sub1, intro))
    {
        strncpy(user, &client_message[12], strlen(client_message)-11);
        sprintf(server_message, "Hello %s, please send your query", user);
    }
    else if(!strcmp(client_message, "Which day today?"))
    {
        datereset();
        if(!strcmp(days[(d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7], "Wednesday"))   // Stackoverflow hack
            strcpy(server_message, "Today is Wednesday, my dudes.");    // Meme reference
        else
        {
            datereset();
            sprintf(server_message, "Today is %s", days[(d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7]);
        }
        datereset();
    }
        
    else if(!strcmp(client_message, "what is the date today?") || !strcmp(client_message, "today's date please"))
    {
        datereset();
        sprintf(server_message, "Today is %d %s, %d", d, months[m], y);
    }
    else if(!strcmp(sub2, whatday))
    {
        datereset();
        strncpy(day, &client_message[9], strlen(client_message)-10);
        strcat(server_message, day);
        if(!strcmp(days[(d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7], "Wednesday"))
        {
            datereset();
            strcpy(server_message, "Today is Wednesday, my dudes.");
        }
        else
        {
            datereset();
            if(!strcmp(day, days[(d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7]))
                strcpy(server_message, "Yes");
            else
                strcpy(server_message, "No");
            strcat(server_message, ". today is ");
            datereset();
            strcat(server_message, days[(d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7]);
            datereset();
        }
    }
    else
        strcpy(server_message, "My responses are limited. You must ask the right questions.");  // I-Robot reference
    return true ;
}
int main(void)
{
    t = time(NULL);
    tm = *localtime(&t);
    datereset();
    int socket_desc;
    struct sockaddr_in server_addr, client_addr;
    int client_struct_length = sizeof(client_addr);
    // Clean buffers:
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));
    // Create UDP socket:
    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(socket_desc < 0)
    {
        printf("Error while creating socket\n");
        return -1;
    }
    printf("Socket created successfully\n");
    // Set port and IP:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // Bind to the set port and IP:
    if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Couldn't bind to the port\n");
        return -1;
    }
    printf("Done with binding\n");
    while(1)
    {
        // Receive client's message:
        memset(client_message, '\0', sizeof(client_message));
        memset(server_message, '\0', sizeof(server_message));
        if (recvfrom(socket_desc, client_message, sizeof(client_message), 0, (struct sockaddr*)&client_addr, &client_struct_length) < 0)
        {
            printf("Couldn't receive\n");
            return -1;
        }
        printf("Client: %s\n", client_message);
        if(!ai())
            break ;
        printf("Server: %s\n", server_message);
        if (sendto(socket_desc, server_message, strlen(server_message), 0, (struct sockaddr*)&client_addr, client_struct_length) < 0)
        {
            printf("Can't send\n");
            return -1;
        }
    }
    // Close the socket:
    close(socket_desc);
}