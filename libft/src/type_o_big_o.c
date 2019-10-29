/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o_big_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 00:27:12 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/03/10 01:40:00 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_o(t_env *e)
{
	char	*tmp;
	int		len;

	tmp = ft_get_arg_o(e);
	len = ft_strlen(tmp);
	if (e->accu_bool || e->flags[MIN])
		e->flags[ZERO] = 0;
	if (*tmp == '0' && e->accu_bool)
		len--;
	e->width -= len;
	e->accu -= len;
	if (e->accu <= 0 && e->flags[DIEZ] && (*tmp != '0' || e->accu_bool))
	{
		e->accu = 1;
		e->width--;
	}
	else if (e->accu > 0)
		e->width -= e->accu;
	if (e->flags[MIN])
		ft_post_indent_o(e, tmp);
	else
		ft_pre_indent_o(e, tmp);
}

void	ft_post_indent_o(t_env *e, char *tmp)
{
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

void	ft_pre_indent_o(t_env *e, char *tmp)
{
	while (e->width-- > 0)
	{
		if (e->flags[ZERO])
			*e->pos++ = '0';
		else
			*e->pos++ = ' ';
	}
	while (e->accu-- > 0)
		*e->pos++ = '0';
	if (*tmp != '0' || !e->accu_bool)
	{
		while (*tmp)
			*e->pos++ = *tmp++;
	}
}

char	*ft_get_arg_o(t_env *e)
{
	char *tmp;

	if (e->modif[Z])
		tmp = ft_itoa_base((size_t)va_arg(e->ap, uint64_t), 8);
	else if (e->modif[J])
		tmp = ft_itoa_base((uintmax_t)va_arg(e->ap, uint64_t), 8);
	else if (e->modif[L])
		tmp = ft_itoa_base(va_arg(e->ap, uint64_t), 8);
	else if (e->modif[H] && e->modif[H] % 2 != 0)
		tmp = ft_itoa_base((uint16_t)va_arg(e->ap, uint64_t), 8);
	else if (e->modif[H])
		tmp = ft_itoa_base((uint8_t)va_arg(e->ap, uint64_t), 8);
	else
		tmp = ft_itoa_base(va_arg(e->ap, uint32_t), 8);
	return (tmp);
}

void	ft_type_big_o(t_env *e)
{
	e->modif[H] = 0;
	e->modif[L] = 1;
	e->modif[J] = 0;
	e->modif[Z] = 0;
	ft_type_o(e);
}
