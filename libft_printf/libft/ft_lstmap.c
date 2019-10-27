/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:06:36 by sle-lieg          #+#    #+#             */
/*   Updated: 2016/11/13 20:47:24 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *newlst;
	t_list *ptrlst;

	newlst = NULL;
	while (lst)
	{
		new = f(lst);
		if (!new)
			return (NULL);
		if (!newlst)
		{
			newlst = new;
			ptrlst = new;
		}
		else
		{
			ptrlst->next = new;
			ptrlst = new;
		}
		lst = lst->next;
	}
	ptrlst->next = NULL;
	return (newlst);
}
