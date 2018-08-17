/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_pc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:29:36 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 18:29:37 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	rm_pc(t_base *base, int pos)
{
	pos %= MEM_SIZE;
	nc_con(base, pos);
	mvprintw(pos / 64, (pos % 64) * 3, "%.2x", (base->battle)[pos]);
	nc_coff(base, pos);
	refresh();
}

void	add_pc(t_base *base, int pos)
{
	pos %= MEM_SIZE;
	if ((base->owner)[pos])
		attron(COLOR_PAIR((base->owner)[pos] + 4));
	else
		attron(COLOR_PAIR(10));
	mvprintw(pos / 64, (pos % 64) * 3, "%.2x", (base->battle)[pos]);
	if ((base->owner)[pos])
		attroff(COLOR_PAIR((base->owner)[pos] + 4));
	else
		attroff(COLOR_PAIR(10));
	move(0, 192);
	refresh();
}

void	init_pcs(t_base *base, t_process **head)
{
	t_process	*current;

	current = *head;
	while (current)
	{
		add_pc(base, current->position);
		current = current->next;
	}
}
