
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
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
        int msqid; /*used by msgget*/
        key_t key; /*used by ftok*/
        
        /* generate a key*/
        if ((key = ftok("writer.c", 'B')) == -1) {
                perror("ftok");
                exit(1);
        }
        
        /*creating a msg q*/
        if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
                perror("msgget");
                exit(1);
        }
        
        printf("Enter lines of text, ^D to quit:\n");
        /*setting msg type*/
        buf.mtype = 1;
        
        while(fgets(buf.mtext, sizeof(buf.mtext), stdin) != NULL) {
                int len = strlen(buf.mtext);
                
                /* ignore newline at end, if it exists */
                if (buf.mtext[len-1] == '\n')
                        buf.mtext[len-1] = '\0';
                        
                /*send the msg*/
                if (msgsnd(msqid, &buf, len+1, 0) == -1) /*+1 for '\0' */
                        perror("msgsnd");
        }
        
        /*remove the msg q*/
        if (msgctl(msqid, IPC_RMID, NULL) == -1) {
                perror("msgctl");
                exit(1);
        }
        
        return 0;
}
