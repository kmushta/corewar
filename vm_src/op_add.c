/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:52:44 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 17:52:47 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_add(t_process *proc, t_base *base, int i)
{
	int				tmp;
	unsigned char	c;

	c = (base->battle)[(i + 1) % MEM_SIZE];
	if (enc_byte(c, 1) != T_REG || enc_byte(c, 2) != T_REG
		|| enc_byte(c, 3) != T_REG ||
		(unsigned)((base->battle)[(i + 2) % MEM_SIZE] - 1) >= REG_NUMBER ||
		(unsigned)((base->battle)[(i + 3) % MEM_SIZE] - 1) >= REG_NUMBER ||
		(unsigned)((base->battle)[(i + 4) % MEM_SIZE] - 1) >= REG_NUMBER)
		return ;
	if ((base->flag.v >> 2) & 1)
		ft_printf("P %4d | add r%d r%d r%d\n", proc->num,
			base->battle[(i + 2) % MEM_SIZE], base->battle[(i + 3) % MEM_SIZE],
			base->battle[(i + 4) % MEM_SIZE]);
	tmp = (proc->reg)[base->battle[(i + 2) % MEM_SIZE] - 1] +
	(proc->reg)[base->battle[(i + 3) % MEM_SIZE] - 1];
	(proc->reg)[base->battle[(i + 4) % MEM_SIZE] - 1] = tmp;
	proc->carry = 0;
	if (!tmp)
		proc->carry = 1;
}
