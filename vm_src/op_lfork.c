/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 20:20:04 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 20:20:05 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lfork(t_process *proc, t_process **head_proc, t_base *base, int i)
{
	int		pc;

	pc = (short)to_int(base, (i + 1) % MEM_SIZE, 2);
	if ((base->flag.v >> 2) & 1)
		ft_printf("P %4d | lfork %d (%d)\n", proc->num, pc,
			proc->position + pc);
	pc += proc->position;
	while (pc < 0)
		pc += MEM_SIZE;
	pushback_proc(head_proc, fork_proc((pc % MEM_SIZE), proc, base));
}
