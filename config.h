#ifndef CONFIG_H
#define CONFIG_H

#include <pthread.h>
#include <semaphore.h>

#define TENP_KOP 2

extern pthread_mutex_t mutex; /**/
extern pthread_cond_t cond1, cond2; /**/

extern sem_t sem_sc; /**/
extern sem_t sem_load; /**/

extern int done; /**/
extern int sartu; /**/
extern long freq1; /**/
extern long freq2; /**/

#endif /* CONFIG_H */