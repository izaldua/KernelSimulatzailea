#include <stdio.h>
#include <pthread.h>
#include "config.h"

void *timer()
{
    printf("# Timer: Ondo iritsi naiz timer-era.\n");

    int tick1 = 0;
    pthread_mutex_lock(&mutex);
    while (1)
    {
        done++;
        if (tick1 == 200)
        {
            printf("\nIEPA\n");
            tick1 = 0;
        }
        else
        {
            tick1++;
            printf("->   tick1: %d\n", tick1);
        }
        pthread_cond_signal(&cond1);
        pthread_cond_wait(&cond2, &mutex);
    }
}