#include "../../ft_irc.h"
#include "socket_tools.h"
#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "get_next_line.h"

static void get_nickname(char *nickname)
{
	ft_printf("Enter your user name: ");
	read(STDIN_FILENO, nickname, NICKLEN);
	nickname[NICKLEN - 1] = '\0';
}

static void init_client(t_client *client)
{
	memset(client, 0, sizeof(t_client));
	client->addinf.ai_family = AF_INET;
	client->addinf.ai_socktype = SOCK_STREAM;
	client->addinf.ai_flags = AI_PASSIVE;
	get_nickname(client->nickname);
	gethostname(client->hostname, HOSTLEN);
	ft_printf("welcome %s\n", client->nickname);
}

static void create_client(t_client *client)
{
	t_addrinfo	*res;
	int			status;

	if ((status = (getaddrinfo(NULL, "12345", &client->addinf, &res))))
	{
		ft_printf("Error file %s line %d: %s\n", \
			__FILE__, __LINE__, gai_strerror(status));
		exit(EXIT_FAILURE);
	}
	if ((client->sock = create_socket(res, &client->addinf)) == -1)
	{
		ft_printf("Error file %s line %d: create_socket failed\n", \
			__FILE__, __LINE__);
		exit(EXIT_FAILURE);
	}
	freeaddrinfo(res);

}

/*
	Connect and immediately send the metadata of the client
	(for now only nickname)
	DATA to send: nickname, hostname, username
*/
static void connect_client(t_client *client)
{
	int error;

	if ((error = connect(client->sock, client->addinf.ai_addr, \
						client->addinf.ai_addrlen)) == -1)
	{
		ft_printf("Error: connect() failed\n");
		close(client->sock);
		exit(EXIT_FAILURE);
	}
	cmd_user(client->sock);
}

int cmd_user(t_socket socket)
{
	char hostname[255];

	gethostname(hostname, 255);
	hostname[254] = '\0';
	ft_printf("+++ %d\n", client->addinf.ai_addr->sa_family);
	ft_printf("%s!%s@%s\n", client->nickname, hostname, get_ntoa_addr((t_sockaddr_storage*)&client->addinf.ai_addr));
	send(client->sock, client->nickname, ft_strlen(client->nickname), 0);
}

void run(t_client *client)
{
	char *line;
	int byte_sent;

	while (ft_get_next_line(STDIN_FILENO, &line))
	{
		byte_sent = send(client->sock, line, ft_strlen(line), 0);
		ft_printf("%d/%d bytes sent\n", byte_sent, ft_strlen(line));
	}
}

int main(int ac, char **av)
{
	t_client client;

	(void)ac;
	(void)av;

	// TODO parse options ?
	// parse_options();

	// if (client.option & IHM)
	// 	startIHM(&client);
	// else
	// {
		init_client(&client);
		create_client(&client);
		connect_client(&client);
		run(&client);
	// }



	return (0);
}