#ifndef SERVER_TOOLS_HPP
# define SERVER_TOOLS_HPP

#include <stdlib.h>
#include <stdio.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

#include "libft.h"

#define BACKLOGS_QUEUE 10
#define CLIENTS_PER_POOL 20

typedef int 					t_socket;
typedef struct sockaddr			t_sockaddr;
typedef struct sockaddr_in		t_sockaddr_in;
typedef struct sockaddr_in6		t_sockaddr_in6;
typedef struct sockaddr_storage t_sockaddr_storage;
typedef struct protoent			t_protoent;
typedef struct addrinfo			t_addrinfo;

typedef struct	s_client
{
	t_sockaddr_storage	addr;
	t_socket		sock;
}				t_client;

typedef struct	s_clients_pool
{
	t_client	*pool[CLIENTS_PER_POOL];
}				t_clients_pool;

typedef struct	s_server
{
	fd_set			readset;
	t_socket		sock_listen;
	t_client		client;
	t_addrinfo		hints;
	const char		*port;
	int				fd_max;
}				t_server;

int			create_server(t_server*);
void		display_socket_addr(t_sockaddr_storage*);
int			new_connection(t_server*);
const char	*get_ntoa_addr(t_sockaddr_storage*);
void		*get_in_addr(t_sockaddr_storage*);
uint16_t	get_port(t_sockaddr_storage*);

#endif