#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"
#include "machine.h"

void *loader()
{
    struct MACHINE machine;
    initMachine(&machine);
    
    while (1)
    {
        sem_wait(&sem_load);
        printf("# Loader: Deia ondo egin zait.\n");
    }
}