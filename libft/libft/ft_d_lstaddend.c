/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstaddend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:08:12 by sle-lieg          #+#    #+#             */
/*   Updated: 2016/11/20 22:31:55 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_d_lstaddend(t_dlist **alst, t_dlist *newl)
{
	while ((*alst)->next)
		*alst = (*alst)->next;
	newl->prev = *alst;
	(*alst)->next = newl;
}
