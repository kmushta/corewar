/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 20:12:29 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 20:12:30 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	validate_magic(unsigned char *champ, char *argv)
{
	int		magic;
	int		buf;

	magic = 0;
	buf = champ[0] << 24;
	magic |= buf;
	buf = champ[1] << 16;
	magic |= buf;
	buf = champ[2] << 8;
	magic |= buf;
	magic |= champ[3];
	if (magic != COREWAR_EXEC_MAGIC)
	{
		ft_printf("Error: File %s has an invalid header\n", argv);
		exit(0);
	}
}

void	validate_name(unsigned char *champ, t_header *head, char *argv)
{
	int		i;

	i = 4;
	while (champ[i] != '\0' && i < 133)
	{
		head->prog_name[i - 4] = champ[i];
		i++;
	}
	if (i == 133)
	{
		ft_printf("Error: File %s has an invalid header\n", argv);
		exit(0);
	}
	while (i < 133)
	{
		if (champ[i] != '\0')
		{
			ft_printf("Error: File %s has an invalid header\n", argv);
			exit(0);
		}
		i++;
	}
}

void	validate_commit(unsigned char *champ, t_header *head, char *argv)
{
	int		i;

	i = 140;
	while (champ[i] != '\0' && i < 2188)
	{
		head->comment[i - 140] = champ[i];
		i++;
	}
	if (i == 2188)
	{
		ft_printf("Error: File %s has an invalid header\n", argv);
		exit(0);
	}
}

void	validate_prog_size(unsigned char *champ, t_header *head)
{
	unsigned int	size;
	unsigned int	buf;

	size = 0;
	buf = 0;
	buf = champ[136] << 24;
	size |= buf;
	buf = champ[137] << 16;
	size |= buf;
	buf = champ[138] << 8;
	size |= buf;
	size |= champ[139];
	head->prog_size = size;
}

void	validate_champ(unsigned char *champ, t_header *head, char *argv)
{
	validate_magic(champ, argv);
	validate_name(champ, head, argv);
	validate_prog_size(champ, head);
	validate_commit(champ, head, argv);
	validate_prog_size(champ, head);
	if ((unsigned)(head->len - 2192) != head->prog_size)
	{
		ft_printf("Error: File %s has a code size that differ ", argv);
		ft_printf("from what its header says\n");
		exit(0);
	}
}
