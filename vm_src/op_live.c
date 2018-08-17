/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:01:41 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 18:01:43 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_live(t_base *base, t_header *current, int j, int n)
{
	if (base->flag.v & 1)
		ft_printf("Player %d (%s) is said to be alive\n",
			-n, current->prog_name);
	if (base->flag.nc)
	{
		current->lives += 1;
		mvprintw(7 + 4 * j, 222, "%7d", base->cycle);
		mvprintw(8 + 4 * j, 222, "%7d", current->lives);
		refresh();
	}
}

void	op_live(t_header **head, t_process *proc, t_base *base, int i)
{
	t_header	*current;
	int			n;
	int			j;

	current = *head;
	proc->live++;
	proc->stay = 1;
	proc->live_cycle = 0;
	n = to_int(base, i + 1, 4);
	if ((base->flag.v >> 2) & 1)
		ft_printf("P %4d | live %d\n", proc->num, n);
	j = 1;
	while (current != NULL)
	{
		if (n == current->name)
		{
			base->champ_win = n;
			print_live(base, current, j, n);
		}
		j++;
		current = current->next;
	}
}
