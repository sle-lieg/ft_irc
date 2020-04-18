/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ntoa_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:37:13 by avalanche         #+#    #+#             */
/*   Updated: 2020/04/15 23:44:19 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket_tools.h"

/*
	Get the socket internet address ( sin_addr or sin6_addr ) from the
	struct sockaddr_storage and transform it in printable format.
	inet_ntop: inet_network_to_printable
*/
const char *get_ntoa_addr(t_sockaddr_storage *addr)
{
	static char	ip[INET6_ADDRSTRLEN] = {0};
	void		*in_addr;

	ft_memset(ip, 0, INET6_ADDRSTRLEN);
	if ((in_addr = get_in_addr(addr)))
	{
		inet_ntop(addr->ss_family, in_addr, ip, INET6_ADDRSTRLEN);
		return (ip);
	}
	return (NULL);
}