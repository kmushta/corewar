/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:50:30 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 17:50:32 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_aff(t_process *proc, t_base *base, int i)
{
	char	c;

	if (base->flag.a && (unsigned)((base->battle)[(i + 2) % MEM_SIZE] - 1)
		< REG_NUMBER && enc_byte(proc->byte, 1))
	{
		c = (proc->reg)[(base->battle)[(i + 2) % MEM_SIZE] - 1];
		c %= 256;
		ft_putstr("Aff: ");
		write(1, &c, 1);
		ft_putstr("\n");
	}
}
