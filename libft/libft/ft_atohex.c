/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:37:37 by avalanche         #+#    #+#             */
/*   Updated: 2019/05/22 18:42:30 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char *nbrs = "0123456789ABCDEF";

uint32_t	ft_atohex(const char *str)
{
	int			i;
	int			j;
	uint32_t	nbr;

	i = 0;
	j = 0;
	nbr = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '0' && (str[i+1] == 'x' || str[i+1] == 'X'))
		i+=2;
	while ((j = ft_get_index(nbrs, ft_toupper(str[i]))) != -1)
	{
		nbr <<= 4;
		nbr += j;
		i++;
	}
	return (nbr);
}