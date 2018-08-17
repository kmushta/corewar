/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:55:01 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 17:55:02 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_ld_carry(t_process *proc, int tmp)
{
	proc->carry = 0;
	if (!tmp)
		proc->carry = 1;
}

void	op_ld(t_process *proc, t_base *base, int i)
{
	int		tmp;

	if (enc_byte((base->battle)[(i + 1) % MEM_SIZE], 2) != T_REG)
		return ;
	if (enc_byte((base->battle)[(i + 1) % MEM_SIZE], 1) == T_DIR &&
		(unsigned)((base->battle)[(i + 6) % MEM_SIZE] - 1) < REG_NUMBER)
	{
		tmp = to_int(base, i + 2, 4);
		(proc->reg)[base->battle[(i + 6) % MEM_SIZE] - 1] = tmp;
		op_ld_carry(proc, tmp);
		if ((base->flag.v >> 2) & 1)
			ft_printf("P %4d | ld %d r%d\n", proc->num, tmp,
				base->battle[(i + 6) % MEM_SIZE]);
	}
	else if (enc_byte((base->battle)[(i + 1) % MEM_SIZE], 1) == T_IND
		&& (unsigned)((base->battle)[(i + 4) % MEM_SIZE] - 1) < REG_NUMBER)
	{
		tmp = to_int(base, i + (short)(to_int(base, i + 2, 2)) % IDX_MOD, 4);
		(proc->reg)[(base->battle)[(i + 4) % MEM_SIZE] - 1] = tmp;
		op_ld_carry(proc, tmp);
		if ((base->flag.v >> 2) & 1)
			ft_printf("P %4d | ld %d r%d\n", proc->num, tmp,
				base->battle[(i + 4) % MEM_SIZE]);
	}
}
