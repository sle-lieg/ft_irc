/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalanche <avalanche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 11:48:49 by avalanche         #+#    #+#             */
/*   Updated: 2019/04/20 11:56:29 by avalanche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void ft_free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
}