/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:56:43 by avalanche         #+#    #+#             */
/*   Updated: 2019/10/29 23:52:00 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_tools.h"
#include "ft_printf.h"
#include <stdlib.h>

int new_connection(t_server* server)
{
	socklen_t		addr_size;

	// accept incomming connection (after a check ?)
	addr_size = sizeof(struct sockaddr_storage);
	if ((server->client.sock = accept(server->sock_listen, \
		(struct sockaddr*)&server->client.addr, &addr_size)) == -1)
	{
		ft_printf("Error file %s line %d: accept failed\n", \
			__FILE__, __LINE__);
		exit(EXIT_FAILURE);
	}
	ft_printf("New connection from %s on port ??TODO??\n", get_ntoa_addr(&server->client.addr));
	// display_socket_addr(&client_addr);
	return (1);
}