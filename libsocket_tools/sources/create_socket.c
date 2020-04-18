/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:45:26 by avalanche         #+#    #+#             */
/*   Updated: 2020/04/15 23:58:36 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket_tools.h"
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

int create_listening_socket(t_addrinfo *list_addr, t_addrinfo *dest_addr)
{
	int sock;

	while (list_addr)
	{
		if ((sock = socket(list_addr->ai_family, list_addr->ai_socktype, \
			list_addr->ai_protocol)) != -1)
		{
			if (activate_socket(sock, list_addr) != -1)
			{
				*dest_addr = *list_addr;
				return (sock);
			}
			close(sock);
		}
		else
			ft_printf("socket() call failed\n");
		list_addr = list_addr->ai_next;
	}
	return (-1);
}

int create_socket(t_addrinfo *list_addr, t_addrinfo *dest_addr)
{
	int sock;

	while (list_addr)
	{
		if ((sock = socket(list_addr->ai_family, list_addr->ai_socktype, \
			list_addr->ai_protocol)) != -1)
		{
			*dest_addr = *list_addr;
			return (sock);
		}
		list_addr = list_addr->ai_next;
	}
	return (-1);
}