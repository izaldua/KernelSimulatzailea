#ifndef LOADER_H
#define LOADER_H

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
    struct CPU *cpu;
};

struct THREAD /* Hau agian aldatu egin behar da */
{
    int tid;
    int PC;
    int *registers;
    int *memory;
    struct THREAD *next;
};

extern void *loader();

#endif /* LOADER_H */