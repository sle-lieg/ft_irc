/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:37:23 by avalanche         #+#    #+#             */
/*   Updated: 2020/04/18 17:30:33 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"
#include "ft_printf.h"

void run_server(t_server *server)
{
	fd_set rset;

	while (1)
	{
		rset = server->fdset[READSET];
		if ((select(server->fd_max+1, &rset, NULL, NULL, NULL)) == -1)
		{
			ft_printf("Error: select failed\n");
			exit(EXIT_FAILURE);
		}
		handle_readset(server, &rset);
	}
}

int main(int ac, char **av)
{
	t_server server;

	if (ac < 2)
	{
		ft_printf("usage: ./server <port>\n");
		return (-1);
	}

	ft_memset(&server, 0, sizeof(server));
	create_server(&server, av[1]);
	run_server(&server);
	// delete_server(&server);

	return (0);
}