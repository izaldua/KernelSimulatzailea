#include <stdio.h>
#include <pthread.h>

#include "config.h"
#include "clock.h"
#include "timer.h"

int done;
int sartu;

pthread_mutex_t mutex;
pthread_cond_t cond1, cond2;

/*void *timer1()
{
    printf("# Timer1: Ondo iritsi naiz timer-era.\n");

    int tick1 = 0;
    pthread_mutex_lock(&mutex);
    while (1)
    {
        done++;
        if (tick1 == 200)
        {
            printf("\nIEPA\n");
            tick1 = 0;
        }
        else
        {
            tick1++;
            printf("->   tick1: %d\n", tick1);
        }
        pthread_cond_signal(&cond1);
        pthread_cond_wait(&cond2, &mutex);
    }
}*/

void *timer2()
{
    printf("# Timer2: Ondo iritsi naiz timer-era.\n");

    int tick2 = 0;
    pthread_mutex_lock(&mutex);
    while (1)
    {
        done++;
        if (tick2 == 100)
        {
            printf("\nIEPE\n");
            tick2 = 0;
        }
        else
        {
            tick2++;
            printf("->   tick2: %d\n", tick2);
        }
        pthread_cond_signal(&cond1);
        pthread_cond_wait(&cond2, &mutex);
    }
}

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
    pthread_t erl, tim, tim2;

    if (pthread_create(&erl, NULL, (void *)erlojua, NULL) != 0) // Hariak sortzeko momentuan existitzen badira dagoeneko, honek "errorea" bueltatuko du
        perror("Failed to create threads");
    if (pthread_create(&tim, NULL, (void *)timer, NULL) != 0)
        perror("Failed to create threads");
    if (pthread_create(&tim2, NULL, &timer2, NULL) != 0)
        perror("Failed to create threads");

    printf("\n\n");

    // HARIEN testuinguru osoa hemen joineatzen da dena ondo amaitzeko
    if (pthread_join(erl, NULL) != 0)
        perror("Failed to join threads");
    else
        printf("Erlojuaren haria ondo amaitu da\n");
    if (pthread_join(tim, NULL) != 0)
        perror("Failed to join threads");
    else
        printf("Timer1-aren haria ondo amaitu da\n");
    if (pthread_join(tim2, NULL) != 0)
        perror("Failed to join threads");
    else
        printf("Timer2-aren haria ondo amaitu da\n");

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
