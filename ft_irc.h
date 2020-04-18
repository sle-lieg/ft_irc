#ifndef FT_IRC_HPP
# define FT_IRC_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include "socket_tools.h"

#define NICKLEN 10
#define HOSTLEN 63
#define MSGLEN 15

#define CLIENTS_PER_POOL 20
#define CLIENTS_PER_POOL 20

typedef enum	e_fdset {
	READSET,
	WRITESET,
	ERRORSET
}				t_fdset;

typedef struct	s_message
{
	char *prefix;
	char *command;
	char *params;
}				t_message;

typedef struct	s_client_identity
{
	char *nickname;
	char *username;
	char *hostname;
	char *domainname;
	char *ip;
}				t_client_identity;

typedef struct	s_client
{
	// t_sockaddr_storage	addr;
	// t_addrinfo			addinf;
	// t_socket			sock;
	t_net_infos			*infos;
	char				nickname[NICKLEN];
}				t_client;

// typedef struct	s_clients_pool
// {
// 	t_client		*pool[CLIENTS_PER_POOL];
// 	// t_clients_pool	*next; // implement later when big server is needed
// }				t_clients_pool;

typedef struct s_servers_connected
{
	t_net_infos					*server;
	struct s_servers_connected	*next;
};

typedef struct	s_server
{
	t_net_infos		*net_infos;
	fd_set			fdset[3];
	t_client		*client_pool[CLIENTS_PER_POOL];
	t_socket		socket; // listening socket for new connections
	int				fd_max;
}				t_server;

int		create_server(t_server* server, char* port);
void	handle_request(t_server *server, t_socket client);

// TODO
// char *get_client_name();
// char *get_client_ip();
// char *get_client_protocol();

#endif
