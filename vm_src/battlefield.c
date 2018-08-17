/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battlefield.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:26:20 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 19:26:21 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	champ_on_field(unsigned char *champ, t_header *head,
	t_base *base, int numb)
{
	unsigned int	i;

	i = 0;
	if (head->prog_size > CHAMP_MAX_SIZE)
	{
		ft_printf("Error: Champ %s has too large a code (%d bytes > %d bytes)\n"
			, head->prog_name, head->prog_size, CHAMP_MAX_SIZE);
		exit(0);
	}
	while (i < head->prog_size)
	{
		(base->battle)[numb] = champ[2192 + i];
		(base->owner)[numb] = (unsigned char)base->name_proc;
		numb++;
		i++;
	}
}

void	zero_base(t_base *base)
{
	base->name_proc = 1;
	ft_bzero(base->battle, MEM_SIZE);
	ft_bzero(base->owner, MEM_SIZE);
}

int		get_champs_count(t_header **head)
{
	t_header	*current;
	int			count;

	current = *head;
	count = 0;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}

t_base	battlefield(t_header **head, char *name)
{
	t_header	*current;
	int			count;
	int			position;
	t_base		base;

	position = 0;
	zero_base(&base);
	count = get_champs_count(head);
	current = *head;
	if (count > 4 || count == 0)
		exit(print_usage(name));
	champ_on_field(current->full, current, &base, 0);
	current = current->next;
	while (current)
	{
		base.name_proc++;
		position += (MEM_SIZE / count);
		champ_on_field(current->full, current, &base, position);
		current = current->next;
	}
	return (base);
}
