/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 14:29:47 by kmushta           #+#    #+#             */
/*   Updated: 2017/12/24 14:29:49 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_printf_print2_o(char *str, const int *arr)
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
		if (*(str + i - 1) != 48)
			*(str + i) = 48;
	return (ft_printf_strrev(str));
}

static char	*ft_printf_print_o(int *arr, unsigned long long int n)
{
	char	*str;
	int		i;

	if (!n && !*(arr + 13) && *(arr + 14))
	{
		if (!*arr)
			return (ft_printf_strnew(0));
		else
			return (ft_printf_pad(1, 48));
	}
	str = ft_printf_strnew(ft_printf_max3(23, *(arr + 13), *(arr + 5)));
	i = 0;
	while (n > 7)
	{
		*(str + i) = n % 8 + 48;
		n /= 8;
		i++;
	}
	*(str + i) = n + 48;
	return (ft_printf_print2_o(str, arr));
}

int			ft_printf_o(int *arr, unsigned long long int arg)
{
	int		l;
	char	*str;
	char	*str2;

	if (*(arr + 9) || *(arr + 10) || *(arr + 11))
		str = ft_printf_print_o(arr, (unsigned long long int)arg);
	else if (*(arr + 8) || *(arr + 12) == 'O')
		str = ft_printf_print_o(arr, (unsigned long int)arg);
	else if (*(arr + 6))
		str = ft_printf_print_o(arr, (unsigned char)arg);
	else if (*(arr + 7))
		str = ft_printf_print_o(arr, (unsigned short int)arg);
	else
		str = ft_printf_print_o(arr, (unsigned int)arg);
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
