#ifndef MACHINE_H
#define MACHINE_H

struct MACHINE
{
    int MACHINE_id;
    struct CPU *cpu;
};

struct CPU
{
    int CPU_id;
    int PC;
    int IR;
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
    int *registers;
    int *memory;
    struct THREAD *next;
};

void initMachine(struct MACHINE *machine);

#endif /* MACHINE_H */