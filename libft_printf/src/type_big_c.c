/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_big_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 01:11:48 by sle-lieg          #+#    #+#             */
/*   Updated: 2018/06/18 08:25:25 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_big_c(t_env *e)
{
	uint32_t arg;

	arg = va_arg(e->ap, uint32_t);
	if ((MB_CUR_MAX == 1 && arg > 255) || arg > 0x10FFFF ||
		(arg >= 0xD800 && arg <= 0xDFFF))
	{
		e->error = 1;
		return ;
	}
	e->width -= ft_wchar_len(arg);
	if (e->flags[MIN])
		ft_post_indent_big_c(e, arg);
	else
		ft_pre_indent_big_c(e, arg);
}

void	ft_post_indent_big_c(t_env *e, uint32_t arg)
{
	*((int *)e->pos) = 0;
	if (arg & FOUR)
		ft_four_octet(e, arg);
	else if (arg & THREE)
		ft_three_octet(e, arg);
	else if (arg & TWO && MB_CUR_MAX > 1)
		ft_two_octet(e, arg);
	else
		*e->pos++ = arg;
	while (e->width-- > 0)
		*e->pos++ = ' ';
}

void	ft_pre_indent_big_c(t_env *e, uint32_t arg)
{
	while (e->width-- > 0)
		*e->pos++ = (e->flags[ZERO] ? '0' : ' ');
	*((int *)e->pos) = 0;
	if (arg & FOUR)
		ft_four_octet(e, arg);
	else if (arg & THREE)
		ft_three_octet(e, arg);
	else if (arg & TWO && MB_CUR_MAX > 1)
		ft_two_octet(e, arg);
	else
		*e->pos++ = arg;
}
