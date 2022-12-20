#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msgbuf {
        long mtype;
        char mtext[200];
};

int main(void)
{
        struct my_msgbuf buf;
        int msqid;
        long m;
        key_t key;
        
        if ((key = ftok("writer.c", 'B')) == -1) { //same as writer.c perror("ftok");
                exit(1);
        }
        
        if ((msqid = msgget(key, 0644)) == -1) {// connect to the queue perror("msgget");
                exit(1);
        }
        
        printf("Reader: ready to receive messages\n");
        
        while(1) {
                if (msgrcv(msqid, &buf, sizeof(buf.mtext), buf.mtype, 0) == -1) {
                        perror("msgrcv");
                        exit(1);
                }
                m=buf.mtype;
                printf("Reader: %ld %s\n", m, buf.mtext);
        }
        
        return 0;
}
