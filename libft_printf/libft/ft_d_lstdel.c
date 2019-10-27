/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:14:54 by sle-lieg          #+#    #+#             */
/*   Updated: 2016/11/14 20:58:18 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_d_lstdel(t_dlist **alst)
{
	t_dlist *ptr;

	ptr = *alst;
	while (ptr)
	{
		free(ptr->content);
		ptr->content_size = 0;
		*alst = ptr->next;
		free(ptr);
		ptr = *alst;
	}
}
