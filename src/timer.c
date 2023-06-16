#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"

sem_t sem_sc;
sem_t sem_load;

void *timer_scheduler(long *freq)
{
    printf("# Timer Scheduler: Ondo iritsi naiz timer-era.\n");

    int tick1 = 0;
    long frek = *freq;
    pthread_mutex_lock(&mutex);
    while (1)
    {
        done++;
        if (tick1 == frek)
        {
            sem_post(&sem_sc);
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

void *timer_loader(long *freq)
{
    printf("# Timer Loader: Ondo iritsi naiz timer-era.\n");

    int tick2 = 0;
    long frek = *freq;
    pthread_mutex_lock(&mutex);
    while (1)
    {
        done++;
        if (tick2 == frek)
        {
            sem_post(&sem_load);
            tick2 = 0;
        }
        else
        {
            tick2++;
            printf("->   tick2: %d\n", tick2);
        }
        pthread_cond_signal(&cond1);
        pthread_cond_wait(&cond2, &mutex);
    }
}