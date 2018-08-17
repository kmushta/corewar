/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:18:27 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 19:18:28 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_nc(t_flag flag)
{
	if (!flag.nc)
		return ;
	initscr();
	curs_set(FALSE);
	start_color();
	nc_pairs();
}

void	renew(t_base *base)
{
	if (base->go)
		mvprintw(1, 196, "** RUNNING **");
	else
		mvprintw(1, 196, "** PAUSED ** ");
	mvprintw(3, 218, "    ");
	mvprintw(3, 218, "%d", base->speed);
	refresh();
}
