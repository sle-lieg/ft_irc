/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:53:07 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/02/18 22:52:15 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BASE_LOW	"0123456789abcdefghijklmnopqrstuvwxyz"

char	*ft_itoa_base(uint64_t n, const int base)
{
	static char	str[0x65];
	char		*p;

	ft_bzero(str, 0x65);
	p = str + 0x64;
	if (!n)
		*--p = '0';
	while (n)
	{
		*--p = BASE_LOW[n % base];
		n /= base;
	}
	return (p);
}
