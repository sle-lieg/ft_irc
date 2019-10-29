/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:51:40 by sle-lieg          #+#    #+#             */
/*   Updated: 2016/11/17 21:25:08 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int i;
	unsigned int dst_len;
	unsigned int src_len;

	if (!size)
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size)
	{
		i = 0;
		while (src[i] && dst_len + i < size - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		if (size >= dst_len)
			dst[dst_len + i] = '\0';
	}
	if (dst_len > size)
		return (src_len + size);
	return (dst_len + src_len);
}
