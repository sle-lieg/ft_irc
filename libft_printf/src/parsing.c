/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 00:13:44 by sle-lieg          #+#    #+#             */
/*   Updated: 2018/06/17 14:37:00 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse(t_env *e, const char *format, int *i)
{
	int j;

	j = 0;
	while (ft_get_opt(e, format, i))
		;
	while (TYPE[j] && TYPE[j] != format[*i])
		j++;
	if (j < 15)
	{
		if (e->pos - e->buff + (e->width + 100) > BUF_SIZE - 2)
			ft_print_buff(e);
		e->type_select[j](e);
		++(*i);
		if (!e->error)
			e->last_valid_pos = e->pos;
	}
	else
		ft_fill_error(e, format, i);
}

void	ft_fill_error(t_env *e, const char *format, int *i)
{
	if (e->pos - e->buff + (e->width + 2) > BUF_SIZE - 2)
		ft_print_buff(e);
	if (!format[*i])
		return ;
	if (e->flags[MIN])
	{
		*e->pos++ = format[(*i)++];
		while (--(e->width) > 0)
			*e->pos++ = ' ';
	}
	else
	{
		while (--(e->width) > 0)
		{
			if (e->flags[ZERO])
				*e->pos++ = '0';
			else
				*e->pos++ = ' ';
		}
		*e->pos++ = format[(*i)++];
	}
	e->last_valid_pos = e->pos;
}

int		ft_get_flags(t_env *e, char flag)
{
	int i;

	i = 0;
	while (FLAGS[i])
	{
		if (FLAGS[i] == flag)
		{
			e->flags[i] = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_get_modifier(t_env *e, char flag)
{
	int i;

	i = 0;
	while (MODIF[i])
	{
		if (MODIF[i] == flag)
		{
			e->modif[i] += 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_get_opt(t_env *e, const char *format, int *i)
{
	++(*i);
	if ((format[*i] < '1' || format[*i] > '9')
	&& format[*i] != '.' && format[*i] != '*')
	{
		if ((ft_get_flags(e, format[*i]) || (ft_get_modifier(e, format[*i]))))
			return (1);
	}
	else
	{
		if (format[*i] == '.')
			ft_get_accuracy(e, format, i);
		else
			ft_get_width(e, format, i);
		while (format[*i + 1] >= '0' && format[*i + 1] <= '9'
				&& format[*i] != '*')
			(*i)++;
		return (1);
	}
	return (0);
}
