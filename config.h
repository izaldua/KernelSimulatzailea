#ifndef CONFIG_H
#define CONFIG_H

#include <pthread.h>
#include <semaphore.h>

#define TENP_KOP 2

extern pthread_mutex_t mutex; /**/
extern pthread_cond_t cond1, cond2; /**/

extern sem_t sem_sc;

extern int done; /**/
extern int sartu; /**/

#endif /* CONFIG_H */