/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:58:02 by oltkache          #+#    #+#             */
/*   Updated: 2018/06/11 16:58:03 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_ex_s(int len, char (*t)[])
{
	if ((char)((len >> 24) & 255) != 0)
		(*t)[0] = (char)((len >> 24) & 255);
	if ((char)((len >> 16) & 255) != 0)
		(*t)[1] = (char)((len >> 16) & 255);
	if ((char)((len >> 8) & 255) != 0)
		(*t)[2] = (char)((len >> 8) & 255);
	if ((char)(len & 255) != 0)
		(*t)[3] = (char)(len & 255);
}

void	ft_cod(int num, char *op, char *a)
{
	int				k;
	unsigned int	n;

	n = (unsigned int)num;
	k = 0;
	if (ft_lb(op) == 2 || a[0] != '%')
	{
		n = (unsigned short)n;
		k = 1;
	}
	else
		ft_printf("%-4d%-4d", n >> 24, (n >> 16) & 255);
	ft_printf("%-4d%-4d", (n >> 8) & 255, n & 255);
	(k == 1) ? ft_printf("%10s", " ") : ft_printf("%2s", " ");
}

void	ft_pr_di(t_lb *a, int i, char *op)
{
	if (i == 0)
	{
		if (a->name[0] != ':' && a->name[1] != ':')
			(a->name[0] == '%') ? ft_cod(ft_atoi(&a->name[1]), op, a->name) :
		ft_cod(ft_atoi(a->name), op, a->name);
		else
			ft_cod(a->len, op, a->name);
	}
	if (i == 1 && !(a->name[0] == '%' || a->name[0] == ':' ||
		a->name[0] == 'r'))
		ft_printf("%-18s", a->name);
	else if (i == 1 && (a->name[0] == '%' && a->name[1] != ':'))
		ft_printf("%-18d", ft_atoi(&a->name[1]));
	else if (i == 1)
		ft_printf("%-18d", a->len);
}

void	ft_pr_nums(char *name, t_lb *arg)
{
	int		o;
	int		c;
	t_lb	*a;

	a = arg;
	o = ft_op_id(name, NULL, 0);
	c = ft_cotage(name);
	(c == 2) ? ft_printf("\n%20s%-4d%-6d", " ", o, ft_ct(arg, NULL, 0)) :
	ft_printf("\n%20s%-10d", " ", o);
	while (a)
	{
		a->name[0] == 'r' ? ft_reg(&a->name[1]) :
		ft_pr_di(a, 0, name);
		a = a->next;
	}
	(c == 2) ? ft_printf("\n%20s%-4d%-6d", " ", o, ft_ct(arg, NULL, 0)) :
	ft_printf("\n%20s%-10d", " ", o);
	a = arg;
	while (a)
	{
		(a->name[0] == 'r') ? ft_reg(&a->name[1]) :
		ft_pr_di(a, 1, name);
		a = a->next;
	}
	ft_printf("\n\n");
}

void	ft_a_flag(t_lb *lb, char *name, char *com, int num)
{
	int		k;
	t_lb	*l;
	t_lb	*o;
	t_lb	*a;

	l = lb;
	k = 0;
	ft_wr_a(num, name, com);
	while (l)
	{
		if (ft_strcmp(l->name, "\0") != 0)
			(l->op) ? ft_printf("%-4d       :    %s\n", l->op->p, l->name) :
		ft_printf("%-4d       :    %s\n", k, l->name);
		o = l->op;
		while (o)
		{
			a = o->op;
			ft_printf("%-4d (%-3d) :%8s%-10s", o->p, o->len, " ", o->name);
			k = o->p + o->len;
			ft_pr_a(a);
			ft_pr_nums(o->name, o->op);
			o = o->next;
		}
		l = l->next;
	}
}
