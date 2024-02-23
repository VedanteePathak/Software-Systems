#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include<string.h>

int main() {
    char *fifoPath = "myfifo2";
    char buffer[BUFSIZ];
    fd_set fds;
    struct timeval timeout;
    int fd, ready;

    // Create the FIFO if it doesn't exist
    mkfifo(fifoPath, 0666);

    // Open the FIFO for reading
    fd = open(fifoPath, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    FD_ZERO(&fds);
    FD_SET(fd, &fds);

    // Set the timeout to 10 seconds
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    // Wait for data to be written into the FIFO or timeout
    printf("Waiting for data in FIFO...\n");
    ready = select(fd + 1, &fds, NULL, NULL, &timeout);

    if (ready == -1) {
        perror("select");
        exit(EXIT_FAILURE);
    } else if (ready == 0) {
        printf("Timeout: No data received within 10 seconds.\n");
    } else {
        // Data is available to be read
        read(fd, buffer, sizeof(buffer));
        printf("Received data from FIFO: %s\n", buffer);
    }

    close(fd);
    return 0;
}

