#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include "config.h"

sem_t sem_sc;

void *timer_scheduler()
{
    printf("# Timer Scheduler: Ondo iritsi naiz timer-era.\n");

    int tick1 = 0;
    pthread_mutex_lock(&mutex);
    while (1)
    {
        done++;
        if (tick1 == 200)
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

void *timer_loader()
{
    printf("# Timer2: Ondo iritsi naiz timer-era.\n");

    int tick2 = 0;
    pthread_mutex_lock(&mutex);
    while (1)
    {
        done++;
        if (tick2 == 100)
        {
            printf("\nIEPE\n");
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