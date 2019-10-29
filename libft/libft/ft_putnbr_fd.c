/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:25:18 by sle-lieg          #+#    #+#             */
/*   Updated: 2016/11/14 14:28:20 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
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
		write(fd, "-", 1);
	}
	else
		pos = n;
	while (pow)
	{
		tmp = pos / pow % 10 + '0';
		write(fd, &tmp, 1);
		pow /= 10;
	}
}
