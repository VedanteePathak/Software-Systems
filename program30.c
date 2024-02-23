#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    key_t key;
    int shmid;
    char *shm_ptr;

    // Generate a unique key for the shared memory
    key = ftok("/tmp", 'A');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create shared memory segment of size 1024 bytes
    shmid = shmget(key, 1024, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment
    shm_ptr = (char *)shmat(shmid, NULL, 0);
    if (shm_ptr == (char *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Write data to shared memory
    strcpy(shm_ptr, "Hello, Shared Memory!");

    // Attach the shared memory segment in read-only mode
    int read_only_shmid = shmget(key, 1024, O_RDONLY);
    char *read_only_shm_ptr = (char *)shmat(read_only_shmid, NULL, SHM_RDONLY);
    if (read_only_shm_ptr == (char *)-1) {
        perror("shmat (read-only)");
        // Note: Even if attaching in read-only mode fails, the original segment remains writable
    } else {
        printf("Read-Only Shared Memory Contents: %s\n", read_only_shm_ptr);
    }

    // Detach the shared memory segment
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // Remove the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}

