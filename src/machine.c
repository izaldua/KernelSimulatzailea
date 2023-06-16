#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"
#include "data.h"

void initMachine(struct MACHINE *machine, struct CPU *cpu)
{
    machine->MACHINE_id = NULL;
    machine->CPU = cpu;
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
    core->state = NULL;
}

void initTHREAD(struct THREAD *thread)
{
    thread->tid = NULL;
    thread->next = NULL;
}