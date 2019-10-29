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
	int	i;
	int	j;

	i = s1 ? ft_strlen(s1) : 0;
	j = s2 ? ft_strlen(s2) : 0;
	if (!(strnew = ft_strnew(i + j)))
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
		{
			strnew[i] = s1[i];
			++i;
		}
	if (s2)
		while (s2[j])
		{
			strnew[i + j] = s2[j];
			++j;
		}
	return (strnew);
}
