/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 01:19:36 by sle-lieg          #+#    #+#             */
/*   Updated: 2018/06/18 08:25:44 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_four_octet(t_env *e, uint32_t arg)
{
	*e->pos++ ^= (0xF0 + (arg >> 18));
	*e->pos++ ^= (0x80 + ((arg & 0x3F000) >> 12));
	*e->pos++ ^= (0x80 + ((arg & 0xFC0) >> 6));
	*e->pos++ ^= (0x80 + (arg & 0x3F));
	return (4);
}

int	ft_three_octet(t_env *e, uint32_t arg)
{
	*e->pos++ ^= (0xE0 + (arg >> 12));
	*e->pos++ ^= (0x80 + ((arg & 0xFC0) >> 6));
	*e->pos++ ^= (0x80 + (arg & 0x3F));
	return (3);
}

int	ft_two_octet(t_env *e, uint32_t arg)
{
	*e->pos++ ^= (0xC0 + (arg >> 6));
	*e->pos++ ^= (0x80 + (arg & 0x3F));
	return (2);
}
