/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:53:07 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 19:53:09 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	operation_part2(t_process *proc, t_base *base, t_process **head_proc)
{
	if (proc->func == 9)
		op_zjmp(proc, base, proc->position);
	else if (proc->func == 10)
		op_ldi(proc, base, proc->position);
	else if (proc->func == 11)
		op_sti(proc, base, proc->position);
	else if (proc->func == 12)
		op_fork(proc, head_proc, base, proc->position);
	else if (proc->func == 13)
		op_lld(proc, base, proc->position);
	else if (proc->func == 14)
		op_lldi(proc, base, proc->position);
	else if (proc->func == 15)
		op_lfork(proc, head_proc, base, proc->position);
	else if (proc->func == 16)
		op_aff(proc, base, proc->position);
}

void	operation(t_process *proc, t_base *base,
	t_header **head, t_process **head_proc)
{
	if (proc->func == 1)
		op_live(head, proc, base, proc->position);
	else if (proc->func == 2)
		op_ld(proc, base, proc->position);
	else if (proc->func == 3)
		op_st(proc, base, proc->position);
	else if (proc->func == 4)
		op_add(proc, base, proc->position);
	else if (proc->func == 5)
		op_sub(proc, base, proc->position);
	else if (proc->func == 6)
		op_and(proc, base, proc->position);
	else if (proc->func == 7)
		op_or(proc, base, proc->position);
	else if (proc->func == 8)
		op_xor(proc, base, proc->position);
	else
		operation_part2(proc, base, head_proc);
}
