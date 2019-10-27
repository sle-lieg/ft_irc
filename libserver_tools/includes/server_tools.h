#ifndef SERVER_TOOLS_HPP
# define SERVER_TOOLS_HPP

#include <sys/socket.h>
#include <netdb.h>

#define BACKLOGS_QUEUE 10

typedef int 				SOCKET;
typedef struct sockaddr_in	T_SOCKADDR_IN;
typedef struct sockaddr		T_SOCKADDR;
typedef struct protoent		T_PROTOENT;
typedef struct sockaddr_storage T_SOCKADDR_STO;
typedef struct addrinfo		T_ADDRINFO;

typedef struct	s_server
{
	SOCKET			sock_listen;
	SOCKET			sock_client;
	T_ADDRINFO		hints;
	const char		*port;
}				t_server;

int		create_server(t_server *server);

// int delete_socket();
// void set_sock_options();


#endif