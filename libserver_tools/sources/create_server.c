/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:45:26 by avalanche         #+#    #+#             */
/*   Updated: 2019/10/29 23:42:03 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_tools.h"
#include <stdlib.h>
#include "ft_printf.h"

static int activate_socket(int sock, t_addrinfo *infos)
{
	int status;

	if ((status = bind(sock, infos->ai_addr, infos->ai_addrlen)) != -1)
	{
		if ((status = listen(sock, BACKLOGS_QUEUE)) != -1)
			return (status);
		ft_printf("listen() call failed\n");
	}
	else
		ft_printf("bind() call failed\n");
	return (status);
}

static int create_socket(t_addrinfo *list_addr)
{
	int sock;

	while (list_addr)
	{
		if ((sock = socket(list_addr->ai_family, list_addr->ai_socktype, \
			list_addr->ai_protocol)) != -1)
		{
			if (activate_socket(sock, list_addr) != -1)
				return (sock);
			close(sock);
		}
		else
			ft_printf("socket() call failed\n");
		list_addr = list_addr->ai_next;
	}
	return (-1);
}

int create_server(t_server *server)
{
	t_addrinfo	*res;
	int			status;

	if ((status = getaddrinfo(NULL, server->port, &server->hints, &res)))
	{
		ft_printf("Error file %s line %d: %s\n", \
			__FILE__, __LINE__, gai_strerror(status));
		exit(EXIT_FAILURE);
	}
	if ((server->sock_listen = create_socket(res)) == -1)
	{
		ft_printf("Error file %s line %d: create_socket failed\n", \
			__FILE__, __LINE__);
		exit(EXIT_FAILURE);
	}
	freeaddrinfo(res);

	return (0);
}
