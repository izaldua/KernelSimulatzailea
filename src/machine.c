#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"
#include "machine.h"

void initMachine(struct MACHINE *machine)
{
    initCPU(&machine->cpu);
}

void initCPU(struct CPU *cpu)
{

}

void initCORE(struct CORE *core)
{

}

void initTHREAD(struct THREAD *thread, int tid)
{
    thread->tid = tid;
    
}