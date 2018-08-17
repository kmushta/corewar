/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 20:10:07 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 20:10:08 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_process	*new_process(int position, int name, int num)
{
	t_process	*new_process;

	new_process = (t_process*)malloc(sizeof(t_process));
	new_process->carry = 0;
	ft_bzero(new_process->reg, sizeof(int) * REG_NUMBER);
	new_process->reg[0] = -name;
	new_process->live = 0;
	new_process->stay = 0;
	new_process->position = position;
	new_process->cycle = -1;
	new_process->func = 0;
	new_process->name = name;
	new_process->next = NULL;
	new_process->num = num;
	new_process->col = num;
	return (new_process);
}

void		pushback_proc(t_process **head, t_process *new)
{
	new->next = *head;
	*head = new;
}

void		start_position(t_process **head, t_header **header_champ,
	int number_champ, t_base *base)
{
	int			position;
	int			i;
	t_header	*current;

	position = 0;
	i = 0;
	current = *header_champ;
	pushback_proc(head, new_process(position, -current->name, ++i));
	current = current->next;
	while (current)
	{
		position += (MEM_SIZE / number_champ);
		pushback_proc(head, new_process(position, -current->name, ++i));
		current = current->next;
	}
	base->processes = i;
}
