/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:39:59 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 19:40:00 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char	*read_str(char *file, t_header **head)
{
	unsigned char	*str;
	int				len;
	int				fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Can't read source file %s\n", file);
		exit(0);
	}
	len = (int)lseek(fd, 0, SEEK_END);
	(*head)->len = len;
	lseek(fd, 0, SEEK_SET);
	str = (unsigned char *)malloc(sizeof(unsigned char) * len + 1);
	read(fd, str, len);
	return (str);
}

void			nc_out(t_header *head, t_base *base)
{
	int		i;

	i = 1;
	while (head)
	{
		if (head->name == base->champ_win)
			break ;
		head = head->next;
		i++;
	}
	mvprintw(34, 196, "The winner is : ");
	attron(COLOR_PAIR(i));
	mvprintw(34, 212, "%s", head->prog_name);
	attroff(COLOR_PAIR(i));
	mvprintw(36, 196, "Press any key to finish");
	nodelay(stdscr, FALSE);
	getch();
	curs_set(TRUE);
	endwin();
}

void			init_base(t_base *base, t_flag *flag, int *n)
{
	if (flag->nc)
	{
		flag->d = 0;
		flag->s = 0;
		flag->v = 0;
		flag->a = 0;
		init_nc(*flag);
		flag->nc = 1;
	}
	base->speed = 50;
	base->go = 0;
	base->champ_win = -(--(*n));
	base->flag = *flag;
	base->cycle_to_die = CYCLE_TO_DIE;
	base->max_check = MAX_CHECKS;
}

int				main(int argc, char **argv)
{
	int			n;
	int			i;
	t_header	*head;
	t_flag		flag;
	t_base		base;

	n = 1;
	head = NULL;
	i = 0;
	bzero(&flag, sizeof(flag));
	while (++i < argc)
		if (!make_flag(&flag, argv, &i, &n) && i < argc)
			pushback(&head, new_champ(argv[i], n++));
	base = battlefield(&head, *argv);
	init_base(&base, &flag, &n);
	if (!base.flag.nc)
		introducing(&head);
	cycle(n, &base, &head);
	if (!base.flag.nc)
		print_win(base, &head);
	else
		nc_out(head, &base);
}
