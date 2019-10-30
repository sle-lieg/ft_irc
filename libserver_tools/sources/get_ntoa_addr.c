/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ntoa_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:37:13 by avalanche         #+#    #+#             */
/*   Updated: 2019/10/30 22:04:42 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_tools.h"

const char *get_ntoa_addr(struct sockaddr_storage *addr)
{
	static char	ip[INET6_ADDRSTRLEN] = {0};
	void		*in_addr;

	ft_memset(ip, 0, INET6_ADDRSTRLEN);
	if ((in_addr = get_in_addr((struct sockaddr *)addr)))
	{
		inet_ntop(addr->ss_family, in_addr, ip, INET6_ADDRSTRLEN);
		return (ip);
	}
	return (NULL);
}