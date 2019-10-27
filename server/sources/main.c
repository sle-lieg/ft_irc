/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:37:23 by avalanche         #+#    #+#             */
/*   Updated: 2019/10/27 22:58:13 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_irc.h"
#include "server_tools.h"
#include "ft_printf.h"
// #include "libft.h"

// TODO check with wrong port value: "12fg4", "aaa", "", ""
void init_server_addr(t_server *server, const char *port)
{
	ft_memset(server, 0, sizeof(t_server));
	server->hints.ai_socktype = SOCK_STREAM;
	server->hints.ai_family = AF_UNSPEC;
	server->hints.ai_flags = AI_PASSIVE;
	server->port = port;
}

void run_server(t_server *server)
{
	T_SOCKADDR_STO	client_addr;
	socklen_t		addr_size;
	// accept incomming connection (after a check ?)
	addr_size = sizeof(struct sockaddr_storage);
	if ((server->sock_client = accept(server->sock_listen, \
		(struct sockaddr*)&client_addr, &addr_size) == -1))
	{
		perror("");
		ft_printf("Error file %s line %d: accept failed\n", \
			__FILE__, __LINE__);
		exit(EXIT_FAILURE);
	}

	char ipstr[INET6_ADDRSTRLEN];
	if (client_addr.ss_family == AF_INET)
	{
		struct sockaddr_in *addr = (struct sockaddr_in *)&client_addr;
		printf("connection from %s on port %d\n", \
		inet_ntop(addr->sin_family, &(addr->sin_addr.s_addr), ipstr, INET6_ADDRSTRLEN), \
		addr->sin_port);
	} else {
		struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *)&client_addr;
		printf("connection from %s on port %d\n", \
		inet_ntop(addr6->sin6_family, &(addr6->sin6_addr.__u6_addr), ipstr, INET6_ADDRSTRLEN), \
		addr6->sin6_port);
	}

}

int main(int ac, char **av)
{
	t_server server;

	if (ac < 2)
	{
		ft_printf("usage: ./server <port>\n");
		return (-1);
	}

	init_server_addr(&server, av[1]);

	create_server(&server);
	run_server(&server);
	// delete_server(&server);



	// // accept incomming connection (after a check ?)
	// addr_size = sizeof(struct sockaddr_storage);
	// if ((client_soc = accept(host_soc, (struct sockaddr*)&client_addr, &addr_size) == -1))
	// {
	// 	perror("accept failed");
	// 	freeaddrinfo(res);
	// 	return (-1);
	// }

	// char ipstr[INET6_ADDRSTRLEN];
	// if (client_addr.ss_family == AF_INET)
	// {
	// 	struct sockaddr_in *addr = (struct sockaddr_in *)&client_addr;
	// 	printf("connection from %s on port %d\n", \
	// 	inet_ntop(addr->sin_family, &(addr->sin_addr.s_addr), ipstr, INET6_ADDRSTRLEN), \
	// 	addr->sin_port);
	// } else {
	// 	struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *)&client_addr;
	// 	printf("connection from %s on port %d\n", \
	// 	inet_ntop(addr6->sin6_family, &(addr6->sin6_addr.__u6_addr), ipstr, INET6_ADDRSTRLEN), \
	// 	addr6->sin6_port);
	// }

	return (0);
}