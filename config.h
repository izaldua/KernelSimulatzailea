#ifndef CONFIG_H
#define CONFIG_H

#include <pthread.h>

#define TENP_KOP 2

extern pthread_mutex_t mutex; /**/
extern pthread_cond_t cond1, cond2; /**/

extern int done; /**/
extern int sartu; /**/

#endif /* CONFIG_H */