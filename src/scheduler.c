#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"
#include "queue.h"

// long size = sizeof(struct PCB);

void *scheduler()
{
    /* Gure Ilara sortu eta hasieratzen dugu */
    struct Queue queue;
    initQueue(&queue);

    while (1)
    {
        sem_wait(&sem_sc);
        if (quantum == 0)
            continue;
        if (isEmpty(&queue) == 1)
        {
            printf("Ilara hutsik dago\n");
            continue;
        }
    }
}