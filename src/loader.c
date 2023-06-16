#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"
#include "data.h"

int ttl;

void *loader()
{
    struct MACHINE machine;
    initMachine(&machine);

    while (1)
    {
        sem_wait(&sem_load);
        ttl = 0;
        while (ttl < quantum)
        {
            printf("# Loader: Deia ondo egin zait.\n");
            ttl++;
        }
    }
}