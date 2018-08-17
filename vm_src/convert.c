/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:34:02 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 19:34:03 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char	enc_byte(unsigned char enc, char arg_num)
{
	enc = enc << ((arg_num - 1) << 1);
	enc = enc >> 6;
	if (enc == 1)
		return (T_REG);
	if (enc == 2)
		return (T_DIR);
	if (enc == 3)
		return (T_IND);
	return (0);
}

int				to_int(t_base *base, int pos, int size)
{
	int		result;
	int		i;

	result = 0;
	i = -1;
	while (pos < 0)
		pos += MEM_SIZE;
	pos %= MEM_SIZE;
	while (++i < size)
		result = (result << 8) + base->battle[(pos + i) % MEM_SIZE];
	return (result);
}

void			put_int(t_base *base, int num, int pos, int size)
{
	while (pos < 0)
		pos += MEM_SIZE;
	pos %= MEM_SIZE;
	while (size--)
	{
		base->battle[(pos + size) % MEM_SIZE] = (unsigned char)num;
		num = num >> 8;
	}
}

void			set_own(t_base *base, unsigned char own, int pos, int size)
{
	int		i;
	int		new;
	int		owner;

	if (!base->flag.nc)
		return ;
	new = size;
	while (pos < 0)
		pos += MEM_SIZE;
	pos %= MEM_SIZE;
	while (new--)
		base->owner[(pos + new) % MEM_SIZE] = own;
	i = -1;
	while (++i < size)
	{
		owner = (base->owner)[(pos + i) % MEM_SIZE];
		attron(COLOR_PAIR(owner));
		mvprintw(((pos + i) % MEM_SIZE) / 64, (((pos + i) % MEM_SIZE) % 64) * 3,
			"%.2x ", (base->battle)[(pos + i) % MEM_SIZE]);
		attroff(COLOR_PAIR(owner));
	}
	move(0, 192);
}
