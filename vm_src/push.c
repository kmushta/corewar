/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 20:15:57 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 20:15:58 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_header	*new_champ(char *argv, int i)
{
	t_header	*new;

	new = (t_header*)malloc(sizeof(t_header));
	new->full = read_str(argv, &new);
	validate_champ(new->full, new, argv);
	new->name = i * -1;
	new->lives = 0;
	new->next = NULL;
	return (new);
}

void		pushback(t_header **head, t_header *new)
{
	t_header	*current;

	current = *head;
	if (*head != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	else
		*head = new;
}
