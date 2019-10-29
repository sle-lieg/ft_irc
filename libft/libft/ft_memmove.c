/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 22:08:12 by sle-lieg          #+#    #+#             */
/*   Updated: 2016/11/21 18:58:41 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_cpy_from_end(void *dst, const void *src, size_t n)
{
	int i;

	i = n - 1;
	while (i >= 0)
	{
		*((char *)dst + i) = *((char *)src + i);
		i = i - 1;
	}
}

static void		ft_cpy_from_beg(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((char *)dst + i) = *((char *)src + i);
		i++;
	}
}

void			*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst > src)
		ft_cpy_from_end(dst, src, n);
	else
		ft_cpy_from_beg(dst, src, n);
	return (dst);
}
