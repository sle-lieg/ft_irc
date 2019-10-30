/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:37:23 by avalanche         #+#    #+#             */
/*   Updated: 2019/10/30 22:45:07 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_irc.h"
#include "server_tools.h"
#include "ft_printf.h"
// #include "libft.h"

// TODO check with wrong port value: "12fg4", "aaa", "", ""
void init_server_addr(t_server *server, const char *port)
{
	ft_memset(server, 0, sizeof(t_server));
	server->hints.ai_socktype = SOCK_STREAM;
	server->hints.ai_family = AF_INET;
	server->hints.ai_flags = AI_PASSIVE;
	server->port = port;
}

void run_server(t_server *server)
{
	while (1)
	{
		if (new_connection(server))
			handle_request(server);
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

	init_server_addr(&server, av[1]);

	create_server(&server);
	run_server(&server);
	// delete_server(&server);

	return (0);
}