/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 14:34:24 by kmushta           #+#    #+#             */
/*   Updated: 2017/12/24 14:34:26 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoc(char *str, unsigned long int *n)
{
	*str = *n % 16 + 48;
	if (*str > 57)
		*str += 39;
	*n /= 16;
	return (1);
}

static char	*ft_printf_print_p(const int *arr, unsigned long int n)
{
	char	*str;
	int		i;

	str = ft_printf_strnew(ft_printf_max3(16, *(arr + 5), *(arr + 13)) + 2);
	i = 0;
	while (n > 9)
		i += ft_itoc(str + i, &n);
	i += ft_itoc(str + i, &n);
	if (*(arr + 14))
		while (i < *(arr + 13))
			*(str + i++) = 48;
	else if (*(arr + 1))
		while (i + 2 < *(arr + 5))
			*(str + i++) = 48;
	if (*(arr + 14) && !*(arr + 13) && *(str + i - 1) == 48)
		i--;
	*(str + i) = 120;
	*(str + ++i) = 48;
	return (ft_printf_strrev(str));
}

int			ft_printf_p(const int *arr, unsigned long long int arg)
{
	int		l;
	char	*str;
	char	*str2;

	str = ft_printf_print_p(arr, (unsigned long int)arg);
	l = ft_printf_strlen(str);
	if (*(arr + 5) > l)
	{
		str2 = ft_printf_pad(*(arr + 5) - l, 32);
		if (*(arr + 2))
			return (ft_printf_putstr_del(&str) + ft_printf_putstr_del(&str2));
		else
			return (ft_printf_putstr_del(&str2) + ft_printf_putstr_del(&str));
	}
	else
		return (ft_printf_putstr_del(&str));
}
