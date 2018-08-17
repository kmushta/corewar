/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 14:42:21 by kmushta           #+#    #+#             */
/*   Updated: 2017/12/24 14:42:22 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_printf_abs(long long int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

unsigned int	ft_printf_max3(unsigned int a, unsigned int b, unsigned int c)
{
	if (a > b)
	{
		if (a > c)
			return (a);
		return (c);
	}
	if (b > c)
		return (b);
	return (c);
}
