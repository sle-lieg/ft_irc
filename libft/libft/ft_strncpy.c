/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:33:47 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/03/03 20:50:33 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (!src[i])
		{
			while (i < len)
				dst[i++] = '\0';
		}
		else
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
