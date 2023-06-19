#ifndef PM_H
#define PM_H

#define memsize 1 << 24

unsigned char* initMemory();
int enoughSpace(int size);
void storeData(int address, int data);
int loadData(int address);
void exitProg();
void exitMachine();

#endif /* PM_H */
