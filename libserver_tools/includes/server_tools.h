#ifndef SERVER_TOOLS_HPP
# define SERVER_TOOLS_HPP

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

#define BACKLOGS_QUEUE 10

typedef int 					T_SOCKET;
typedef struct sockaddr_in		T_SOCKADDR_IN;
typedef struct sockaddr			T_SOCKADDR;
typedef struct protoent			T_PROTOENT;
typedef struct sockaddr_storage T_SOCKADDR_STO;
typedef struct addrinfo			T_ADDRINFO;

typedef struct	s_client
{
	T_SOCKADDR_STO	addr;
	T_SOCKET			sock;
}				t_client;

typedef struct	s_server
{
	T_SOCKET		sock_listen;
	t_client		client;
	T_ADDRINFO		hints;
	const char		*port;
}				t_server;

int		create_server(t_server *server);
void	display_socket_addr(T_SOCKADDR_STO *socket_addr);
int		new_connection(t_server* server);


// int delete_socket();
// void set_sock_options();


#endif