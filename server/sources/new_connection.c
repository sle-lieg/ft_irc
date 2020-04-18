/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:56:43 by avalanche         #+#    #+#             */
/*   Updated: 2020/04/18 20:15:10 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"
#include "ft_printf.h"
#include <stdlib.h>

int new_connection(t_server* server)
{
	socklen_t			addr_size;
	t_socket			client_socket;
	t_sockaddr_storage	client_addr;

	addr_size = sizeof(t_sockaddr_storage);
	if ((client_socket = accept(server->socket, \
		(t_sockaddr*)&client_addr, &addr_size)) == -1)
		return -1;
	if (add_new_client(server, client_socket, &client_addr))
	{
		// TODO socket not usable anymore, since the POOL is either full
		// or the t_client creation failed.
		close(client_socket);
		return (-1);
	}

	ft_printf("new client socket: %d \n", client_socket);
	FD_SET(client_socket, &server->fdset[READSET]);
	server->fd_max = (client_socket > server->fd_max ? client_socket : server->fd_max);

	return (0);
}

/*
	- create a new t_client
	- associate an index and store it in the pool
	- [socket] -> t_client address
*/
uint8_t	add_new_client(t_server *server, t_socket socket, t_sockaddr_storage *client_addr)
{
	t_client	*new_client;

	// TODO find how to make list of POOLS, so if a pool is full, create a new
	// one. Use [socket % CLIENTS_PER_POOL] to manage indexing in each pool.
	assert(socket < CLIENTS_PER_POOL);
	assert(server->client_pool[socket] == NULL);

	// create the new t_client and get its nickname
	if (!(new_client = create_t_client(socket, client_addr)))
	{
		ft_printf("ERROR: create_t_client failed\n");
		return (-1);
	}
	server->client_pool[socket] = new_client;
	
	return (0);
}

t_client *create_t_client(int socket, t_sockaddr_storage *client_addr)
{
	t_client	*new_client;
	char		name[NICKLEN];
	int			ret;

	if (!(new_client = malloc( sizeof(*new_client) )))
		return (NULL);
	new_client->sock = socket;
	new_client->addr = *client_addr;

	ret = recv(socket, name, NICKLEN, 0);
	if (ret)
	{
		ft_printf("nickname received from the client: %s\n", name);
		ft_strncpy(new_client->nickname, name, NICKLEN);
	}

	return (new_client);
}

void	free_t_client(t_server *server, t_socket client)
{
	// TODO use client / CLIENT_PER_POOL to get the index of the right pool
	// and then % for the index
	free(server->client_pool[client]);
	server->client_pool[client] = NULL;
}