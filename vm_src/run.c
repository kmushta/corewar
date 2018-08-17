/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:32:45 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 18:32:46 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	run(t_process *proc, t_base *base,
	t_header **head, t_process **head_proc)
{
	if (proc->func)
	{
		if (proc->cycle > 0)
		{
			proc->cycle--;
			return ;
		}
		proc->byte = (base->battle)[(proc->position + 1) % MEM_SIZE];
		rm_pc(base, proc->position);
		operation(proc, base, head, head_proc);
		run_pc(proc, base);
		add_pc(base, proc->position);
		proc->func = 0;
		proc->cycle = -1;
		return ;
	}
	if ((unsigned)((base->battle)[proc->position] - 1) < 16)
	{
		proc->func = base->battle[proc->position];
		proc->cycle = op_cycle(proc->func) - 2;
		return ;
	}
	rm_pc(base, proc->position);
	proc->position = (proc->position + 1) % MEM_SIZE;
	add_pc(base, proc->position);
}

void	run_process(t_base *base, t_process **head, t_header **header)
{
	t_process	*current;
	int			i;

	i = 0;
	current = *head;
	while (current != NULL)
	{
		i++;
		run(current, base, header, head);
		current->live_cycle++;
		current = current->next;
	}
	if (base->flag.nc)
	{
		mvprintw(8, 209, "          ");
		mvprintw(8, 209, "%d", i);
		refresh();
	}
}
