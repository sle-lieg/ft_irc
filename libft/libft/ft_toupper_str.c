/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:18:41 by sle-lieg          #+#    #+#             */
/*   Updated: 2019/05/22 17:44:21 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_toupper_str(char *str)
{
	char *ptr;

	ptr = str;
	if (str)
	{
		while (*ptr)
		{
			if (ft_islower(*ptr))
				*ptr -= 32;
			++ptr;
		}
	}
	return (str);
}
