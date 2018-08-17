/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:12:35 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 18:12:37 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_1(t_process *proc, t_base *base, int i, int num_reg)
{
	proc->reg[base->battle[i % MEM_SIZE] - 1] = proc->reg[num_reg];
	if ((base->flag.v >> 2) & 1)
		ft_printf("P %4d | st r%d %d\n",
			proc->num, num_reg + 1, base->battle[i % MEM_SIZE]);
}

void	op_st(t_process *proc, t_base *base, int i)
{
	int		arg[2];
	int		num_reg;
	int		pos;

	arg[0] = enc_byte(base->battle[(i + 1) % MEM_SIZE], 1);
	arg[1] = enc_byte(base->battle[(i + 1) % MEM_SIZE], 2);
	if (arg[0] != T_REG)
		return ;
	i += 2;
	num_reg = to_int(base, i % MEM_SIZE, 1) - 1;
	if (num_reg < 0 || num_reg >= REG_NUMBER)
		return ;
	i++;
	if (arg[1] == T_REG &&
		(unsigned)(base->battle[i % MEM_SIZE] - 1) < REG_NUMBER)
		op_1(proc, base, i, num_reg);
	else if (arg[1] == T_IND)
	{
		if ((base->flag.v >> 2) & 1)
			ft_printf("P %4d | st r%d %d\n",
				proc->num, num_reg + 1, (short)(to_int(base, i, 2)));
		pos = proc->position + (short)(to_int(base, i, 2)) % IDX_MOD;
		put_int(base, proc->reg[num_reg], pos % MEM_SIZE, 4);
		set_own(base, proc->col, pos % MEM_SIZE, 4);
	}
}
