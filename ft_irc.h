#ifndef FT_IRC_HPP
# define FT_IRC_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include "server_tools.h"

// #define INVALID_SOCKET -1
// #define SOCKET_ERROR -1
// #define MAX_QUEUE_SIZE 5

void handle_request(t_server *server);

#endif
