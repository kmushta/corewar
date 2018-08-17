/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 14:30:59 by kmushta           #+#    #+#             */
/*   Updated: 2017/12/24 14:31:00 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoc(char *str, unsigned long long int *n, const int *arr)
{
	*str = *n % 16 + 48;
	if (*str > 57)
	{
		if (*(arr + 12) == 88)
			*str += 7;
		else
			*str += 39;
	}
	*n /= 16;
	return (1);
}

static char	*ft_printf_print2_x(char *str, const int *arr)
{
	int		i;
	int		q;

	i = ft_printf_strlen(str);
	q = 0;
	if (*(arr + 14))
		while (i < *(arr + 13))
			*(str + i++) = 48;
	else if (*(arr + 1) && (q = 1) && !*(arr + 2))
		while (i < *(arr + 5))
			*(str + i++) = 48;
	if (*arr)
	{
		if (q && !*(arr + 2))
			i -= 2;
		if (*(arr + 12) == 88)
			*(str + i) = 88;
		else
			*(str + i) = 120;
		*(str + i + 1) = 48;
	}
	return (ft_printf_strrev(str));
}

static char	*ft_printf_print_x(int *arr, unsigned long long int n)
{
	char	*str;
	int		i;

	if (!n)
		*arr = 0;
	if (!n && !*(arr + 13) && *(arr + 14))
		return (ft_printf_strnew(0));
	str = ft_printf_strnew(ft_printf_max3(16, *(arr + 13), *(arr + 5)) + 2);
	i = 0;
	while (n > 15)
		i += ft_itoc(str + i, &n, arr);
	i += ft_itoc(str + i, &n, arr);
	if (*(str + i) > 57)
	{
		if (*(arr + 12) == 88)
			*(str + i) += 7;
		else
			*(str + i) += 39;
	}
	return (ft_printf_print2_x(str, arr));
}

int			ft_printf_x(int *arr, unsigned long long int arg)
{
	int		l;
	char	*str;
	char	*str2;

	str2 = 0;
	if (*(arr + 9) || *(arr + 10) || *(arr + 11))
		str = ft_printf_print_x(arr, (unsigned long long int)arg);
	else if (*(arr + 8))
		str = ft_printf_print_x(arr, (unsigned long int)arg);
	else if (*(arr + 6))
		str = ft_printf_print_x(arr, (unsigned char)arg);
	else if (*(arr + 7))
		str = ft_printf_print_x(arr, (unsigned short int)arg);
	else
		str = ft_printf_print_x(arr, (unsigned int)arg);
	l = ft_printf_strlen(str);
	if (*(arr + 5) > l)
	{
		str2 = ft_printf_pad(*(arr + 5) - l, 32);
		if (*(arr + 2))
			return (ft_printf_putstr_del(&str) + ft_printf_putstr_del(&str2));
		else
			return (ft_printf_putstr_del(&str2) + ft_printf_putstr_del(&str));
	}
	return (ft_printf_putstr_del(&str));
}
