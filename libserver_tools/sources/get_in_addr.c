/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_in_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:36:09 by avalanche         #+#    #+#             */
/*   Updated: 2019/10/30 23:49:15 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_tools.h"

void *get_in_addr(struct sockaddr *addr)
{
	// // struct sockaddr_in *ip4;

	// if (addr->sa_family == AF_INET)
	// {
	// 	// ip4 = (struct sockaddr_in*)addr;
	// 	return (&(*(struct sockaddr_in*)addr).sin_addr);
	// }
	// else if (addr->sa_family == AF_INET6)
	// 	return (&(*(struct sockaddr_in6*)&addr).sin6_addr);
	// return (NULL);

	if (addr->sa_family == AF_INET)
		return (&((*(struct sockaddr_in*)addr).sin_addr));
	else if (addr->sa_family == AF_INET6)
		return (&((*(struct sockaddr_in6*)addr).sin6_addr));
	return (NULL);
}