/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:12:06 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/02/18 22:50:22 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cast(long long *n)
{
	if (*n < 0)
	{
		*n = -*n;
		return (1);
	}
	return (0);
}

char		*ft_itoa(long long n)
{
	static char str[0x15];
	char		*p;
	int			neg;

	neg = 0;
	ft_bzero(str, 0x15);
	p = str + 0x14;
	if (n == -9223372036854775807 - 1)
	{
		*--p = '8';
		n = -922337203685477580;
	}
	neg = 0x1 >> ft_cast(&n);
	if (!n)
		*--p = '0';
	while (n > 0)
	{
		*--p = n % 10 + '0';
		n /= 10;
	}
	if (!neg)
		*--p = '-';
	return (p);
}
