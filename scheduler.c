#include <stdio.h>
#include <pthread.h>
#include "config.h"

struct PCB *root = NULL;

void *scheduler()
{
    while (1)
    {
        sem_wait(&sem_sc);
        printf("# Scheduler: Deia ondo egin zait.\n");
    }
}