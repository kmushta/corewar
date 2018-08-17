/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:15:53 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 19:15:55 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cycle_flags(t_base *base, t_header *header, t_process *head)
{
	if (base->flag.nc)
	{
		nc_draw(base, header);
		init_pcs(base, &head);
	}
}

void	cycle_flags2(t_base *base)
{
	if (base->flag.nc)
		red_speed(base);
	if (base->flag.nc)
	{
		mvprintw(6, 204, "%llu", base->cycle);
		refresh();
	}
	if ((base->flag.v >> 1) & 1)
		ft_printf("It is now cycle %d\n", base->cycle);
}

void	cycle_flags3(t_base *base)
{
	char	*line;

	if (base->flag.s)
	{
		if (!(base->cycle % base->flag.s))
		{
			dump_print(*base);
			if (get_next_line(0, &line) == 1)
				free(line);
		}
	}
	if (base->go && base->flag.nc)
		usleep((useconds_t)((int)1000000 / base->speed));
}

void	cycle(int num_champ, t_base *base, t_header **header)
{
	t_process	*head;
	int			j;

	j = 0;
	head = 0;
	start_position(&head, header, num_champ, base);
	cycle_flags(base, *header, head);
	base->cycle = 1;
	nodelay(stdscr, TRUE);
	while (head && (!base->flag.d || (base->cycle - 1) < base->flag.d))
	{
		cycle_flags2(base);
		run_process(base, &head, header);
		if (++j == base->cycle_to_die || base->cycle_to_die < 1)
		{
			j = 0;
			cycle_die(&head, base, *header);
		}
		(base->cycle)++;
		cycle_flags3(base);
	}
	if (base->flag.d && head)
		exit(dump_print(*base));
}
