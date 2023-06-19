#ifndef MACHINE_H
#define MACHINE_H

void initMachine(struct MACHINE *machine);
void initCPU(struct CPU *cpu);
void initCore(struct CORE *core);
void initThread(struct THREAD *thread);
void initPCB(struct PCB *pcb, struct MM *mm);
void runInstruction(struct instruction *inst);

#endif /* MACHINE_H */