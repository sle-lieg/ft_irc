#include "../../ft_irc.h"
#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "get_next_line.h"


int main(int ac, char **av)
{
	int sock;
	int err;
	t_addrinfo hints, *res;
	// struct sockaddr_in host_addr;

	(void)ac;
	(void)av;

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(NULL, "1234", &hints, &res);
	if ((sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1)
	{
		ft_printf("Error: socket() failed\n");
		exit(EXIT_FAILURE);
	}

	t_addrinfo *cli_infos;

	getaddrinfo(NULL, "12345", &hints, &cli_infos);
	// t_sockaddr cli_addr;

	// cli_addr.sin_family = AF_INET;
	// cli_addr.sin_addr.s_addr = INADDR_ANY;
	// cli_addr.sin_port = htons(12345);

	bind(sock, cli_infos->ai_addr, cli_infos->ai_addrlen);

	if ((err = connect(sock, res->ai_addr, res->ai_addrlen)) == -1)
	{
		ft_printf("Error: connect() failed\n");
		close(sock);
		exit(EXIT_FAILURE);
	}

	char *line;
	int byte_sent;

	while (ft_get_next_line(STDIN_FILENO, &line))
	{
		byte_sent = send(sock, line, ft_strlen(line), 0);
		ft_printf("%d/%d bytes sent\n", byte_sent, ft_strlen(line));
	}

	return (0);
}