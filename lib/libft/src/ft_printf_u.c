/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 14:31:51 by kmushta           #+#    #+#             */
/*   Updated: 2017/12/24 14:31:52 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_printf_print2_u(char *str, const int *arr)
{
	int		i;

	i = ft_printf_strlen(str);
	if (*(arr + 14))
		while (i < *(arr + 13))
			*(str + i++) = 48;
	else if (*(arr + 1) && *(arr + 5) > i)
		while (i < *(arr + 5))
			*(str + i++) = 48;
	return (ft_printf_strrev(str));
}

static char	*ft_printf_print_u(const int *arr, unsigned long long int n)
{
	char	*str;
	int		i;

	if (!n && !*(arr + 13) && *(arr + 14))
		return (ft_printf_strnew(0));
	str = ft_printf_strnew(ft_printf_max3(20, *(arr + 13), *(arr + 5)));
	i = 0;
	while (n > 9)
	{
		*(str + i++) = n % 10 + 48;
		n /= 10;
	}
	*(str + i++) = n + 48;
	return (ft_printf_print2_u(str, arr));
}

int			ft_printf_u(const int *arr, unsigned long long int arg)
{
	int		l;
	char	*str;
	char	*str2;

	if (*(arr + 12) == 85 || *(arr + 8))
		str = ft_printf_print_u(arr, (unsigned long int)arg);
	else if (*(arr + 9) || *(arr + 10) || *(arr + 11))
		str = ft_printf_print_u(arr, (unsigned long long int)arg);
	else if (*(arr + 6))
		str = ft_printf_print_u(arr, (unsigned char)arg);
	else if (*(arr + 7))
		str = ft_printf_print_u(arr, (unsigned short int)arg);
	else
		str = ft_printf_print_u(arr, (unsigned int)arg);
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
