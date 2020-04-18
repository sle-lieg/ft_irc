#ifndef SOCKET_TOOLS_HPP
# define SOCKET_TOOLS_HPP

#include <stdlib.h>
#include <stdio.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

#include "libft.h"

#define BACKLOGS_QUEUE 10
#define HOSTNAME_LEN 63
// ERRORS TYPE (use enum ?)
// #define ECREACLIENT 1

// COMMAND

typedef int 					t_socket;
typedef struct sockaddr			t_sockaddr;
typedef struct sockaddr_in		t_sockaddr_in;
typedef struct sockaddr_in6		t_sockaddr_in6;
typedef struct sockaddr_storage t_sockaddr_storage;
typedef struct protoent			t_protoent;
typedef struct addrinfo			t_addrinfo;

typedef struct	s_net_infos
{
	t_addrinfo	*addinf;
	char		ip[INET6_ADDRSTRLEN];
	char		hostname[HOSTNAME_LEN];
}				t_net_infos;

int			create_listening_socket(t_addrinfo *list_addr, t_addrinfo *dest_addr);
int			create_socket(t_addrinfo *list_addr, t_addrinfo *dest_addr);
void		display_socket_addr(t_sockaddr_storage*);
int			new_connection(t_server*);
const char	*get_ntoa_addr(t_sockaddr_storage*);
void		*get_in_addr(t_sockaddr_storage*);
uint16_t	get_port(t_sockaddr_storage*);
void		init_addr_infos(t_addrinfo *addinfo, uint16_t AF, uint16_t socket_type, uint16_t flags);
uint8_t		add_new_client(t_server *server, t_socket socket, t_sockaddr_storage *);
t_client	*create_t_client(int socket, t_sockaddr_storage *);
void		free_t_client(t_server *server, t_socket client);
#endif