/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 14:28:27 by kmushta           #+#    #+#             */
/*   Updated: 2017/12/24 14:28:31 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*fgc(const char *format, int *n)
{
	int		*arr;
	int		i;

	if (!(arr = (int *)malloc(sizeof(int) * 15)))
		return (0);
	i = 0;
	while (i < 15)
		*(arr + i++) = 0;
	*n = ft_printf_read_flags(format, arr);
	*n += ft_printf_read_width(format + *n, arr);
	*n += ft_printf_read_precision(format + *n, arr);
	*n += ft_printf_read_modificators(format + *n, arr);
	*n += ft_printf_read_transformation(format + *n, arr);
	return (arr);
}

static int	ft_printf_cases(int *arr, unsigned long long int arg)
{
	if (*(arr + 12) == 115 || *(arr + 12) == 83)
		return (ft_printf_s(arr, arg));
	if (*(arr + 12) == 112)
		return (ft_printf_p(arr, arg));
	if (*(arr + 12) == 99 || *(arr + 12) == 67)
		return (ft_printf_c(arr, arg));
	if (*(arr + 12) == 100 || *(arr + 12) == 105 || *(arr + 12) == 68)
		return (ft_printf_d(arr, arg));
	if (*(arr + 12) == 85 || *(arr + 12) == 117)
		return (ft_printf_u(arr, arg));
	if (*(arr + 12) == 88 || *(arr + 12) == 120)
		return (ft_printf_x(arr, arg));
	if (*(arr + 12) == 79 || *(arr + 12) == 111)
		return (ft_printf_o(arr, arg));
	if (*(arr + 12) == 37)
		return (ft_printf_c(arr, (unsigned long long int)37));
	return (0);
}

static int	ft_printf_print(const char **format, unsigned long long int arg,
	int **arr, int tmp)
{
	int		*table;
	int		i;
	char	*str;

	table = *arr;
	*format += tmp + 1;
	i = 0;
	if (!*(table + 12))
	{
		if (*(table + 5))
		{
			if (*(table + 1) && !*(table + 2))
				str = ft_printf_pad(*(table + 5) - 1, 48);
			else
				str = ft_printf_pad(*(table + 5) - 1, 32);
			if (*(table + 2))
				i += write(1, (*format)++, 1);
			i += ft_printf_putstr_del(&str);
		}
		free(table);
		return (i);
	}
	i += ft_printf_cases(table, arg);
	free(*arr);
	return (i);
}

int			ft_printf(const char *f, ...)
{
	va_list				ap;
	int					*t;
	int					tab[3];

	va_start(ap, f);
	*tab = 0;
	*(tab + 1) = 0;
	while (*f)
	{
		while (*(f + *(tab + 1)) && *(f + *(tab + 1)) != 37)
			*(tab + 1) += 1;
		write(1, f, *(tab + 1));
		if (((f += *(tab + 1)) + 1) && ((*tab += *(tab + 1)) + 1) && *f == 37)
		{
			t = fgc(f + 1, tab + 2);
			if (*(t + 12) && *(t + 12) != 37)
				*tab += ft_printf_print(&f,
					va_arg(ap, unsigned long long int), &t, *(tab + 2));
			else
				*tab += ft_printf_print(&f, 0, &t, *(tab + 2));
		}
		*(tab + 1) = 0;
	}
	va_end(ap);
	return (*tab);
}
