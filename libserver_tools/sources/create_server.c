/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:45:26 by avalanche         #+#    #+#             */
/*   Updated: 2019/10/27 23:06:57 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_tools.h"
#include <stdlib.h>
#include "ft_printf.h"

static int create_server_socket(t_server *server, T_ADDRINFO *info)
{
	int status;

	if ((server->sock_listen = socket(info->ai_family, info->ai_socktype, \
		info->ai_protocol)) == -1)
		return (-1);
	if ((status = bind(server->sock_listen, info->ai_addr, info->ai_addrlen)))
	{
		close(server->sock_listen);
		return (status);
	}
	if ((status = listen(server->sock_listen, BACKLOGS_QUEUE)))
	{
		close(server->sock_listen);
		return (status);
	}
	return (0);
}

int create_server(t_server *server)
{
	T_ADDRINFO	*res;
	T_ADDRINFO	*tmp;
	int			status;

	if ((status = getaddrinfo(NULL, server->port, &server->hints, &res)))
	{
		ft_printf("Error file %s line %d: %s\n", \
			__FILE__, __LINE__, gai_strerror(status));
		exit(EXIT_FAILURE);
	}
	tmp = res;
	while (tmp)
	{
		if (!create_server_socket(server, tmp))
			break;
		tmp = tmp->ai_next;
	}
	freeaddrinfo(res);
	if (tmp == NULL)
	{
		ft_printf("Error file %s line %d: Socket creation failed\n", \
			__FILE__, __LINE__);
		exit(EXIT_FAILURE);
	}
	return (0);
}