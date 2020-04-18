/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_request.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:43:53 by avalanche         #+#    #+#             */
/*   Updated: 2020/04/18 18:13:03 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"
#include "ft_printf.h"

// void parse_msg()
// {

// }

void handle_request(t_server *server, t_socket socket_client)
{
	int		ret;
	char	buf[MSGLEN];

	ret = recv(socket_client, buf, MSGLEN, 0);

	if (ret)
	{
		ft_printf("Message from socket %d:\n	", socket_client);
		write(STDOUT_FILENO, &buf, ret);
		ft_printf("\nret=%d\n", ret);
		// parse_msg();
	}
	else
	{
		if (ret == -1)
			ft_printf("Error during recv.\n");
		else if (ret == 0)
		{
			ft_printf("Connection to socket %d closed\n", socket_client);
			free_t_client(server, socket_client);
		}
		close(socket_client);
		FD_CLR(socket_client, &server->fdset[READSET]);
	}
}