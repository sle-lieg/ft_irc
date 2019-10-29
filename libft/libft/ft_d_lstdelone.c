/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:23:19 by sle-lieg          #+#    #+#             */
/*   Updated: 2016/11/14 20:58:52 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_d_lstdelone(t_dlist **alst)
{
	(*alst)->next->prev = (*alst)->prev;
	(*alst)->prev->next = (*alst)->next;
	free((*alst)->content);
	free(*alst);
}
