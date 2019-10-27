/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:13:02 by sle-lieg          #+#    #+#             */
/*   Updated: 2016/12/16 21:55:09 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newstr;
	size_t	i;

	i = 0;
	newstr = (char*)malloc(sizeof(char) * (size + 1));
	if (!newstr)
		return (NULL);
	while (i < size)
	{
		newstr[i] = 0;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
