/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:45:07 by sle-lieg          #+#    #+#             */
/*   Updated: 2016/11/14 15:41:03 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	while (big[i])
	{
		j = 0;
		while (i + j <= len && (big[i + j] == little[j] || !little[j]))
		{
			if (!little[j])
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
