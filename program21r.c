#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>

int main()
{
    char *fifoPath = "myfifo1";
    char message[BUFSIZ];

    // Create the FIFO if it doesn't exist
    mkfifo(fifoPath, 0666);

    // Open the FIFO for reading
    int fd = open(fifoPath, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        // Read message from the FIFO
        read(fd, message, sizeof(message));

        // Print the received message
        printf("Received message: %s\n", message);

        // If the received message is 'exit', break the loop and close the FIFO
        if (strcmp(message, "exit") == 0)
            break;
    }

    close(fd);
    return 0;
}

