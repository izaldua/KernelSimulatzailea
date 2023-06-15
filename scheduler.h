#ifndef SCHEDULER_H
#define SCHEDULER_H

struct PCB
{
    long int pid;
    int TTL;
    int quantum;
    struct PCB *next;
};

extern void *scheduler();

#endif /* SCHEDULER_H */