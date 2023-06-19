#ifndef CONFIG_H
#define CONFIG_H

#include <pthread.h>
#include <semaphore.h>

#define TENP_KOP 2
#define LD 0
#define ST 1
#define ADD 2
#define EXIT 3

extern pthread_mutex_t mutex; /**/
extern pthread_cond_t cond1, cond2; /**/

extern sem_t sem_sc; /**/
extern sem_t sem_load; /**/

extern int done; /**/
extern int sartu; /**/
extern int quantum; /**/
extern long freq1; /**/
extern long freq2; /**/

extern int stopReading; // 0 = .elf irakurtzen jarraitu, 1 = .elf bukatu da

extern unsigned char* memory;

#endif /* CONFIG_H */