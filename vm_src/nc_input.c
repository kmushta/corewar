/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:18:15 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/12 18:18:16 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ref_nc(t_base *base)
{
	if (base->speed < 2)
		base->speed = 2;
	else if (base->speed > 1000)
		base->speed = 1000;
	renew(base);
}

void	red_speed1(t_base *base)
{
	char	c;

	c = (char)getch();
	if (c == ' ')
	{
		base->go = 0;
		renew(base);
		return ;
	}
	if (c == 'w')
		base->speed -= 1;
	else if (c == 'q')
		base->speed -= 10;
	else if (c == 'e')
		base->speed += 1;
	else if (c == 'r')
		base->speed += 10;
	ref_nc(base);
}

void	red_speed2(t_base *base)
{
	char	c;

	nodelay(stdscr, FALSE);
	while ((c = (char)getch()))
	{
		if (c == ' ')
		{
			base->go = 1;
			nodelay(stdscr, TRUE);
			renew(base);
			return ;
		}
		else if (c == 'q')
			base->speed -= 10;
		else if (c == 'w')
			base->speed -= 1;
		else if (c == 'e')
			base->speed += 1;
		else if (c == 'r')
			base->speed += 10;
		else if (c == 's')
			return ;
		ref_nc(base);
	}
}

void	red_speed(t_base *base)
{
	if (base->go)
		red_speed1(base);
	else
		red_speed2(base);
}
