/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:56:43 by avalanche         #+#    #+#             */
/*   Updated: 2019/11/03 22:49:13 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_tools.h"
#include "ft_printf.h"
#include <stdlib.h>

/*
	- add listener to readset
	- MAX_SOCK + 1 = listener
	do
		- select
		- if FD_SET listener // new_connection
			- new_sock = accept
			- add new_sock to readset
			- MAX_SOCK = new_sock + 1 > MAX_SOCK ? new_sock + 1 : MAX_SOCK
		- for i = listener + 1 && i < MAX_SOCK // handle_request
			- if FD_SET i
				- recv


	while true
*/

int new_connection(t_server* server)
{
	socklen_t	addr_size;
	t_socket	new_socket;

	addr_size = sizeof(t_sockaddr_storage);
	if ((new_socket = accept(server->sock_listen, \
		(t_sockaddr*)&(server->client.addr), &addr_size)) == -1)
	{
		ft_printf("Error file %s line %d: accept failed\n", \
			__FILE__, __LINE__);
		exit(EXIT_FAILURE);
	}

	ft_printf("new client socket: %d \n", new_socket);
	FD_SET(new_socket, &server->readset);
	server->fd_max = (new_socket > server->fd_max ? new_socket : server->fd_max);
	// add_new_client(server, new_socket);
	// display_socket_addr(&server->client.addr);

	return (1);
}

// int new_connection(t_server* server)
// {
// 	socklen_t	addr_size;

// 	addr_size = sizeof(t_sockaddr_storage);
// 	if ((server->client.sock = accept(server->sock_listen, \
// 		(t_sockaddr*)&(server->client.addr), &addr_size)) == -1)
// 	{
// 		ft_printf("Error file %s line %d: accept failed\n", \
// 			__FILE__, __LINE__);
// 		exit(EXIT_FAILURE);
// 	}

// 	display_socket_addr(&server->client.addr);

// 	return (1);
// }
