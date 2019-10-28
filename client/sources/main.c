#include "../../ft_irc.h"
#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"

int main(int ac, char **av)
{
	int sock;
	int err;
	struct addrinfo hints, *res;
	struct sockaddr_in host_addr;

	
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(NULL, "1234", &hints, &res);
	if ((sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1)
	{
		ft_printf("Error: socket() failed\n");
		exit(EXIT_FAILURE);
	}

	if ((err = connect(sock, res->ai_addr, res->ai_addrlen)) == -1)
	{
		ft_printf("Error: connect() failed\n");
		close(sock);
		exit(EXIT_FAILURE);
	}

	return (0);
}