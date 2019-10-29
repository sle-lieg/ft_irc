/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 00:22:48 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/03/10 01:39:23 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_d(t_env *e)
{
	char	*tmp;
	int		len;

	tmp = ft_get_arg_d(e);
	len = ft_strlen(tmp);
	if (e->accu_bool || e->flags[MIN])
		e->flags[ZERO] = 0;
	if (*tmp != '-' && (e->flags[PLUS] || e->flags[SPACE]))
		e->width--;
	if (*tmp == '0' && e->accu_bool)
		len--;
	e->width -= len;
	e->accu -= (*tmp == '-' ? (len - 1) : len);
	if (e->accu > 0)
		e->width -= e->accu;
	if (e->flags[MIN])
		ft_post_indent_d(e, tmp);
	else
		ft_pre_indent_d(e, tmp);
}

void	ft_post_indent_d(t_env *e, char *tmp)
{
	if (*tmp != '-')
	{
		if (e->flags[PLUS])
			*e->pos++ = '+';
		else if (e->flags[SPACE])
			*e->pos++ = ' ';
	}
	else
		*e->pos++ = *tmp++;
	while (e->accu-- > 0)
		*e->pos++ = '0';
	if (*tmp != '0' || !e->accu_bool)
	{
		while (*tmp)
			*e->pos++ = *tmp++;
	}
	while (e->width-- > 0)
		*e->pos++ = ' ';
}

void	ft_pre_indent_d(t_env *e, char *tmp)
{
	if (e->flags[ZERO])
	{
		if (*tmp == '-')
			*e->pos++ = *tmp++;
		else if (e->flags[PLUS])
			*e->pos++ = '+';
		else if (e->flags[SPACE])
			*e->pos++ = ' ';
	}
	while (e->width-- > 0)
	{
		if (e->flags[ZERO])
			*e->pos++ = '0';
		else
			*e->pos++ = ' ';
	}
	ft_pre_indent_dnext(e, tmp);
}

void	ft_pre_indent_dnext(t_env *e, char *tmp)
{
	if (*tmp != '-' && !e->flags[ZERO])
	{
		if (e->flags[PLUS])
			*e->pos++ = '+';
		else if (e->flags[SPACE])
			*e->pos++ = ' ';
	}
	else
		*e->pos++ = *tmp++;
	while (e->accu-- > 0)
		*e->pos++ = '0';
	if (*tmp != '0' || !e->accu_bool)
	{
		while (*tmp)
			*e->pos++ = *tmp++;
	}
}

char	*ft_get_arg_d(t_env *e)
{
	char *tmp;

	if (e->modif[Z])
		tmp = ft_itoa((size_t)va_arg(e->ap, uint64_t));
	else if (e->modif[J])
		tmp = ft_itoa((intmax_t)va_arg(e->ap, uint64_t));
	else if (e->modif[L] && e->modif[L] % 2 == 0)
		tmp = ft_itoa(va_arg(e->ap, long long));
	else if (e->modif[L])
		tmp = ft_itoa((long)va_arg(e->ap, uint64_t));
	else if (e->modif[H] && e->modif[H] % 2 != 0)
		tmp = ft_itoa((short)va_arg(e->ap, uint64_t));
	else if (e->modif[H])
		tmp = ft_itoa((char)va_arg(e->ap, uint64_t));
	else
		tmp = ft_itoa(va_arg(e->ap, int));
	return (tmp);
}
