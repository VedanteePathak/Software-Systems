#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    char *fifoPath = "myfifo1";
    char message[BUFSIZ];

    // Open the FIFO for writing
    int fd = open(fifoPath, O_WRONLY);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        // Read user input for the message to send
        printf("Enter message to send (or type 'exit' to quit): ");
        fgets(message, sizeof(message), stdin);

        // Remove newline character from the message
        strtok(message, "\n");

        // Write the message to the FIFO
        write(fd, message, strlen(message) + 1);

        // If the user types 'exit', break the loop and close the FIFO
        if (strcmp(message, "exit") == 0)
            break;
    }

    close(fd);
    return 0;
}

