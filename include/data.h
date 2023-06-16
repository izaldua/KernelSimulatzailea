#ifndef DATA_H
#define DATA_H

struct MM{
    int pgb;
    unsigned char* code;
    unsigned char* data;
};

struct PCB
{
    long int pid;
    int quantum;
    int status; // 0 = done, 1 = not done
    struct PCB *next;
};

struct MACHINE
{
    int MACHINE_id;
    struct CPU *cpu;
};

struct CPU
{
    int CPU_id;
    struct CORE *core;
    struct CPU *next;
};

struct CORE
{
    int CORE_id;
    struct THREAD *thread;
    struct CORE *next;
};

struct THREAD /* Hau agian aldatu egin behar da */
{
    int tid;
    int state; // 0 = ready, 1 = running, 2 = blocked
    struct PCB *pcb;
    int IR;
    struct THREAD *next;
};

#endif /* DATA_H */