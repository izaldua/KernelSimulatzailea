#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"
#include "queue.h"

// long size = sizeof(struct PCB);
int ttl;

void *scheduler()
{
    /* Gure Ilara sortu eta hasieratzen dugu */
    struct Queue queue;
    initQueue(&queue);

    while (1)
    {
        sem_wait(&sem_sc);
        ttl = 0;
        while (ttl < quantum)
        {
            printf("# Scheduler: Deia ondo egin zait.\n");
            if (isEmpty(&queue) == 1)
            {
                printf("Ilara hutsik dago\n");
                continue;
            }
            else
            {
                // Hemen egin behar duen lana egin dezala
            }
            ttl++;
        }
        nextCommand(&queue);
    }
}