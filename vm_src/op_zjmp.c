/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:51:51 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 17:51:52 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_zjmp(t_process *proc, t_base *base, int i)
{
	int		tmp;

	tmp = (short)(to_int(base, i + 1, 2));
	if (proc->carry == 1)
	{
		if ((base->flag.v >> 2) & 1)
			ft_printf("P %4d | zjmp %d OK\n", proc->num, tmp);
		tmp %= IDX_MOD;
		proc->position = (proc->position + tmp + MEM_SIZE) % MEM_SIZE;
	}
	else if ((base->flag.v >> 2) & 1)
		ft_printf("P %4d | zjmp %d FAILED\n", proc->num, tmp);
}
