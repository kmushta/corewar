/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:55:32 by oltkache          #+#    #+#             */
/*   Updated: 2018/06/11 16:55:33 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_args_len(char *s, char *op)
{
	int i;

	i = -1;
	if (s[0] == 'r')
		return (1);
	while (s[++i])
	{
		if (s[0] == ':')
			return (2);
		if (s[0] == '-')
			++i;
		if (s[i] && !(s[i] >= 48 && s[i] <= 57))
			break ;
	}
	if (!s[i])
		return (2);
	if (s[0] == '%')
		return (ft_lb(op));
	return (0);
}

void	ft_operation(t_lb **op, t_list *lt)
{
	char	*tmp;
	int		i;
	int		n_a;
	t_lb	*args;

	n_a = 1;
	while (n_a && lt)
	{
		args = NULL;
		i = 0;
		n_a = ft_args_num(lt->content);
		if (n_a == 0)
			return ;
		tmp = (char*)(lt->content);
		while (i++ < n_a)
		{
			ft_lable_add(&args, lt->next->content, NULL);
			lt = lt->next;
		}
		ft_lable_add(op, tmp, args);
		if (lt)
			lt = lt->next;
	}
}

int		ft_cotage(char *s)
{
	if (ft_strcmp(s, "live") == 0 || ft_strcmp(s, "zjmp") == 0 ||
		ft_strcmp(s, "fork") == 0 || ft_strcmp(s, "lfork") == 0)
		return (1);
	return (2);
}

void	ft_lable(t_lb **l, t_list *lt)
{
	char	*tmp;
	char	*name;
	t_lb	*op;
	int		i;

	while (lt)
	{
		op = NULL;
		tmp = lt->content;
		i = 0;
		while (tmp[i] && tmp[i] != ':')
			++i;
		if (!(*l) && !tmp[i])
		{
			ft_operation(&op, lt);
			ft_lable_add(l, "", op);
		}
		if (((char*)(lt->content))[ft_strlen((char*)(lt->content)) - 1] == ':')
		{
			name = (char*)(lt->content);
			ft_operation(&op, lt->next);
			ft_lable_add(l, name, op);
		}
		lt = lt->next;
	}
}

void	ft_exec_size(t_lb **lb, int *len)
{
	t_lb	*op;
	t_lb	*a;
	t_lb	*l;

	l = *lb;
	while (l)
	{
		op = l->op;
		while (op)
		{
			op->p = *len;
			a = op->op;
			*len += ft_cotage(op->name);
			op->len += ft_cotage(op->name);
			while (a)
			{
				*len += ft_args_len(a->name, op->name);
				op->len += ft_args_len(a->name, op->name);
				a = a->next;
			}
			op = op->next;
		}
		l = l->next;
	}
}
