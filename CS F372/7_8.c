#include <stdio.h>
#include <sched.h>
#include <linux/sched.h>
#include <stdlib.h>
#include <string.h>
int main(int *argc, char *argv[])
{
    int policy, ret ;
    struct sched_param sp ;
    struct timespec ts ;
    ret = sched_rr_get_interval(0, &ts);
    printf("Timeslice %lu.%lu\n", ts.tv_sec, ts.tv_nsec);
    printf("Valid priority range for SCHED_FIFO %d %d\n", sched_get_priority_min(SCHED_FIFO), sched_get_priority_max(SCHED_FIFO));
    // policy = (argv[1][0] == 'r') ? SCHED_RR: 
    //         (argv[1][0] == 'f') ? SCHED_FIFO: 
    //         (argv[1][0] == 'b') ? SCHED_BATCH: 
    //         (argv[1][0] == 'i') ? SCHED_IDLE:
    //         SCHED_OTHER ;
    // sp.sched_priority = atoi(argv[2]);
    // if(sched_setscheduler(atoi(argv[3]), policy, &sp) == -1)
    //     exit(-1);
    exit(0);
}