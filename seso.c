#include <stdio.h>
#include <pthread.h>

#include "config.h"
#include "clock.h"
#include "timer.h"
#include "scheduler.h"

int done;
int sartu;

pthread_mutex_t mutex;
pthread_cond_t cond1, cond2;

int main(int argc, char *argv[])
{
    printf("=========================\nSistema ondo hasieratu da\n=========================\n\n\n");

    // MUTEX eta bere testuinguru osoa hemen hasieratzen da
    pthread_mutex_init(&mutex, NULL);
    printf("Mutexa ondo hasieratu da\n");
    pthread_cond_init(&cond1, NULL);
    printf("Lehen baldintza ondo hasieratu da\n");
    pthread_cond_init(&cond2, NULL);
    printf("Bigarren baldintza ondo hasieratu da\n");

    // HARIEN testuinguru osoa hemen hasieratzen da
    pthread_t erl, tim_sc, tim2, sched;

    if (pthread_create(&erl, NULL, (void *)erlojua, NULL) != 0) // Hariak sortzeko momentuan existitzen badira dagoeneko, honek "errorea" bueltatuko du
        perror("Failed to create threads");
    if (pthread_create(&tim_sc, NULL, (void *)timer_scheduler, NULL) != 0)
        perror("Failed to create threads");
    if (pthread_create(&tim2, NULL, &timer2, NULL) != 0)
        perror("Failed to create threads");
    if (pthread_create(&sched, NULL, (void *)scheduler, NULL) != 0)
        perror("Failed to create threads");

    printf("\n\n");

    // HARIEN testuinguru osoa hemen joineatzen da dena ondo amaitzeko
    if (pthread_join(erl, NULL) != 0)
        perror("Failed to join threads");
    if (pthread_join(tim_sc, NULL) != 0)
        perror("Failed to join threads");
    if (pthread_join(tim2, NULL) != 0)
        perror("Failed to join threads");
    if (pthread_join(sched, NULL) != 0)
        perror("Failed to join threads");

    printf("\n\n");

    // MUTEX-aren testuinguru osoa hemen amaitzen da dena suntsituz
    pthread_mutex_destroy(&mutex);
    printf("Mutexa ondo amaitu da\n");
    pthread_cond_destroy(&cond1);
    printf("Lehen baldintza ondo amaitu da\n");
    pthread_cond_destroy(&cond2);
    printf("Bigarren baldintza ondo amaitu da\n");

    return 0;
}
