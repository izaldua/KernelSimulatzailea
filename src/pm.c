#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"
#include "data.h"
#include "pm.h"

unsigned char *memory;

void initMemory()
{
    memory = (unsigned char *)malloc(memsize);
}