/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:00:01 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 18:00:03 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lldi_carry(t_process *proc, int tmp)
{
	proc->carry = 0;
	if (!tmp)
		proc->carry = 1;
}

void	op_lldi_print(t_drop *tmp, int val1, int val2, int pos)
{
	if ((tmp->base->flag.v >> 2) & 1)
	{
		ft_printf("P %4d | lldi %d %d r%d\n", tmp->proc->num, val1, val2,
			(tmp->base->battle)[pos % MEM_SIZE]);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
			val1, val2, val1 + val2,
			tmp->proc->position + (val1 + val2) % IDX_MOD);
	}
}

void	op_lldi(t_process *proc, t_base *base, int i)
{
	int		t[3];
	int		arg[3];
	t_drop	tmp;

	tmp.base = base;
	tmp.proc = proc;
	if (!op_ldi_arg1(&tmp, arg, &(t[0])))
		return ;
	if (((t[2] = i + 3) + 1) && arg[0] > T_REG)
		t[2]++;
	if (!op_ldi_arg2(&tmp, arg, t[2], &(t[1])))
		return ;
	if (((t[2] = t[2] + 1) + 1) && arg[1] == T_DIR)
		t[2]++;
	if ((unsigned)((base->battle)[t[2] % MEM_SIZE] - 1) >= REG_NUMBER)
		return ;
	op_lldi_print(&tmp, t[0], t[1], t[2]);
	(proc->reg)[(base->battle)[t[2] % MEM_SIZE] - 1] =
	to_int(base, i + t[0] + t[1], 4);
	op_lldi_carry(proc, (proc->reg)[(base->battle)[t[2] % MEM_SIZE] - 1]);
}
