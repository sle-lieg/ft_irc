/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:48:32 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/01/15 05:47:07 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_lst	*ft_creanew(t_lst *elem, const int fd)
{
	elem = (t_lst*)malloc(sizeof(t_lst));
	if (!elem)
		return (NULL);
	elem->str = NULL;
	elem->fd = fd;
	elem->next = NULL;
	return (elem);
}

static t_lst	*ft_find_fd(t_lst *lst, const int fd)
{
	t_lst	*tmp;

	tmp = lst;
	while (tmp->fd != fd && tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->fd != fd)
	{
		tmp->next = ft_creanew(tmp, fd);
		if (!tmp->next)
			return (NULL);
		tmp = tmp->next;
	}
	return (tmp);
}

static char		*ft_read_fd(char *str, const int fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (NULL);
		buff[ret] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, buff);
		free(tmp);
		if (ft_strchr(str + i, '\n'))
			return (str);
		i += ret;
	}
	return (str);
}

static int		ft_checkret(char **str, char **line)
{
	char *tmp;
	char *old;

	tmp = NULL;
	if ((tmp = ft_strchr(*str, '\n')))
		*tmp = '\0';
	*line = ft_strdup(*str);
	if (**str == '\0' && (*str != tmp))
		return (0);
	old = *str;
	if (tmp)
	{
		*str += (ft_strlen(*str) + 1);
		*str = ft_strdup(*str);
		free(old);
	}
	else
		*str += ft_strlen(*str);
	return (1);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_lst	*lst;
	t_lst			*tmp;

	if (fd < 0 || !line)
		return (-1);
	if (!lst)
	{
		lst = ft_creanew(lst, fd);
		tmp = lst;
	}
	else
		tmp = ft_find_fd(lst, fd);
	if (!tmp)
		return (-1);
	if (!tmp->str || (tmp->str && !ft_strchr(tmp->str, '\n')))
	{
		tmp->str = ft_read_fd(tmp->str, fd);
		if (!tmp->str)
			return (-1);
	}
	return (ft_checkret(&tmp->str, line));
}
