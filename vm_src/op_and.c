/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:02:55 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 18:02:56 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		first_op(int *i, t_base *base, t_process *proc, int *arg)
{
	int first;

	first = 0;
	if (arg[0] == T_REG &&
		(unsigned)(base->battle[*i % MEM_SIZE] - 1) < REG_NUMBER)
	{
		first = proc->reg[base->battle[*i % MEM_SIZE] - 1];
		(*i)++;
	}
	else if (arg[0] == T_DIR)
	{
		first = to_int(base, *i % MEM_SIZE, 4);
		*i += 4;
	}
	else if (arg[0] == T_IND)
	{
		first = (short)to_int(base, *i % MEM_SIZE, 2);
		first = to_int(base, (proc->position + first) % MEM_SIZE, 4);
		*i += 2;
	}
	return (first);
}

int		second_op(int *i, t_base *base, t_process *proc, int *arg)
{
	int second;

	second = 0;
	if (arg[1] == T_REG &&
		(unsigned)(base->battle[*i % MEM_SIZE] - 1) < REG_NUMBER)
	{
		second = proc->reg[base->battle[*i % MEM_SIZE] - 1];
		(*i)++;
	}
	else if (arg[1] == T_DIR)
	{
		second = to_int(base, *i % MEM_SIZE, 4);
		*i += 4;
	}
	else if (arg[1] == T_IND)
	{
		second = (short)to_int(base, *i % MEM_SIZE, 2);
		second = to_int(base, (proc->position + second) % MEM_SIZE, 4);
		*i += 2;
	}
	return (second);
}

void	arg_op(int *arg, t_base *base, int i)
{
	arg[0] = enc_byte(base->battle[(i + 1) % MEM_SIZE], 1);
	arg[1] = enc_byte(base->battle[(i + 1) % MEM_SIZE], 2);
	arg[2] = enc_byte(base->battle[(i + 1) % MEM_SIZE], 3);
}

void	in_reg(t_base *base, t_process *proc, int i, int num)
{
	proc->reg[base->battle[i % MEM_SIZE] - 1] = num;
	proc->carry = 0;
	if (proc->reg[base->battle[i % MEM_SIZE] - 1] == 0)
		proc->carry = 1;
}

void	op_and(t_process *proc, t_base *base, int i)
{
	int		first;
	int		second;
	int		arg[3];

	arg_op(arg, base, i);
	if (arg[2] == T_REG)
	{
		i += 2;
		if (!(arg[0] == T_REG &&
			(unsigned)(base->battle[i % MEM_SIZE] - 1) < REG_NUMBER) &&
			!(arg[0] == T_DIR) && !(arg[0] == T_IND))
			return ;
		first = first_op(&i, base, proc, arg);
		if (!(arg[1] == T_REG &&
			(unsigned)(base->battle[i % MEM_SIZE] - 1) < REG_NUMBER) &&
			!(arg[1] == T_DIR) && !(arg[1] == T_IND))
			return ;
		second = second_op(&i, base, proc, arg);
		if ((unsigned)(base->battle[i % MEM_SIZE] - 1) >= REG_NUMBER)
			return ;
		if ((base->flag.v >> 2) & 1)
			ft_printf("P %4d | and %d %d r%d\n", proc->num,
				first, second, base->battle[i % MEM_SIZE]);
		in_reg(base, proc, i, first & second);
	}
}
