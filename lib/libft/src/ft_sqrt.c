/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:50:24 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/23 16:50:25 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int	current;
	int	min;
	int	max;
	int	tmp;

	min = 0;
	max = nb;
	if (max > 46340)
		max = 46340;
	while (max - min > 1)
	{
		current = (min + max) / 2;
		tmp = current * current;
		if (tmp == nb)
			return (current);
		if (tmp < nb)
			min = current;
		else
			max = current;
	}
	current++;
	if (current * current == nb)
		return (current);
	return (0);
}
