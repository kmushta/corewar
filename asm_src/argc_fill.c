/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:55:50 by oltkache          #+#    #+#             */
/*   Updated: 2018/06/11 16:55:50 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_num(char *arg, char **res, int *j, int i)
{
	unsigned int	num;

	num = (unsigned int)ft_atoi(&arg[i]);
	if (i == 0)
		(*res)[(*j)++] = (char)((num >> 8) & 255);
	(*res)[(*j)++] = (char)(num & 255);
}

int		ft_op_id(char *op, char **res, int *j)
{
	const char	*oper[16] = {"live", "ld", "st", "add", "sub", "and",\
	"or", "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff"};
	int			i;

	i = 0;
	while (oper[i])
	{
		if (ft_strcmp(oper[i], op) == 0)
		{
			++i;
			break ;
		}
		++i;
	}
	if (res && i != 0)
		(*res)[(*j)++] = i;
	return (i);
}

void	ft_dir_n(char *arg, int lb, char **res, int *j)
{
	unsigned int	num;

	num = (unsigned int)ft_atoi(&arg[1]);
	if (lb == 2)
		num = (unsigned short)num;
	if (lb == 4)
		(*res)[(*j)++] = (char)((num >> 24) & 255);
	if (lb == 4)
		(*res)[(*j)++] = (char)((num >> 16) & 255);
	(*res)[(*j)++] = (char)((num >> 8) & 255);
	(*res)[(*j)++] = (char)(num & 255);
}

int		ft_arg_fill(char *op, char *arg, char **res, int *j)
{
	int lb;

	if (arg[0] == 'r')
		ft_num(arg, res, j, 1);
	if (arg[0] == '%')
	{
		lb = ft_lb(op);
		if (arg[1] != ':')
		{
			ft_dir_n(arg, lb, res, j);
			return (0);
		}
		else if (arg[1] == ':')
			return (2);
	}
	if (arg[0] == '-' || (arg[0] >= 48 && arg[0] <= 57))
		ft_num(arg, res, j, 0);
	if (arg[0] == ':')
		return (2);
	return (0);
}

int		ft_ct(t_lb *arg, char **res, int *j)
{
	unsigned char	n[4];
	int				i;

	i = 0;
	while (i < 4)
		n[i++] = 0;
	i = 0;
	while (arg)
	{
		if ((arg->name)[0] == 'r')
			n[i++] = 1;
		else if ((arg->name)[0] == '%')
			n[i++] = 2;
		else
			n[i++] = 3;
		arg = arg->next;
	}
	i = 1;
	while (i < 4)
		n[0] = (n[0] << 2) | n[i++];
	if (res && (char)((n[0] >> 8) & 255) != 0)
		(*res)[(*j)++] = (char)((n[0] >> 8) & 255);
	if (res)
		(*res)[(*j)++] = (char)(n[0] & 255);
	return (n[0]);
}
