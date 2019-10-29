/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 00:28:15 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/03/06 00:29:22 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_s(t_env *e)
{
	char	*tmp;
	int		len;

	if (e->modif[L] % 2)
	{
		ft_type_big_s(e);
		return ;
	}
	tmp = va_arg(e->ap, char *);
	len = (tmp ? ft_strlen(tmp) : 6);
	if (!tmp)
		tmp = "(null)";
	if (e->pos - e->buff + e->width + len > BUF_SIZE - 2)
		ft_print_buff(e);
	if (e->accu > len || !e->accu_bool)
		e->width -= len;
	else
		e->width -= e->accu;
	if (e->flags[MIN])
		ft_post_indent_s(e, tmp, len);
	else
		ft_pre_indent_s(e, tmp, len);
}

void	ft_post_indent_s(t_env *e, char *tmp, int len)
{
	if (e->accu > -1 && e->accu < len)
	{
		while (e->accu-- > 0)
			*e->pos++ = *tmp++;
	}
	else
	{
		while (*tmp)
			*e->pos++ = *tmp++;
	}
	while (e->width-- > 0)
		*e->pos++ = ' ';
}

void	ft_pre_indent_s(t_env *e, char *tmp, int len)
{
	while (e->width-- > 0)
	{
		if (e->flags[ZERO])
			*e->pos++ = '0';
		else
			*e->pos++ = ' ';
	}
	if (e->accu > -1 && e->accu < len)
	{
		while (e->accu-- > 0)
			*e->pos++ = *tmp++;
	}
	else
	{
		while (*tmp)
			*e->pos++ = *tmp++;
	}
	while (e->width-- > 0)
		*e->pos++ = ' ';
}
