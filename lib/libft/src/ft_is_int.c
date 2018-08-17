/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:22:18 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/17 17:22:20 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_int(const char *str)
{
	long long int	i;

	i = ft_atol(str);
	if (i > INT_MAX || i < INT_MIN)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0' && *(str + 1) >= '0' && *(str + 1) <= '9')
		str++;
	i = 0;
	while (*str && !ft_isspace(*str))
	{
		if (*str < '0' || *str > '9' || i > 9)
			return (0);
		str++;
		i++;
	}
	while (ft_isspace(*str))
		str++;
	if (*str || !i)
		return (0);
	return (1);
}
