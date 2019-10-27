/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:10:43 by sle-lieg          #+#    #+#             */
/*   Updated: 2016/12/10 18:05:22 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*strnew;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	strnew = NULL;
	if (s1 || s2)
		strnew = ft_strnew((ft_strlen(s1)) + (ft_strlen(s2)));
	if (!strnew)
		return (NULL);
	while (s1 && s1[i])
	{
		strnew[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		strnew[i + j] = s2[j];
		j++;
	}
	strnew[i + j] = '\0';
	return (strnew);
}
