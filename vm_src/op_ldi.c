/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:58:16 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 17:58:18 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		op_ldi_arg1(t_drop *tmp, int *arg, int *val)
{
	arg[0] = enc_byte((tmp->base->battle)[(tmp->proc->position + 1)
		% MEM_SIZE], 1);
	arg[1] = enc_byte((tmp->base->battle)[(tmp->proc->position + 1)
		% MEM_SIZE], 2);
	arg[2] = enc_byte((tmp->base->battle)[(tmp->proc->position + 1)
		% MEM_SIZE], 3);
	if (!arg[0] || !(arg[1] == T_REG || arg[1] == T_DIR) || arg[2] != T_REG)
		return (0);
	if (arg[0] == T_REG)
	{
		if ((unsigned)((tmp->base->battle)[(tmp->proc->position + 2)
			% MEM_SIZE] - 1)
			>= REG_NUMBER)
			return (0);
		*val = (tmp->proc->reg)[tmp->base->battle[(tmp->proc->position + 2)
			% MEM_SIZE] - 1];
	}
	else if (arg[0] == T_DIR)
		*val = (short)to_int(tmp->base, tmp->proc->position + 2, 2);
	else
		*val = to_int(tmp->base, tmp->proc->position + (short)
			(to_int(tmp->base, tmp->proc->position + 2, 2)) % IDX_MOD, 4);
	return (1);
}

int		op_ldi_arg2(t_drop *tmp, int *arg, int i, int *val)
{
	if (arg[1] == T_REG)
	{
		if ((unsigned)((tmp->base->battle)[i % MEM_SIZE] - 1) >= REG_NUMBER)
			return (0);
		*val = (tmp->proc->reg)[tmp->base->battle[i % MEM_SIZE] - 1];
	}
	else
		*val = (short)to_int(tmp->base, i, 2);
	return (1);
}

void	op_ldi(t_process *proc, t_base *base, int i)
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
	if ((base->flag.v >> 2) & 1)
	{
		ft_printf("P %4d | ldi %d %d r%d\n", proc->num, t[0], t[1],
			(base->battle)[t[2] % MEM_SIZE]);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
			t[0], t[1], t[0] + t[1], proc->position + (t[0] + t[1]) % IDX_MOD);
	}
	(proc->reg)[(base->battle)[t[2] % MEM_SIZE] - 1] =
	to_int(base, i + (t[0] + t[1]) % IDX_MOD, 4);
}
