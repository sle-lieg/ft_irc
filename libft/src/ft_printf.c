/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 00:08:29 by sle-lieg          #+#    #+#             */
/*   Updated: 2018/06/18 08:24:30 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_env		e;
	va_list		ap_1;

	va_start(ap_1, format);
	ft_init(&e);
	va_copy(e.ap, ap_1);
	ft_read(&e, format);
	ft_print_buff(&e);
	va_end(ap_1);
	va_end(e.ap);
	if (e.error)
		return (-1);
	return (e.ret);
}

void	ft_print_buff(t_env *e)
{
	if (e->error)
		e->pos = e->last_valid_pos;
	*e->pos = '\0';
	e->ret += write(1, e->buff, e->pos - e->buff);
	e->pos = e->buff;
}

void	ft_read(t_env *e, const char *format)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (e->error)
			return ;
		if (format[i] == '%')
		{
			ft_parse(e, format, &i);
			ft_reset_options(e);
		}
		else if (format[i] == '{')
			ft_get_color(e, format, &i);
		else
		{
			if (e->pos - e->buff > BUF_SIZE - 2)
				ft_print_buff(e);
			*e->pos++ = format[i++];
		}
	}
}

void	ft_reset_options(t_env *e)
{
	e->flags[0] = 0;
	e->flags[1] = 0;
	e->flags[2] = 0;
	e->flags[3] = 0;
	e->flags[4] = 0;
	e->modif[0] = 0;
	e->modif[1] = 0;
	e->modif[2] = 0;
	e->modif[3] = 0;
	e->width = -1;
	e->accu = -1;
	e->width_bool = FALSE;
	e->accu_bool = FALSE;
}

void	ft_init(t_env *e)
{
	e->pos = e->buff;
	e->last_valid_pos = e->buff;
	e->ret = 0;
	e->error = FALSE;
	ft_reset_options(e);
	e->type_select[0] = &ft_type_s;
	e->type_select[1] = &ft_type_big_s;
	e->type_select[2] = &ft_type_p;
	e->type_select[3] = &ft_type_d;
	e->type_select[4] = &ft_type_big_d;
	e->type_select[5] = &ft_type_d;
	e->type_select[6] = &ft_type_o;
	e->type_select[7] = &ft_type_big_o;
	e->type_select[8] = &ft_type_u;
	e->type_select[9] = &ft_type_big_u;
	e->type_select[10] = &ft_type_x;
	e->type_select[11] = &ft_type_big_x;
	e->type_select[12] = &ft_type_c;
	e->type_select[13] = &ft_type_big_c;
	e->type_select[14] = &ft_type_b;
}
