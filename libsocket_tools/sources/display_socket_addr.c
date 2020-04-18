/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_socket_addr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 23:05:26 by avalanche         #+#    #+#             */
/*   Updated: 2020/04/15 23:44:19 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket_tools.h"
#include "ft_printf.h"

void display_socket_addr(t_sockaddr_storage *socket_addr)
{
	const char		*ip;
	uint16_t	port;

	ip = get_ntoa_addr(socket_addr);
	port = get_port(socket_addr);

	ft_printf("New connection from %s on port %d\n", ip, ntohs(port));
}