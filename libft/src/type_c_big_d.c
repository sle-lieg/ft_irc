/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c_D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 00:17:06 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/03/06 00:19:00 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_c(t_env *e)
{
	unsigned char car;

	if (e->modif[L] % 2)
	{
		ft_type_big_c(e);
		return ;
	}
	car = va_arg(e->ap, uint32_t);
	if (e->flags[MIN])
	{
		*e->pos++ = car;
		while (e->width-- > 1)
			*e->pos++ = ' ';
	}
	else
	{
		while (e->width-- > 1)
		{
			if (e->flags[ZERO])
				*e->pos++ = '0';
			else
				*e->pos++ = ' ';
		}
		*e->pos++ = car;
	}
}

void	ft_type_big_d(t_env *e)
{
	e->modif[H] = 0;
	e->modif[L] = 1;
	e->modif[J] = 0;
	e->modif[Z] = 0;
	ft_type_d(e);
}
