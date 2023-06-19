#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"
#include "data.h"
#include "pm.h"

unsigned char *memory;
int freeMem;

unsigned char* initMemory()
{
    memory = (unsigned char *)malloc(memsize);
    freeMem = memsize;
    return memory;
}

/* 1 == enough space 0 == not enough */
int enoughSpace(int size)
{
    return freeMem >= size;
}

void storeData(int address, int data)
{

    memory[address] = data;
}

int loadData(int address)
{
    return memory[address];
}

void exitProg()
{
    stopReading = 1;
}

void exitMachine()
{
    free(memory);
}
