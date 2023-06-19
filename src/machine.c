#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"
#include "data.h"
#include "pm.h"

void initMachine(struct MACHINE *machine, struct CPU *cpu)
{
    machine->MACHINE_id = NULL;
    machine->cpu = cpu;
}

void initCPU(struct CPU *cpu, struct CORE *core)
{
    cpu->CPU_id = NULL;
    cpu->core = core;
    cpu->next = NULL;
}

void initCORE(struct CORE *core, struct THREAD *thread)
{
    core->CORE_id = NULL;
    core->thread = thread;
    core->next = NULL;
}

void initTHREAD(struct THREAD *thread)
{
    thread->tid = NULL;
    thread->state = 0;
    thread->pcb = NULL;
    thread->IR = NULL;
    thread->next = NULL;
}

void initPCB(struct PCB *pcb, struct MM *mm)
{
    pcb->pid = NULL;
    pcb->mm = mm;
    pcb->quantum = quantum;
    pcb->status = 1;
    pcb->ptbr = NULL;
    pcb->pc = NULL;
    pcb->next = NULL;
}

void runInstruction(struct instruction *inst)
{
    int OP = inst->op;
    int R1;
    int R2;
    int R3;
    int ADDR;
    switch (OP)
    {
    case LD:
        R1 = inst->r1;
        ADDR = inst->addr;
        R1 = loadData(ADDR); // Hay que gestionar los registros
        break;
    case ST:
        R2 = inst->r2;
        ADDR = inst->addr;
        storeData(ADDR, R2);
        break;
    case ADD:
        R1 = inst->r1;
        R2 = inst->r2;
        R3 = inst->r3;
        R1 = R2 + R3; // Hay que gestionar los registros
        break;
    case EXIT:
        exitProg();
        break;
    }
}