/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:41:53 by oltkache          #+#    #+#             */
/*   Updated: 2018/06/11 16:41:54 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_skip_com(char *f, int *i)
{
	if (f[*i] && (f[*i] == '#' || f[*i] == ';'))
		while (f[*i] && f[*i] != '\n')
			++(*i);
}

void	ft_skip_nl(char (*f)[], int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((*f)[i])
	{
		if (i == 0)
			while ((*f)[i] == '\n')
				++i;
		if ((*f)[i] == '\n')
			while ((*f)[i + 1] == '\n')
				++i;
		if (!(*f)[i])
			return ;
		(*f)[j++] = (*f)[i++];
	}
	while (j < len)
		(*f)[j++] = '\0';
}

void	ft_cl_file(char (*f)[], int len)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while ((*f)[++i])
	{
		ft_skip_com(*f, &i);
		if (!(*f)[i])
			return ;
		if ((*f)[i] && (*f)[i] == ',')
			(*f)[j++] = ' ';
		else if ((*f)[i])
			(*f)[j++] = (*f)[i];
	}
	while (j < len)
		(*f)[j++] = '\0';
}

void	ft_space(char (*f)[], int len)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while ((*f)[++i])
	{
		while ((*f)[i] != '\n' && ft_isspace((*f)[i]))
			++i;
		if (j > 0 && (*f)[j - 1] != '\n' && i > 0 && ft_isspace((*f)[i - 1]))
			(*f)[j++] = ' ';
		if ((*f)[i] && ((*f)[i] == '\n' || !ft_isspace((*f)[i])))
			(*f)[j++] = (*f)[i];
	}
	while (j < len)
		(*f)[j++] = '\0';
}

int		ft_no_n_c(char file[])
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (file[i])
	{
		if (file[i] == '"')
			++k;
		++i;
		if (k == 4)
			return (i);
	}
	return (0);
}
