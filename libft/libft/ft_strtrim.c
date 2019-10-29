/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:18:50 by sle-lieg          #+#    #+#             */
/*   Updated: 2016/11/09 16:36:22 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_chk_spaces(const char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

static	int		ft_sizecopy(char const *s)
{
	int min;
	int max;

	min = 0;
	max = ft_strlen(s) - 1;
	while (s[min] == ' ' || s[min] == '\n' || s[min] == '\t')
		min++;
	while (s[max] == ' ' || s[max] == '\n' || s[max] == '\t')
		max--;
	if (max > min)
		return (max - min + 1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	copy = NULL;
	s ? copy = ft_strnew(ft_sizecopy(s)) : 0;
	if (!copy)
		return (NULL);
	while (s && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (s && s[i])
	{
		if (ft_chk_spaces(s + i))
		{
			copy[j] = '\0';
			return (copy);
		}
		copy[j] = s[i];
		i++;
		j++;
	}
	copy[j] = '\0';
	return (copy);
}
