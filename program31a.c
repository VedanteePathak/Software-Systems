#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int main() {
    sem_t binarySemaphore;

    // Initialize a binary semaphore with an initial value of 1
    if (sem_init(&binarySemaphore, 0, 1) == -1) {
        perror("sem_init");
        exit(EXIT_FAILURE);
    }

    printf("Binary Semaphore created and initialized successfully.\n");

    // Perform operations using the binary semaphore

    // Destroy the binary semaphore
    if (sem_destroy(&binarySemaphore) == -1) {
        perror("sem_destroy");
        exit(EXIT_FAILURE);
    }

    printf("Binary Semaphore destroyed.\n");

    return 0;
}

