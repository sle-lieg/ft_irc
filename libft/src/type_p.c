/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 00:27:29 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/03/10 01:40:28 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_p(t_env *e)
{
	char	*tmp;
	int		len;

	tmp = ft_itoa_base(va_arg(e->ap, uint64_t), 16);
	len = ft_strlen(tmp);
	if (*tmp == '0' && e->accu_bool)
		len--;
	e->accu -= len;
	e->width -= (len + 2);
	if (e->accu > 0)
		e->width -= e->accu;
	if (e->flags[MIN])
		ft_post_indent_p(e, tmp);
	else
		ft_pre_indent_p(e, tmp);
}

void	ft_post_indent_p(t_env *e, char *tmp)
{
	*e->pos++ = '0';
	*e->pos++ = 'x';
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

void	ft_pre_indent_p(t_env *e, char *tmp)
{
	if (e->flags[ZERO] && !e->accu_bool)
	{
		*e->pos++ = '0';
		*e->pos++ = 'x';
		while (e->width-- > 0)
			*e->pos++ = '0';
	}
	else
	{
		while (e->width-- > 0)
			*e->pos++ = ' ';
		*e->pos++ = '0';
		*e->pos++ = 'x';
		while (e->accu-- > 0)
			*e->pos++ = '0';
	}
	if (*tmp != '0' || !e->accu_bool)
	{
		while (*tmp)
			*e->pos++ = *tmp++;
	}
}
