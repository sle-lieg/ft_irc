/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_addr_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 00:01:44 by avalanche         #+#    #+#             */
/*   Updated: 2020/04/15 23:44:20 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket_tools.h"

void init_addr_infos(t_addrinfo *addinfo, uint16_t AF, uint16_t socket_type, \
						uint16_t flags)
{
	ft_memset(addinfo, 0, sizeof(*addinfo));
	addinfo->ai_family = AF;
	addinfo->ai_socktype = socket_type;
	addinfo->ai_flags = flags;
}