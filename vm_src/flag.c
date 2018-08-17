/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:35:34 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 19:35:35 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		no_col(short *tab, short n)
{
	int		i;

	i = -1;
	while (++i < MAX_PLAYERS)
		if (*(tab + i) == n)
			return (0);
	return (1);
}

void	add_fl(short *tab, short n)
{
	int		i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (!*(tab + i))
		{
			*(tab + i) = n;
			return ;
		}
	}
}

int		is_val_n(t_flag *flag, char *str)
{
	short	n;

	n = (short)ft_atoi(str);
	while (!no_col(flag->champs, n) || n < 1 || n > CHAMP_MAX_SIZE)
		n++;
	add_fl(flag->champs, n);
	return (n);
}

int		make_flag2(t_flag *flag, char **argv, int *i)
{
	if (!ft_strcmp(argv[*i], "-d"))
	{
		if (argv[++(*i)])
			flag->d = (unsigned long long)ft_atoi(argv[*i]);
		return (1);
	}
	if (!ft_strcmp(argv[*i], "-s"))
	{
		if (argv[++(*i)])
			flag->s = (unsigned long long)ft_atoi(argv[*i]);
		return (1);
	}
	if (!ft_strcmp(argv[*i], "-v"))
	{
		if (argv[++(*i)])
			flag->v = (char)ft_atoi(argv[*i]);
		return (1);
	}
	return (0);
}

int		make_flag(t_flag *flag, char **argv, int *i, int *j)
{
	if (!ft_strcmp(argv[*i], "-a"))
	{
		flag->a = 1;
		return (1);
	}
	if (!ft_strcmp(argv[*i], "-nc"))
	{
		flag->nc = 1;
		return (1);
	}
	if (!ft_strcmp(argv[*i], "-n"))
	{
		if (argv[++(*i)])
			*j = is_val_n(flag, argv[*i]);
		return (1);
	}
	return (make_flag2(flag, argv, i));
}
