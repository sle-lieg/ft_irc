/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_request.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:43:53 by avalanche         #+#    #+#             */
/*   Updated: 2019/11/03 22:44:57 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_tools.h"
#include "ft_printf.h"

#define BUFFSIZE 15

void handle_request(t_server *server, t_socket client)
{
	int		ret;
	// const char	*client_ip;
	char	buf[BUFFSIZE];

	// client_ip = get_ntoa_addr(&server->client.addr);
	ret = recv(client, buf, BUFFSIZE, 0);

	if (ret)
	{
		ft_printf("Message from socket %d:\n	", client);
		write(STDOUT_FILENO, &buf, ret);
		ft_printf("\n");
	}
	else
	{
		if (ret == -1)
			ft_printf("Error during recv.\n");
		else if (ret == 0)
			ft_printf("Connection closed\n");
		close(client);
		FD_CLR(client, &server->readset);
	}
}