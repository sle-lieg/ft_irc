#include "ft_irc.h"
#include "ft_printf.h"

void handle_readset(t_server *server, fd_set *set)
{
	int i;

	i = 0;
	while (i < server->fd_max+1)
	{
		if (FD_ISSET(i, set))
		{
			if (i == server->socket)
				new_connection(server);
			else
				handle_request(server, i);
		}
		i++;
	}
}
