/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:14:31 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/03/12 16:14:47 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_width(t_env *e, const char *format, int *i)
{
	e->width_bool = TRUE;
	if (format[*i] == '*')
	{
		e->width = va_arg(e->ap, int);
		if (e->width < 0)
		{
			e->flags[MIN] = 1;
			e->width *= -1;
		}
	}
	else
		e->width = ft_atoi(format + *i);
}

void	ft_get_accuracy(t_env *e, const char *format, int *i)
{
	e->accu_bool = TRUE;
	if (format[*i + 1] == '*')
	{
		e->accu = va_arg(e->ap, int);
		if (e->accu < 0)
			e->accu_bool = FALSE;
		++(*i);
	}
	else
	{
		if (format[*i + 1] >= '0' && format[*i + 1] <= '9')
			++(*i);
		e->accu = ft_atoi(format + *i);
	}
}

void	ft_get_color(t_env *e, const char *format, int *i)
{
	if (ft_strnequ(format + *i, "{eoc}", 5))
		ft_strcpy(e->pos, EOC);
	else if (ft_strnequ(format + *i, "{red}", 5))
		ft_strcpy(e->pos, RED);
	else if (ft_strnequ(format + *i, "{green}", 7))
		ft_strcpy(e->pos, GREEN);
	else if (ft_strnequ(format + *i, "{yellow}", 8))
		ft_strcpy(e->pos, YELLOW);
	else if (ft_strnequ(format + *i, "{blue}", 6))
		ft_strcpy(e->pos, BLUE);
	else if (ft_strnequ(format + *i, "{purple}", 8))
		ft_strcpy(e->pos, PURPLE);
	else if (ft_strnequ(format + *i, "{cyan}", 6))
		ft_strcpy(e->pos, CYAN);
	else if (ft_strnequ(format + *i, "{grey}", 6))
		ft_strcpy(e->pos, GREY);
	else
	{
		*e->pos++ = format[(*i)++];
		return ;
	}
	e->pos += (*(e->pos + 4) == 'm' ? 5 : 7);
	while (format[(*i) - 1] != '}')
		++(*i);
}
