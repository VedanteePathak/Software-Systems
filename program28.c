#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/msg.h>
#include <errno.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    key_t key;
    int msqid;
    struct msqid_ds msqbuf;

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

    // Get the current permissions and other attributes of the message queue
    if (msgctl(msqid, IPC_STAT, &msqbuf) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    // Change the message queue permissions (for example, to read-only)
    msqbuf.msg_perm.mode = 0444; // Read-only permission (owner, group, others)

    // Update the message queue attributes with the modified permissions
    if (msgctl(msqid, IPC_SET, &msqbuf) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    printf("Message queue permission changed successfully.\n");

    return 0;
}

