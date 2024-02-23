#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    key_t key;
    int msqid;
    struct msgbuf message;

    // Generate a unique key for the message queue
    key = ftok("/tmp", 'A');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Get the existing message queue
    msqid = msgget(key, 0666);
    if (msqid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Receive the message from the message queue (non-blocking mode with IPC_NOWAIT flag)
    if (msgrcv(msqid, &message, sizeof(message.mtext), 0, IPC_NOWAIT) == -1) {
        if (errno == ENOMSG) {
            printf("No message in the queue.\n");
        } else {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }
    } else {
        printf("Received Message from the Queue: %s\n", message.mtext);
    }

    return 0;
}

