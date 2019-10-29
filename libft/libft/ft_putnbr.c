/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:35:14 by sle-lieg          #+#    #+#             */
/*   Updated: 2016/11/14 14:26:57 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	pos;
	int				pow;
	char			tmp;

	pow = 1;
	while (n / pow > 9 || n / pow < -9)
		pow *= 10;
	if (n < 0)
	{
		pos = n * -1;
		write(1, "-", 1);
	}
	else
		pos = n;
	while (pow)
	{
		tmp = pos / pow % 10 + '0';
		write(1, &tmp, 1);
		pow /= 10;
	}
}
