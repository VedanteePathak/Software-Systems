#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

void *handle_client(void *client_socket_ptr) {
    int client_socket = *((int *)client_socket_ptr);
    char buffer[1024];
    // Receive data from client
    read(client_socket, buffer, sizeof(buffer));
    printf("Client: %s\n", buffer);

    // Send response to client
    const char *response = "Hello, Client! I received your message.";
    write(client_socket, response, strlen(response));

    // Close client socket
    close(client_socket);
    pthread_exit(NULL);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
    pthread_t thread_id;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080); // Port number
    server_address.sin_addr.s_addr = INADDR_ANY; // Accept connections from any address

    // Bind the socket to the specified IP and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port 8080...\n");

    // Accept and handle incoming connections using threads
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket == -1) {
            perror("Accepting failed");
            exit(EXIT_FAILURE);
        }

        // Create a thread to handle client request
        if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket) != 0) {
            perror("Thread creation failed");
            close(client_socket);
        }
    }

    // Close server socket (unreachable in this example)
    close(server_socket);

    return 0;
}

