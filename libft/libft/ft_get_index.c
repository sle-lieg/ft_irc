/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:03:53 by avalanche         #+#    #+#             */
/*   Updated: 2019/05/22 18:09:07 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_get_index(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return i;
		++i;
	}
	return (-1);
}