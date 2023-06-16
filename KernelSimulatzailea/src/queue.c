#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"
#include "queue.h"

void initQueue(struct Queue *queue)
{
    queue->first = NULL;
    queue->last = NULL;
    queue->n = 0;
}

int isEmpty(struct Queue *queue)
{
    return queue->first == NULL;
}

void enqueue(struct Queue *queue, struct PCB *newPCB)
{
    newPCB->next = NULL;
    if (isEmpty(queue))
    {
        queue->first = newPCB;
        queue->last = newPCB;
    }
    else
    {
        queue->last->next = newPCB;
        queue->last = newPCB;
    }
    queue->n++;
}

struct PCB *dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Ilara hutsik dago\n");
        return NULL;
    }
    else
    {
        struct PCB *lag = queue->first;
        queue->first = queue->first->next;
        lag->next = NULL;
        if (queue->first == NULL)
            queue->last = NULL;
        queue->n--;
        return lag;
    }
}

struct PCB *peek(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Ilara hutsik dago\n");
        return NULL;
    }

    return queue->first;
}

void displayQueue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Ilara hutsik dagon");
        return;
    }

    struct PCB *current = queue->first;
    printf("Ilarako elementuak:\n");
    while (current != NULL)
    {
        printf("PID: %ld, TTL: %d, Quantum: %d\n", current->pid, current->TTL, current->quantum);
        current = current->next;
    }
}