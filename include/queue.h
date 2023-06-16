#ifndef QUEUE_H
#define QUEUE_H

struct Queue
{
    struct PCB *first;
    struct PCB *last;
    int n;
};

void initQueue(struct Queue *queue);
int isEmpty(struct Queue *queue);
void enqueue(struct Queue *queue, struct PCB *newPCB);
struct PCB *dequeue(struct Queue *queue);
struct PCB *peek(struct Queue *queue);

#endif /* QUEUE_H */