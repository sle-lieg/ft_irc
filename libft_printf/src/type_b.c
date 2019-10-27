/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 01:10:49 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/03/10 01:11:30 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_b(t_env *e)
{
	char	*tmp;
	int		len;

	tmp = ft_get_arg_b(e);
	len = ft_strlen(tmp);
	if (e->accu_bool || e->flags[MIN])
		e->flags[ZERO] = 0;
	e->width -= len;
	if (e->flags[DIEZ])
		e->width -= 2;
	e->accu -= len;
	if (e->accu > 0)
		e->width -= e->accu;
	if (e->flags[MIN])
		ft_post_indent_b(e, tmp);
	else
		ft_pre_indent_b(e, tmp);
}

void	ft_post_indent_b(t_env *e, char *tmp)
{
	if (e->flags[DIEZ] && *tmp != '0')
	{
		*e->pos++ = '0';
		*e->pos++ = 'b';
	}
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

void	ft_pre_indent_b(t_env *e, char *tmp)
{
	if (e->flags[ZERO] && !e->accu_bool)
	{
		if (e->flags[DIEZ] && *tmp != '0')
		{
			*e->pos++ = '0';
			*e->pos++ = 'b';
		}
		while (e->width-- > 0)
			*e->pos++ = '0';
	}
	else
		ft_pre_indent_bnext(e, tmp);
	if (*tmp != '0' || !e->accu_bool)
	{
		while (*tmp)
			*e->pos++ = *tmp++;
	}
}

void	ft_pre_indent_bnext(t_env *e, char *tmp)
{
	while (e->width-- > 0)
		*e->pos++ = ' ';
	if (e->flags[DIEZ] && *tmp != '0')
	{
		*e->pos++ = '0';
		*e->pos++ = 'b';
	}
	while (e->accu-- > 0)
		*e->pos++ = '0';
}

char	*ft_get_arg_b(t_env *e)
{
	char *tmp;

	if (e->modif[Z])
		tmp = ft_itoa_base((size_t)va_arg(e->ap, uint64_t), 2);
	else if (e->modif[J])
		tmp = ft_itoa_base((uintmax_t)va_arg(e->ap, uint64_t), 2);
	else if (e->modif[L])
		tmp = ft_itoa_base(va_arg(e->ap, uint64_t), 2);
	else if (e->modif[H] && e->modif[H] % 2 != 0)
		tmp = ft_itoa_base((uint16_t)va_arg(e->ap, uint64_t), 2);
	else if (e->modif[H])
		tmp = ft_itoa_base((uint8_t)va_arg(e->ap, uint64_t), 2);
	else
		tmp = ft_itoa_base(va_arg(e->ap, uint64_t), 2);
	return (tmp);
}
