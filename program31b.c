#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int main() {
    sem_t countingSemaphore;

    // Initialize a counting semaphore with an initial value of 3
    if (sem_init(&countingSemaphore, 0, 3) == -1) {
        perror("sem_init");
        exit(EXIT_FAILURE);
    }

    printf("Counting Semaphore created and initialized with a value of 3.\n");

    // Perform operations using the counting semaphore

    // Destroy the counting semaphore
    if (sem_destroy(&countingSemaphore) == -1) {
        perror("sem_destroy");
        exit(EXIT_FAILURE);
    }

    printf("Counting Semaphore destroyed.\n");

    return 0;
}

