#include "ft_irc.h"

void set_server_infos(t_server *server, t_addrinfo *server_addr)
{
	t_net_infos *ninfos;
	char *ip;

	if (!(ninfos = malloc(sizeof(*ninfos))))
		exit(EXIT_FAILURE);
	ninfos->addinf = server_addr;

	ft_printf("canonname: %s\n", server_addr->ai_canonname);
	ft_strncpy(ninfos->hostname, server_addr->ai_canonname, HOSTNAME_LEN);

	ip = get_ntoa_addr((t_sockaddr_storage*)server_addr->ai_addr);
	ft_printf("server ip: %s\n", ip);
	ft_strncpy(ninfos->ip, ip, INET6_ADDRSTRLEN);

	server->net_infos = ninfos;
}

int create_server(t_server *server, char *port)
{
	t_addrinfo	server_addr;
	t_addrinfo	*res;
	t_socket	socket;
	int			status;

	init_addr_infos(&server_addr, AF_INET, SOCK_STREAM, AI_PASSIVE);
	if ((status = getaddrinfo(NULL, port, &server_addr, &res)))
	{
		ft_printf("Error in create_server: %s\n", gai_strerror(status));
		exit(EXIT_FAILURE);
	}
	if ((socket = create_listening_socket(res, &server_addr)) == -1)
	{
		ft_printf("Error in create_listening_socket\n");
		exit(EXIT_FAILURE);
	}
	freeaddrinfo(res);
	set_server_infos(server, &server_addr);
	FD_ZERO(&server->fdset[READSET]);
	// FD_ZERO(&server->fdset[WRITESET]);
	// FD_ZERO(&server->fdset[ERRSET]);
	FD_SET(socket, &server->fdset[READSET]);
	server->socket = socket;
	server->fd_max = socket;
	return (0);
}