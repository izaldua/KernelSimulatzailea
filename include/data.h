#ifndef DATA_H
#define DATA_H

struct instruction{
    int op; // 0 = ld, 1 = st, 2 = add, 3 = exit
    int r1; // beti
    int r2; // add kasuan
    int r3; // add kasuan
    int addr; // ld eta st kasuan
};

struct MM{
    int pgb;
    unsigned char* code;
    unsigned char* data;
};

struct MMU {
    unsigned char* tlb; // 16 entries Translation Lookaside Buffer
};

struct PCB
{
    long int pid;
    struct MM *mm;
    int quantum;
    int status; // 0 = done, 1 = not done
    int ptbr;
    int pc;
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