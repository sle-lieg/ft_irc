/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_socket_addr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 23:05:26 by avalanche         #+#    #+#             */
/*   Updated: 2019/10/29 23:48:56 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_tools.h"
#include <stdio.h>

void display_socket_addr(t_sockaddr_storage *socket_addr)
{
	char ipstr[INET6_ADDRSTRLEN];

	if (socket_addr->ss_family == AF_INET)
	{
		struct sockaddr_in *addr = (struct sockaddr_in *)socket_addr;
		printf("connection from %s on port %d\n", \
		inet_ntop(addr->sin_family, &(addr->sin_addr.s_addr), ipstr, INET6_ADDRSTRLEN), \
		ntohs(addr->sin_port));
	} else {
		struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *)socket_addr;
		printf("connection from %s on port %d\n", \
		inet_ntop(addr6->sin6_family, &(addr6->sin6_addr.__u6_addr), ipstr, INET6_ADDRSTRLEN), \
		ntohs(addr6->sin6_port));
	}
}