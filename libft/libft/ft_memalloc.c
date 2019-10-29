/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:39:46 by sle-lieg          #+#    #+#             */
/*   Updated: 2016/12/02 18:27:05 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memzone;
	size_t	i;

	i = 0;
	memzone = (void*)malloc(sizeof(*memzone) * size);
	if (!memzone)
		return (NULL);
	while (i < size)
	{
		*((char *)memzone + i) = 0;
		i++;
	}
	return (memzone);
}
