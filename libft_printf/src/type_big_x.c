/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_big_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 00:21:35 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/03/12 16:15:48 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_big_x(t_env *e)
{
	char	*tmp;
	char	*begin;
	int		len;

	begin = e->pos;
	tmp = ft_get_arg_x(e);
	len = ft_strlen(tmp);
	if (e->accu_bool || e->flags[MIN])
		e->flags[ZERO] = 0;
	if (*tmp == '0' && e->accu_bool)
		len--;
	e->width -= len;
	if (e->flags[DIEZ] && *tmp != '0')
		e->width -= 2;
	e->accu -= len;
	if (e->accu > 0)
		e->width -= e->accu;
	if (e->flags[MIN])
		ft_post_indent_x(e, tmp);
	else
		ft_pre_indent_x(e, tmp);
	ft_toupper(begin);
}
