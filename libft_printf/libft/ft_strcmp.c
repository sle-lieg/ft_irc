/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 20:42:18 by sle-lieg          #+#    #+#             */
/*   Updated: 2016/12/15 21:57:56 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int i;
	unsigned int diff;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	diff = ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (diff);
}
