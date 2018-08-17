/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 20:18:01 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 20:18:02 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_fork(t_process *proc, t_process **head_proc, t_base *base, int i)
{
	int		pc;

	pc = (short)(to_int(base, (i + 1) % MEM_SIZE, 2));
	if ((base->flag.v >> 2) & 1)
		ft_printf("P %4d | fork %d (%d)\n", proc->num, pc, proc->position
			+ pc % IDX_MOD);
	pc = proc->position + pc % IDX_MOD;
	while (pc < 0)
		pc += MEM_SIZE;
	pushback_proc(head_proc, fork_proc((pc % MEM_SIZE), proc, base));
}
