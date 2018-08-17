/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:16:56 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/26 20:16:58 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
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
