/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_port.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 23:15:41 by avalanche         #+#    #+#             */
/*   Updated: 2019/11/01 00:32:34 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_tools.h"
#include <stdio.h>

uint16_t get_port(t_sockaddr_storage *addr)
{
	uint16_t port;

	port = 0;
	if (addr->ss_family == AF_INET)
		port = ((struct sockaddr_in*)addr)->sin_port;
	else if (addr->ss_family == AF_INET6)
		port = ((struct sockaddr_in6*)addr)->sin6_port;
	return (port);
}