/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:44:58 by sle-lieg          #+#    #+#             */
/*   Updated: 2016/11/09 17:21:37 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*strcut;

	i = 0;
	strcut = ft_strnew(len);
	if (!strcut || !s)
		return (NULL);
	while (i < len)
	{
		strcut[i] = s[start];
		i++;
		start++;
	}
	return (strcut);
}
