/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:41:39 by oltkache          #+#    #+#             */
/*   Updated: 2018/06/11 16:41:40 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_lable_add(t_lb **l, char *name, t_lb *op)
{
	t_lb *head;

	if (!(*l))
	{
		*l = (t_lb*)malloc(sizeof(t_lb));
		(*l)->name = ft_strdup(name);
		(*l)->op = op;
		(*l)->next = NULL;
		return ;
	}
	head = *l;
	while ((*l)->next)
		(*l) = (*l)->next;
	(*l)->next = (t_lb*)malloc(sizeof(t_lb));
	(*l)->next->name = ft_strdup(name);
	(*l)->next->op = op;
	(*l)->next->next = NULL;
	*l = head;
}

int		ft_in_lable(char s)
{
	int i;

	i = 0;
	while (LABEL_CHARS[i])
		if (s == LABEL_CHARS[i++])
			return (1);
	return (0);
}

void	ft_get_lst(t_list **lst, char *file)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (file[i])
	{
		j = i;
		if (i > 0 && (file[i - 1] == '%' || file[i - 1] == '-'))
			j -= 1;
		while ((file[i] && !((file[i] == ' ' || file[i] == '\n') ||
			(i > 0 && file[i] == ':' && ft_in_lable(file[i - 1]) == 1))) ||
			file[i] == '%' || file[i] == '-')
			if (file[++i] == '%' || (file[i] == '-' && file[i - 1] != '%'))
				break ;
		if (i > 0 && file[i] == ':' && file[i - 1] != '%' && i - j + 1 != j)
			tmp = ft_strsub(file, j, i - j + 1);
		else
			tmp = ft_strsub(file, j, i - j);
		(ft_strcmp(tmp, "") != 0) ? ft_lstaddend(lst, tmp) : ft_strdel(&tmp);
		if (file[i])
			++i;
	}
}

int		ft_args_num(char *s)
{
	if (ft_strcmp(s, "aff") == 0 || ft_strcmp(s, "fork") == 0 ||
		ft_strcmp(s, "zjmp") == 0 || ft_strcmp(s, "live") == 0 ||
		ft_strcmp(s, "lfork") == 0)
		return (1);
	else if (ft_strcmp(s, "sti") == 0 || ft_strcmp(s, "and") == 0 ||
		ft_strcmp(s, "add") == 0 || ft_strcmp(s, "sub") == 0 ||
		ft_strcmp(s, "or") == 0 || ft_strcmp(s, "xor") == 0 ||
		ft_strcmp(s, "ldi") == 0 || ft_strcmp(s, "lldi") == 0)
		return (3);
	else if (ft_strcmp(s, "ld") == 0 || ft_strcmp(s, "st") == 0 ||
		ft_strcmp(s, "lld") == 0)
		return (2);
	return (0);
}

int		ft_lb(char *s)
{
	if (ft_strcmp(s, "live") == 0 || ft_strcmp(s, "ld") == 0 ||
		ft_strcmp(s, "st") == 0 || ft_strcmp(s, "add") == 0 ||
		ft_strcmp(s, "sub") == 0 || ft_strcmp(s, "and") == 0 ||
		ft_strcmp(s, "or") == 0 || ft_strcmp(s, "xor") == 0 ||
		ft_strcmp(s, "lld") == 0 || ft_strcmp(s, "aff") == 0)
		return (4);
	else if (ft_strcmp(s, "zjmp") == 0 || ft_strcmp(s, "ldi") == 0 ||
		ft_strcmp(s, "sti") == 0 || ft_strcmp(s, "fork") == 0 ||
		ft_strcmp(s, "lldi") == 0 || ft_strcmp(s, "lfork") == 0)
		return (2);
	return (0);
}
