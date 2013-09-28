#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#pragma once

#define RECEIVE_BUFFER_SIZE 512      /* The receive buffer size */
#define SEND_BUFFER_SIZE 512      /* The send buffer size */
#define MAXPENDING 5

char *get_request(int sock);
int is_valid(char *message);
void die_with_error(char *errorMessage);          /* Error handler */
int setup_server_socket(unsigned short port);  /* Create TCP server socket */
int accept_connection(int servSock);          /* Accept TCP connection request */

struct thread_args {
    int clientSock;
};