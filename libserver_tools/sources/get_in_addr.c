/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_in_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:36:09 by avalanche         #+#    #+#             */
/*   Updated: 2019/10/29 23:36:32 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_tools.h"

void *get_in_addr(struct sockaddr *addr)
{
	if (addr->sa_family == AF_INET)
		return (&((struct sockaddr_in*)&addr)->sin_addr);
	else if (addr->sa_family == AF_INET6)
		return (&((struct sockaddr_in6*)&addr)->sin6_addr);
	return (NULL);
}