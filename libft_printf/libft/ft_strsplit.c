/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:48:10 by sle-lieg          #+#    #+#             */
/*   Updated: 2018/06/18 08:39:00 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**initarray(const char *s, char c)
{
	const char	*tmp;
	char		**array;
	int			nb_words;

	nb_words = 0;
	tmp = s;
	while (*tmp)
		if (*tmp++ != c && (!*tmp || *tmp == c))
			++nb_words;
	if (!(array = (char**)malloc((nb_words + 1) * sizeof(char*))))
		return (NULL);
	array[nb_words] = NULL;
	nb_words = 0;
	tmp = s;
	while (*tmp)
	{
		while (*tmp && *tmp != c)
			++tmp;
		if (!(array[nb_words++] = (char*)malloc((tmp - s + 1) * sizeof(char))))
			return (NULL);
		while (*tmp == c)
			++tmp;
		s = tmp;
	}
	return (array);
}

char			**ft_strsplit(const char *s, char c)
{
	const char	*tmp;
	char		**array;
	int			word;

	word = 0;
	while (*s == c)
		++s;
	if (!(array = initarray(s, c)))
		return (NULL);
	tmp = s;
	while (array[word])
	{
		while (*tmp != c)
			++tmp;
		ft_memcpy(array[word], s, tmp - s);
		array[word++][tmp - s] = '\0';
		while (*tmp == c)
			++tmp;
		s = tmp;
	}
	return (array);
}
