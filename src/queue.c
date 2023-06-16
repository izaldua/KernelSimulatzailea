#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"
#include "queue.h"
#include "data.h"

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

void *nextCommand(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Ilara hutsik dago\n");
        return NULL;
    }
    else if (queue->n >= 2)
    {
        int done = queue->first->pid;
        struct PCB *lag = dequeue(queue);
        enqueue(queue, lag);
        while (queue->first->status == 0 && queue->first->pid != done)
        {
            lag = dequeue(queue);
            enqueue(queue, lag);
        }
    }
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
        printf("PID: %ld, Quantum: %d\n, Status: %d", current->pid, current->quantum, current->status);
        current = current->next;
    }
}