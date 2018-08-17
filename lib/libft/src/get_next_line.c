/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:41:45 by kmushta           #+#    #+#             */
/*   Updated: 2017/12/02 13:41:47 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (!c)
		return (i);
	return (-1);
}

static int			ft_read(char **line, char *str, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (*line)
		i = ft_strlen(*line);
	k = size + i;
	if (!(ft_realloc((void **)line, sizeof(char) * i, sizeof(char) * (k + 1))))
		return (-1);
	j = 0;
	while (i < k)
		(*line)[i++] = str[j++];
	(*line)[i] = 0;
	i = ft_c(str, '\n');
	if (i == -1)
		*str = 0;
	else
	{
		j = 0;
		while (str[++i])
			str[j++] = str[i];
		str[j] = 0;
	}
	return (1);
}

static int			ft_read_line(const int fd, char **line,
	t_gnl_list **alst, t_gnl_list **list)
{
	int	i;

	while (1)
		if (!*((*list)->data))
		{
			if ((i = read(fd, (*list)->data, BUFF_SIZE)) < 1)
			{
				if ((*list)->prev)
					(*list)->prev->next = (*list)->next;
				else
					*alst = (*list)->next;
				if ((*list)->next)
					(*list)->next->prev = (*list)->prev;
				free((*list)->data);
				free((*list));
				if (*line)
					return (1);
				return (i);
			}
			((*list)->data)[i] = 0;
		}
		else if ((i = ft_c((*list)->data, '\n')) != -1)
			return (ft_read(line, (*list)->data, i));
		else if (ft_read(line, (*list)->data, ft_c((*list)->data, '\0')) == -1)
			return (-1);
}

static t_gnl_list	*ft_getlist(t_gnl_list **alst, const int fd)
{
	t_gnl_list	*list;

	list = *alst;
	while (list && list->fd != fd)
		list = list->next;
	if (!list)
	{
		if (!(list = (t_gnl_list *)malloc(sizeof(t_gnl_list))))
			return (0);
		if (!(list->data = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		{
			free(list);
			return (0);
		}
		*(list->data) = 0;
		list->next = *alst;
		list->prev = 0;
		if (*alst)
			(*alst)->prev = list;
		list->fd = fd;
		*alst = list;
	}
	return (list);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl_list	*alst;
	t_gnl_list			*list;
	int					q;

	if (!line)
		return (-1);
	list = ft_getlist(&alst, fd);
	if (!list)
		return (-1);
	*line = 0;
	q = ft_read_line(fd, line, &alst, &list);
	return (q);
}
