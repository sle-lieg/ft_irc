/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:21:36 by sle-lieg          #+#    #+#             */
/*   Updated: 2016/12/09 20:23:52 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_pow(unsigned int n, int pow)
{
	long res;

	res = n;
	while (--pow > 1)
	{
		res *= n;
	}
	return (res);
}