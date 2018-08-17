/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_t_cor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:41:12 by oltkache          #+#    #+#             */
/*   Updated: 2018/06/11 16:41:13 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_zero(char (*tmp)[], int len)
{
	int i;

	i = 0;
	while (i <= len)
		(*tmp)[i++] = '\0';
}

void	ft_magic(t_cor *c)
{
	ft_zero(&(c->magic), 4);
	c->magic[3] = (char)(COREWAR_EXEC_MAGIC & 255);
	c->magic[2] = (char)((COREWAR_EXEC_MAGIC >> 8) & 255);
	c->magic[1] = (char)((COREWAR_EXEC_MAGIC >> 16) & 255);
	c->magic[0] = (char)((COREWAR_EXEC_MAGIC >> 24) & 255);
}

void	ft_name(char *c, char (*name)[], int len)
{
	int				i;

	i = -1;
	ft_zero(name, len);
	while (c[++i])
		(*name)[i] = c[i];
}

void	ft_str(char **str, char *tmp)
{
	int i;
	int j;
	int len;

	if (!tmp)
		return ;
	i = 0;
	j = 0;
	len = 0;
	i = 0;
	while (tmp[i] != '"')
		++i;
	len = 0;
	j = 0;
	while (tmp[++i] != '"')
		++len;
	i -= len;
	*str = (char*)malloc(sizeof(char) * (len + 1));
	(*str)[len] = '\0';
	while (tmp[i] != '"')
		(*str)[j++] = tmp[i++];
}

void	ft_get_n_c(char file[], t_cor *c)
{
	char *tmp;

	tmp = ft_strstr(file, NAME_CMD_STRING);
	if (tmp)
	{
		ft_str(&(c->f_n), tmp);
		tmp = ft_strstr(tmp, COMMENT_CMD_STRING);
		ft_str(&(c->f_c), tmp);
		return ;
	}
	tmp = ft_strstr(file, COMMENT_CMD_STRING);
	ft_str(&(c->f_c), tmp);
	tmp = ft_strstr(tmp, NAME_CMD_STRING);
	ft_str(&(c->f_n), tmp);
}
