#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "config.h"
#include "clock.h"
#include "timer.h"
#include "scheduler.h"
#include "loader.h"
#include "data.h"
#include "pm.h"
#include "machine.h"

int done;
int sartu;
int quantum;
long freq1;
long freq2;
int stopReading;

pthread_mutex_t mutex;
pthread_cond_t cond1, cond2;

pthread_t erl, tim_sc, tim2, sched, load;

void signalHandler(int signum)
{
    free(memory);

    if (pthread_cancel(erl) != 0)
        perror("Failed to cancel erl thread");
    if (pthread_cancel(tim_sc) != 0)
        perror("Failed to cancel tim_sc thread");
    if (pthread_cancel(tim2) != 0)
        perror("Failed to cancel tim2 thread");
    if (pthread_cancel(sched) != 0)
        perror("Failed to cancel sched thread");
    if (pthread_cancel(load) != 0)
        perror("Failed to cancel load thread");

    printf("\n\n Amaiera forzatua egin da\n\n");

    exit(signum);
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Argumentuak ez dira ondo pasatu\n\n");
        printf("========================= Argumentuak nola pasa =========================\n\n");
        printf("./seso <scheduler frequency> <loader frequency> <each process quantum>\n\n");
        printf("=========================================================================\n\n");
        return 1;
    }
    else
    {
        long freq1 = strtol(argv[1], NULL, 10);
        long freq2 = strtol(argv[2], NULL, 10);
        int quantum = atoi(argv[3]);
    }

    printf("=========================\nSistema ondo hasieratu da\n=========================\n\n");

    stopReading = 0;

    unsigned char *memory = initMemory();

    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    signal(SIGINT, signalHandler);

    // MUTEX eta bere testuinguru osoa hemen hasieratzen da
    pthread_mutex_init(&mutex, NULL);
    printf("Mutexa ondo hasieratu da\n");
    pthread_cond_init(&cond1, NULL);
    printf("Lehen baldintza ondo hasieratu da\n");
    pthread_cond_init(&cond2, NULL);
    printf("Bigarren baldintza ondo hasieratu da\n");

    // HARIEN testuinguru osoa hemen hasieratzen da

    if (pthread_create(&erl, NULL, (void *)erlojua, NULL) != 0) // Hariak sortzeko momentuan existitzen badira dagoeneko, honek "errorea" bueltatuko du
        perror("Failed to create threads");
    if (pthread_create(&tim_sc, NULL, (void *)timer_scheduler, &freq1) != 0)
        perror("Failed to create threads");
    if (pthread_create(&tim2, NULL, (void *)timer_loader, &freq2) != 0)
        perror("Failed to create threads");
    if (pthread_create(&sched, NULL, (void *)scheduler, NULL) != 0)
        perror("Failed to create threads");
    if (pthread_create(&load, NULL, (void *)loader, NULL) != 0)
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
    if (pthread_join(load, NULL) != 0)
        perror("Failed to join threads");

    printf("\n\n");

    // MUTEX-aren testuinguru osoa hemen amaitzen da dena suntsituz
    pthread_mutex_destroy(&mutex);
    printf("Mutexa ondo amaitu da\n");
    pthread_cond_destroy(&cond1);
    printf("Lehen baldintza ondo amaitu da\n");
    pthread_cond_destroy(&cond2);
    printf("Bigarren baldintza ondo amaitu da\n");

    free(memory);

    return 0;
}