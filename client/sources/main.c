#include "../../ft_irc.h"
#include <string.h>

int main(int ac, char **av)
{
	int sock;
	struct addrinfo hints, *res;
	struct sockaddr_in host_addr;

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(NULL, "1234", &hints, &res);
	sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

	connect(sock, res->ai_addr, res->ai_addrlen);

	return (0);
}