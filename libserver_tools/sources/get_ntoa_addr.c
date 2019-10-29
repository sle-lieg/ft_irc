/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ntoa_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:37:13 by avalanche         #+#    #+#             */
/*   Updated: 2019/10/30 00:00:01 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_tools.h"

const char *get_ntoa_addr(struct sockaddr_storage *addr)
{
	void *in_addr;

	if ((in_addr = get_in_addr((struct sockaddr *)addr)))
		return (inet_ntoa(*(struct in_addr *)in_addr));
	return (NULL);
}