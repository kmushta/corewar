/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:19:19 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 19:19:22 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_win(t_base base, t_header **head)
{
	t_header	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->name == base.champ_win)
			break ;
		tmp = tmp->next;
	}
	ft_printf("Contestant %d, \"%s\", has won !\n",
		-base.champ_win, tmp->prog_name);
}

void	introducing(t_header **head)
{
	t_header *current;

	current = *head;
	ft_printf("Introducing contestants...\n");
	while (current != NULL)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			current->name * -1, current->prog_size,
			current->prog_name, current->comment);
		current = current->next;
	}
}

int		dump_print(t_base base)
{
	int		i;

	i = 0;
	ft_printf("0x0000 : ");
	while (i < MEM_SIZE)
	{
		ft_printf("%.2x ", base.battle[i]);
		i++;
		if (i % 64 == 0 && i < MEM_SIZE)
			ft_printf("\n%#.4x : ", i);
	}
	ft_printf("\n");
	return (0);
}

int		print_usage(char *name)
{
	ft_printf("Usage: %s [-d N -s N -v N -n N | -nc] [-a] ", name);
	ft_printf("<champion1.cor> <...>\n");
	ft_printf("    -a        : Prints output from \"aff\"");
	ft_printf(" (Default is to hide it)\n");
	ft_printf("#### TEXT OUTPUT MODE ######################");
	ft_printf("####################################\n");
	ft_printf("    -d N      : Dumps memory after N cycles then exits\n");
	ft_printf("    -s N      : Runs N cycles, dumps memory, pauses");
	ft_printf(", then repeats\n");
	ft_printf("    -v N      : Verbosity levels, can be added together ");
	ft_printf("to enable several\n");
	ft_printf("                - 0 : Show only essentials\n");
	ft_printf("                - 1 : Show lives\n");
	ft_printf("                - 2 : Show cycles\n");
	ft_printf("                - 4 : Show operations");
	ft_printf(" (Params are NOT litteral ...)\n");
	ft_printf("                - 8 : Show deaths\n");
	ft_printf("                - 16 : Show PC movements (Except for jumps)\n");
	ft_printf("#### NCURSES OUTPUT MODE ####################");
	ft_printf("###################################\n");
	ft_printf("    -nc       : Ncurses output mode\n");
	ft_printf("##############################################");
	ft_printf("###################################\n");
	return (0);
}
