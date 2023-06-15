#include <stdio.h>
#include <pthread.h>
#include "config.h"

void *scheduler()
{
    while (1)
    {
        sem_wait(&sem_sc);

        printf("# Scheduler: Deia ondo egin zait.\n");
    }
}