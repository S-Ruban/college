#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
int main(void)
{
    int socket_desc;
    struct sockaddr_in server_addr;
    char server_message[100], client_message[100];
    int server_struct_length = sizeof(server_addr);
    // Clean buffers:
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));
    // Create socket:
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
    while(1)
    {
        // Get input from the user:
        printf("Enter message (exit to terminate): ");
        gets(client_message);
        printf("result of strcmp(input message, 'exit') = %d\n",strcmp(client_message, "exit"));
        // Send the message to server:
        if(sendto(socket_desc, client_message, strlen(client_message), 0, (struct sockaddr*)&server_addr, server_struct_length) < 0)
        {
            printf("Unable to send message\n");
            return -1;
        }
        // Receive the server's response:
        memset(server_message, '\0', sizeof(server_message));
        if(recvfrom(socket_desc, server_message, sizeof(server_message), 0, (struct sockaddr*)&server_addr, &server_struct_length) < 0)
        {
            printf("Error while receiving server's msg\n");
            return -1;
        }
        printf("Server's response: %s\n", server_message);
        if (strcmp(client_message, "exit") == 0)
        {
            printf("loop breaks\n");
            break;
        }
        else
            printf("loop continues\n");

    }
    // Close the socket:
    close(socket_desc);
    return 0;
}