/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_in_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:36:09 by avalanche         #+#    #+#             */
/*   Updated: 2019/11/01 11:22:24 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_tools.h"

void *get_in_addr(t_sockaddr_storage *addr)
{
	if (addr->ss_family == AF_INET)
		return (&((*(struct sockaddr_in*)addr).sin_addr));
	else if (addr->ss_family == AF_INET6)
		return (&((*(struct sockaddr_in6*)addr).sin6_addr));
	return (NULL);
}