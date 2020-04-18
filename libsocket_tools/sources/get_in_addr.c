/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_in_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:36:09 by avalanche         #+#    #+#             */
/*   Updated: 2020/04/15 23:44:19 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket_tools.h"

/*
	Return the sin_addr part of the sockaddr_storage, casted upon its ss_family.
	Basically return the ip or ip6 address part of the sockaddr structure.
*/
void *get_in_addr(t_sockaddr_storage *addr)
{
	if (addr->ss_family == AF_INET)
		return (&((*(struct sockaddr_in*)addr).sin_addr));
	else if (addr->ss_family == AF_INET6)
		return (&((*(struct sockaddr_in6*)addr).sin6_addr));
	return (NULL);
}