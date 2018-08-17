/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:29:57 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 19:29:58 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		counting_lives(t_process **head)
{
	int			count;
	t_process	*current;

	count = 0;
	current = *head;
	while (current != NULL)
	{
		count += current->live;
		current = current->next;
	}
	return (count);
}

void	kill_you2(t_process **head, t_base *base)
{
	t_process	*start;
	t_process	*tmp;

	tmp = (*head);
	while (tmp != NULL)
	{
		start = tmp;
		tmp = tmp->next;
		if (tmp != NULL && (tmp->stay == 0 || base->cycle_to_die < 1))
		{
			if ((base->flag.v >> 3) & 1)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					tmp->num, tmp->live_cycle - 1, base->cycle_to_die);
			rm_pc(base, tmp->position);
			start->next = tmp->next;
			free(tmp);
			tmp = start;
		}
	}
}

void	kill_you(t_process **head, t_base *base)
{
	t_process	*start;

	while (*head != NULL && ((*head)->stay == 0 || base->cycle_to_die < 1))
	{
		if ((base->flag.v >> 3) & 1)
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				(*head)->num, (*head)->live_cycle - 1, base->cycle_to_die);
		rm_pc(base, (*head)->position);
		start = (*head)->next;
		free(*head);
		*head = start;
	}
	kill_you2(head, base);
}

void	set_to_zero(t_process **head)
{
	t_process	*current;

	current = *head;
	while (current != NULL)
	{
		current->live = 0;
		current->stay = 0;
		current = current->next;
	}
}

void	cycle_die(t_process **head, t_base *base, t_header *header)
{
	int		j;

	kill_you(head, base);
	if (counting_lives(head) >= NBR_LIVE || base->max_check == 0)
	{
		base->cycle_to_die = base->cycle_to_die - CYCLE_DELTA;
		if ((base->flag.v >> 1) & 1)
			ft_printf("Cycle to die is now %d\n", base->cycle_to_die);
		base->max_check = MAX_CHECKS;
		j = 1;
		if (base->flag.nc)
			mvprintw(26, 211, "%d        ", base->cycle_to_die);
		while (header)
		{
			header->lives = 0;
			mvprintw(8 + 4 * j, 222, "%7d", header->lives);
			header = header->next;
			j++;
		}
		refresh();
	}
	base->max_check--;
	set_to_zero(head);
}
