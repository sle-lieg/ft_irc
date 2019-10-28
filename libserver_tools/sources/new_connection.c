/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:56:43 by avalanche         #+#    #+#             */
/*   Updated: 2019/10/28 23:18:52 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_tools.h"
#include <stdio.h>
#include <stdlib.h>

int new_connection(t_server* server)
{
	T_SOCKADDR_STO	client_addr;
	socklen_t		addr_size;

	// accept incomming connection (after a check ?)
	addr_size = sizeof(struct sockaddr_storage);
	if ((server->client.sock = accept(server->sock_listen, \
		(struct sockaddr*)&client_addr, &addr_size) == -1))
	{
		printf("Error file %s line %d: accept failed\n", \
			__FILE__, __LINE__);
		exit(EXIT_FAILURE);
	}
	display_socket_addr(&client_addr);
	return (1);
}