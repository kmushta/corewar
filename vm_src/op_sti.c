/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:14:17 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 18:14:18 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		first_sti(int *i, t_base *base, t_process *proc, int *arg)
{
	int		first;
	int		pos;

	first = 0;
	if (arg[1] == T_REG &&
		(unsigned)(base->battle[*i % MEM_SIZE] - 1) < REG_NUMBER)
	{
		first = proc->reg[base->battle[*i % MEM_SIZE] - 1];
		(*i)++;
	}
	else if (arg[1] == T_DIR)
	{
		first = (short)to_int(base, *i, 2);
		*i += 2;
	}
	else if (arg[1] == T_IND)
	{
		pos = (short)(to_int(base, *i, 2)) % IDX_MOD + proc->position;
		first = to_int(base, pos % MEM_SIZE, 4);
		*i += 2;
	}
	return (first);
}

int		op_sti_init(t_base *base, int *i, int *num_reg, int *arg)
{
	arg[0] = enc_byte(base->battle[(*i + 1) % MEM_SIZE], 1);
	arg[1] = enc_byte(base->battle[(*i + 1) % MEM_SIZE], 2);
	arg[2] = enc_byte(base->battle[(*i + 1) % MEM_SIZE], 3);
	if (arg[0] != T_REG || (*num_reg =
		(unsigned)to_int(base, (*i + 2) % MEM_SIZE, 1) - 1) >= REG_NUMBER)
		return (0);
	*i += 3;
	if (!(arg[1] == T_REG &&
		(unsigned)(base->battle[*i % MEM_SIZE] - 1) < REG_NUMBER) &&
		!(arg[1] == T_DIR) && !(arg[1] == T_IND))
		return (0);
	return (1);
}

void	op_sti(t_process *proc, t_base *base, int i)
{
	int		arg[3];
	int		num_reg;
	int		f;
	int		s;

	if (!op_sti_init(base, &i, &num_reg, arg))
		return ;
	f = first_sti(&i, base, proc, arg);
	if (arg[2] == T_REG &&
		(unsigned)(base->battle[i % MEM_SIZE] - 1) < REG_NUMBER)
		s = proc->reg[base->battle[i % MEM_SIZE] - 1];
	else if (arg[2] == T_DIR)
		s = (short)to_int(base, i, 2);
	else
		return ;
	if ((base->flag.v >> 2) & 1)
	{
		ft_printf("P %4d | sti r%d %d %d\n", proc->num, num_reg + 1, f, s);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
f, s, f + s, proc->position + (f + s) % IDX_MOD);
	}
	put_int(base, proc->reg[num_reg],
		(proc->position + (f + s) % IDX_MOD) % MEM_SIZE, 4);
	set_own(base, proc->col,
		(proc->position + (f + s) % IDX_MOD) % MEM_SIZE, 4);
}
