#include <stdio.h>
#include <pthread.h>
#include "config.h"

void *loader()
{
    while (1)
    {
        sem_wait(&sem_sc);
        printf("# Loader: Deia ondo egin zait.\n");
    }
}