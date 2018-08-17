/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:24:11 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 18:24:12 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	nc_con(t_base *base, int i)
{
	if ((base->owner)[i])
		attron(COLOR_PAIR((base->owner)[i]));
	else
		attron(COLOR_PAIR(9));
}

void	nc_coff(t_base *base, int i)
{
	if ((base->owner)[i])
		attroff(COLOR_PAIR((base->owner)[i]));
	else
		attroff(COLOR_PAIR(9));
}

void	nc_pairs(void)
{
	init_color(COLOR_CYAN, 500, 500, 500);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_WHITE);
	init_pair(6, COLOR_BLUE, COLOR_WHITE);
	init_pair(7, COLOR_RED, COLOR_WHITE);
	init_pair(8, COLOR_MAGENTA, COLOR_WHITE);
	init_pair(9, COLOR_CYAN, COLOR_BLACK);
	init_pair(10, COLOR_CYAN, COLOR_WHITE);
}

void	nc_print_std(void)
{
	mvprintw(26, 196, "CYCLE_TO_DIE : %d", CYCLE_TO_DIE);
	mvprintw(28, 196, "CYCLE_DELTA : %d", CYCLE_DELTA);
	mvprintw(30, 196, "NBR_LIVE : %d", NBR_LIVE);
	mvprintw(32, 196, "MAX_CHECKS : %d", MAX_CHECKS);
	refresh();
}

void	nc_draw(t_base *base, t_header *header)
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		nc_con(base, i);
		mvprintw(i / 64, (i % 64) * 3, "%.2x ", (base->battle)[i]);
		nc_coff(base, i);
	}
	mvprintw(1, 196, "** PAUSED **");
	mvprintw(3, 196, "Cycles/second limit : %d", base->speed);
	mvprintw(6, 196, "Cycle : ");
	mvprintw(8, 196, "Processes : ");
	i = 0;
	while (header && ++i)
	{
		mvprintw(6 + i * 4, 196, "Player %4d : ", header->name);
		attron(COLOR_PAIR(i));
		mvprintw(6 + i * 4, 210, "%s", header->prog_name);
		attroff(COLOR_PAIR(i));
		mvprintw(7 + i * 4, 196, "Last live :                     0");
		mvprintw(8 + i * 4, 196, "Lives in current period :       0");
		header = header->next;
	}
	nc_print_std();
}
