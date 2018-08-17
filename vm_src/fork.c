/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 20:18:20 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 20:18:21 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		rewrite_reg(t_process *proc, t_process *new_proc)
{
	int		i;

	i = -1;
	while (++i < REG_NUMBER)
		new_proc->reg[i] = proc->reg[i];
}

t_process	*fork_proc(int position, t_process *proc, t_base *base)
{
	t_process *new_process;

	new_process = (t_process*)malloc(sizeof(t_process));
	new_process->carry = proc->carry;
	rewrite_reg(proc, new_process);
	new_process->live = 0;
	new_process->stay = 0;
	new_process->stay = proc->stay;
	new_process->position = position;
	new_process->cycle = -1;
	new_process->func = 0;
	new_process->name = proc->name;
	new_process->next = NULL;
	new_process->num = ++base->processes;
	new_process->col = proc->col;
	new_process->live_cycle = proc->live_cycle + 1;
	return (new_process);
}
