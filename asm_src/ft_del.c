/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 14:57:18 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/27 14:57:19 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_del_arg(t_lb *a)
{
	t_lb	*tmp;

	while (a)
	{
		tmp = a->next;
		ft_strdel(&(a->name));
		free(a);
		a = tmp;
	}
}

void	ft_del_op(t_lb *op)
{
	t_lb *tmp;

	while (op)
	{
		tmp = op->next;
		ft_strdel(&(op->name));
		ft_del_arg(op->op);
		free(op);
		op = tmp;
	}
}

void	ft_del_lb(t_lb *l)
{
	t_lb *tmp;

	while (l)
	{
		tmp = l->next;
		ft_strdel(&(l->name));
		ft_del_op(l->op);
		free(l);
		l = tmp;
	}
}

void	ft_del_lst(t_list *lst)
{
	t_list *tmp;

	while (lst)
	{
		tmp = lst->next;
		ft_strdel((char**)(&(lst->content)));
		free(lst);
		lst = tmp;
	}
}

void	ft_del_all(t_list *lst, t_lb *lb, char *name)
{
	ft_del_lb(lb);
	ft_del_lst(lst);
	ft_strdel(&(name));
}
