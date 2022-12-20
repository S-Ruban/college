#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#define NO_OF_FRAMES 20
#define TIMER_IN_SECONDS 2
struct Frame
{
    int id ;
    int data ;
    struct timeval sentTime ;
    struct timeval receivedTime ;
    int type ;
} frames[NO_OF_FRAMES], sentFrame;

double beginTime = 0.0 ;
int currentFrame = 0 ;
int resend = 0 ;

void initializeSender();
void startSender();
void startReceiever();
void receiveAcknowledgement();

int main()
{
    srand(time(0));
    struct timeval startTime ;
    gettimeofday(&startTime, NULL);
    beginTime = startTime.tv_sec + (double)startTime.tv_usec/1000000;
    initializeSender();
    startSender();
    return 0 ;
}

void initializeSender()
{
    for(int i = 0; i < NO_OF_FRAMES; i++)
    {
        frames[i].id = i ;
        frames[i].data = rand() % 100 ;
        frames[i].type = 0 ;
    }
}

void startSender()
{
    while (currentFrame < NO_OF_FRAMES)
    {
        if (currentFrame > 0 && !resend)
	{
            printf("%d frames sent. Continue?\nEnter 0 to exit, 1 to continue\n", currentFrame);
            int response; scanf("%d", &response);
            printf("\n");
            if (response == 0)
	     {
                printf("Exiting...\n");
                return ;
            }
        }
        gettimeofday(&frames[currentFrame].sentTime, NULL);
        double currentTime = frames[currentFrame].sentTime.tv_sec + (double)frames[currentFrame].sentTime.tv_usec/1000000 ;
        printf("Sender sending frame %d at time %fs\n", currentFrame + 1, currentTime - beginTime);
        if (rand() % 8)
	{
            sentFrame = frames[currentFrame];
            startReceiever();
	}
 	else
	{
            sleep(TIMER_IN_SECONDS);
            printf("Acknowledgement not received... Resending frame\n");
            resend = 1 ;
        }
    }
    printf("All frames sent. Exiting.\n");
}

void startReceiever()
{
    gettimeofday(&frames[currentFrame].receivedTime, NULL);
    double currentTime = frames[currentFrame].receivedTime.tv_sec + (double)frames[currentFrame].receivedTime.tv_usec/1000000 ;
    printf("Received frame %i at time %fs\n", currentFrame + 1, currentTime - beginTime);
    printf("Frame ID: %d\n", sentFrame.id);
    printf("Data received: %d\n", sentFrame.data);
    printf("Sending acknowledgement back to sender...\n");
    if (rand() % 8)
    {
        sentFrame.type = 1 ;
        receiveAcknowledgement();
    }
    else
    {
        sleep(TIMER_IN_SECONDS);
        printf("Acknowledgement not received... Resending frame\n");
        resend = 1 ;
    }
}

void receiveAcknowledgement()
{
    if (sentFrame.type == 1)
    {
        printf("Acknowledgement received. Sending next frame...\n\n");
        currentFrame++ ;
        resend = 0 ;
    }
}
