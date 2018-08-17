/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 14:33:40 by kmushta           #+#    #+#             */
/*   Updated: 2017/12/24 14:33:41 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printf_wc(const int *arr, unsigned long long int arg)
{
	wchar_t	c;
	char	*str2;

	c = (wchar_t)arg;
	if (*(arr + 5) > 1)
		if (*(arr + 2))
		{
			str2 = ft_printf_pad(*(arr + 5) - 1, 32);
			return (ft_printf_putwchar(c) + ft_printf_putstr_del(&str2));
		}
		else
		{
			if (*(arr + 1))
				str2 = ft_printf_pad(*(arr + 5) - 1, 48);
			else
				str2 = ft_printf_pad(*(arr + 5) - 1, 32);
			return (ft_printf_putstr_del(&str2) + ft_printf_putwchar(c));
		}
	else
		return (ft_printf_putwchar(c));
}

int			ft_printf_c(const int *arr, unsigned long long int arg)
{
	unsigned char	c;
	char			*str2;

	if (*(arr + 12) == 'C' || *(arr + 8) || *(arr + 9))
		return (ft_printf_wc(arr, arg));
	c = (unsigned char)arg;
	if (*(arr + 5) > 1)
		if (*(arr + 2))
		{
			str2 = ft_printf_pad(*(arr + 5) - 1, 32);
			return (write(1, &c, 1) + ft_printf_putstr_del(&str2));
		}
		else
		{
			if (*(arr + 1))
				str2 = ft_printf_pad(*(arr + 5) - 1, 48);
			else
				str2 = ft_printf_pad(*(arr + 5) - 1, 32);
			return (ft_printf_putstr_del(&str2) + write(1, &c, 1));
		}
	else
		return (write(1, &c, 1));
}
