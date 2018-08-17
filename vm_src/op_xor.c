/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:09:47 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 18:09:48 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_xor(t_process *proc, t_base *base, int i)
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
			ft_printf("P %4d | xor %d %d r%d\n", proc->num,
				first, second, base->battle[i % MEM_SIZE]);
		in_reg(base, proc, i, first ^ second);
	}
}
