/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_request.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:43:53 by avalanche         #+#    #+#             */
/*   Updated: 2019/10/30 22:07:30 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_tools.h"
#include "ft_printf.h"

#define BUFFSIZE 15

void handle_request(t_server *server)
{
	int		ret;
	const char	*client_ip;
	char	buf[BUFFSIZE];

	client_ip = get_ntoa_addr(&server->client.addr);
	while ((ret = recv(server->client.sock, buf, BUFFSIZE, 0)))
	{
		if (ret == -1)
		{
			ft_printf("Error during recv.\n");
			close(server->client.sock);
			break;
		}

		ft_printf("Message from %s:\n	", client_ip);
		write(STDOUT_FILENO, &buf, ret);
		ft_printf("\n");
	}
	ft_printf("Connection closed\n");
}