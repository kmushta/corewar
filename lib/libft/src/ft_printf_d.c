/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 14:32:59 by kmushta           #+#    #+#             */
/*   Updated: 2017/12/24 14:33:00 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_printf_print2_d(char *str, const int *arr, int sign)
{
	int		i;
	int		q;

	i = ft_printf_strlen(str);
	q = 0;
	if (*(arr + 14))
		while (i < *(arr + 13))
			*(str + i++) = 48;
	else if (*(arr + 1) && *(arr + 5) > i && (q = 1) && !*(arr + 2))
		while (i < *(arr + 5) - *(arr + 4))
			*(str + i++) = 48;
	if (!q && sign)
		*(str + i++) = 45;
	else if (!q && *(arr + 3))
		*(str + i++) = 43;
	else if (q && sign && !*(arr + 2))
		*(str + i - 1) = 45;
	else if (q && sign)
		*(str + i) = 45;
	else if (q && *(arr + 3))
		*(str + i - 1) = 43;
	if (*(arr + 4) && *(str + i - 1) > 47 && *(str + i - 1) < 58)
		*(str + i) = 32;
	return (ft_printf_strrev(str));
}

static char	*ft_printf_print_d(const int *arr, long long int n)
{
	char	*str;
	int		i;
	int		sign;

	if (!n && !*(arr + 13) && *(arr + 14))
		return (ft_printf_strnew(0));
	str = ft_printf_strnew(ft_printf_max3(20, *(arr + 13), *(arr + 5)) + 1);
	i = 0;
	sign = 0;
	if (n < 0)
		sign = 1;
	while (n > 9 || n < -9)
	{
		*(str + i++) = ft_printf_abs(n % 10) + 48;
		n /= 10;
	}
	*(str + i++) = ft_printf_abs(n % 10) + 48;
	return (ft_printf_print2_d(str, arr, sign));
}

int			ft_printf_d(const int *arr, unsigned long long int arg)
{
	int		l;
	char	*str;
	char	*str2;

	if (*(arr + 11) || *(arr + 8) || *(arr + 12) == 68)
		str = ft_printf_print_d(arr, (long int)arg);
	else if (*(arr + 9) || *(arr + 10))
		str = ft_printf_print_d(arr, (long long int)arg);
	else if (*(arr + 6))
		str = ft_printf_print_d(arr, (signed char)arg);
	else if (*(arr + 7))
		str = ft_printf_print_d(arr, (short int)arg);
	else
		str = ft_printf_print_d(arr, (int)arg);
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
