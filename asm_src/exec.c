/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:56:40 by oltkache          #+#    #+#             */
/*   Updated: 2018/06/14 16:16:50 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_ch_lab(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			break ;
		++i;
	}
	if (!(str1[i] == '\0' && str2[i] == ':'))
		return (0);
	return (1);
}

int		ft_ind(t_d d, char *name)
{
	int		num;
	t_lb	*a;
	t_lb	*o;

	num = 0;
	while (d.h)
	{
		if (ft_ch_lab(name, (d.h)->name))
			return (d.incr + num);
		o = (d.h)->op;
		while (o)
		{
			a = o->op;
			num += ft_cotage(o->name);
			while (a)
			{
				num += ft_args_len(a->name, o->name);
				a = a->next;
			}
			o = o->next;
		}
		d.h = (d.h)->next;
	}
	return (0);
}

int		ft_dir_lb(t_d d, char **res, int *j)
{
	int				n;
	unsigned int	num;
	char			*name;

	num = 0;
	if (d.name[0] == ':')
		name = ft_strdup(&(d.name[1]));
	else
		name = ft_strdup(&(d.name[2]));
	n = ft_ind(d, name);
	num = (unsigned int)n;
	if (d.len == 2)
	{
		n = (short)n;
		num = (unsigned short)n;
	}
	if (d.len == 4)
		(*res)[(*j)++] = (char)((num >> 24) & 255);
	if (d.len == 4)
		(*res)[(*j)++] = (char)((num >> 16) & 255);
	(*res)[(*j)++] = (char)((num >> 8) & 255);
	(*res)[(*j)++] = (char)(num & 255);
	ft_strdel(&name);
	return (n);
}

void	ft_ex(t_d *d, char **ex, t_lb *arg, int *i)
{
	int lb;

	if (ft_cotage(d->op) == 2)
		ft_ct(arg, ex, i);
	d->i += ft_cotage(d->op);
	++d->j;
	while (arg)
	{
		if (ft_arg_fill(d->op, arg->name, ex, i) == 2)
		{
			if ((arg->name)[0] == ':' || ((arg->name)[0] == '%'
				&& (arg->name)[1] == ':'))
			{
				lb = ft_lb(d->op);
				if ((arg->name)[0] == ':')
					lb = 2;
				d->name = arg->name;
				d->len = lb;
				arg->len = ft_dir_lb(*d, ex, i);
			}
		}
		d->i += ft_args_len(arg->name, d->op);
		arg = arg->next;
	}
}

void	ft_exec(char **ex, t_lb *l)
{
	t_d		d;
	int		i;
	t_lb	*op;
	t_lb	*arg;

	i = 0;
	d.h = l;
	d.incr = 0;
	while (l)
	{
		op = l->op;
		d.j = 0;
		d.l = l;
		while (op)
		{
			d.i = 0;
			ft_op_id(op->name, ex, &i);
			arg = op->op;
			d.op = op->name;
			ft_ex(&d, ex, arg, &i);
			d.incr -= d.i;
			op = op->next;
		}
		l = l->next;
	}
}
