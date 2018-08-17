/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:49:58 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 19:49:59 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_move(t_base *base, int pos, int shift)
{
	int		i;

	if ((base->flag.v >> 4) & 1)
	{
		ft_printf("ADV %d (0x%.4x -> 0x%.4x) ", shift, pos, pos + shift);
		i = -1;
		while (++i < shift)
			ft_printf("%.2x ", (base->battle)[(pos + i) % MEM_SIZE]);
		ft_printf("\n");
	}
}

int		run_pc2(t_process *proc, int label)
{
	int				shift;
	int				i;
	unsigned char	c;

	shift = 2;
	i = 0;
	while (++i < 4)
	{
		c = enc_byte(proc->byte, i);
		if ((proc->func == 3 || proc->func == 2) && i > 2)
			break ;
		if (proc->func == 16 && i > 1)
			break ;
		if (c == T_REG)
			shift++;
		else if (c == T_DIR)
			shift += label;
		else if (c == T_IND)
			shift += 2;
		else if (proc->func == 3 || proc->func == 16)
			break ;
	}
	return (shift);
}

void	run_pc(t_process *proc, t_base *base)
{
	int				label;
	int				shift;

	if (proc->func == 9 && proc->carry == 1)
		return ;
	label = 4;
	if (proc->func > 8 && proc->func < 16 && proc->func != 13)
		label = 2;
	if (proc->func == 1 || proc->func == 9
		|| proc->func == 12 || proc->func == 15)
	{
		print_move(base, proc->position, label + 1);
		proc->position = (proc->position + label + 1) % MEM_SIZE;
		return ;
	}
	shift = run_pc2(proc, label);
	print_move(base, proc->position, shift);
	proc->position = (proc->position + shift) % MEM_SIZE;
}

int		op_cycle(int i)
{
	if (i == 1 || i == 4 || i == 5 || i == 13)
		return (10);
	if (i == 2 || i == 3)
		return (5);
	if (i == 6 || i == 7 || i == 8)
		return (6);
	if (i == 9)
		return (20);
	if (i == 10 || i == 11)
		return (25);
	if (i == 12)
		return (800);
	if (i == 14)
		return (50);
	if (i == 15)
		return (1000);
	return (2);
}
