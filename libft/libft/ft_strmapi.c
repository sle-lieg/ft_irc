/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:27:53 by sle-lieg          #+#    #+#             */
/*   Updated: 2016/11/14 15:38:39 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstr;

	i = 0;
	newstr = NULL;
	s ? newstr = ft_strnew(ft_strlen(s)) : 0;
	if (!newstr || !s)
		return (NULL);
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	return (newstr);
}
