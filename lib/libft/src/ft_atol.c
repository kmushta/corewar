/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:17:53 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/17 17:17:54 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_atol(const char *str)
{
	unsigned long long int	result;
	int						sign;

	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	sign = 0;
	if (*str == '-')
	{
		sign = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	result = 0;
	while (*str > 47 && *str < 58)
		result = result * 10 + *str++ - 48;
	if (sign)
		return (-result);
	return (result);
}
