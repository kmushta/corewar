/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 14:35:02 by kmushta           #+#    #+#             */
/*   Updated: 2017/12/24 14:35:03 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printf_prtd_ws(wchar_t **str)
{
	int		i;
	int		q;

	q = 0;
	i = 0;
	while (*(*str + i))
		q += ft_printf_putwchar(*(*str + i++));
	free(*str);
	return (q);
}

static int	ft_printf_ws(const int *arr, wchar_t *arg)
{
	int		l;
	wchar_t	*str;
	char	*str2;

	if (!arg)
		return (write(1, "(null)", 6));
	if (*(arr + 14))
		str = ft_printf_wstrndup(arg, *(arr + 13));
	else
		str = ft_printf_wstrndup(arg, ft_printf_wstrlen(arg));
	l = ft_printf_wstrlen(str);
	if (*(arr + 5) > l)
	{
		if (*(arr + 2))
		{
			str2 = ft_printf_pad(*(arr + 5) - l, 32);
			return (ft_printf_prtd_ws(&str) + ft_printf_putstr_del(&str2));
		}
		if (*(arr + 1))
			str2 = ft_printf_pad(*(arr + 5) - l, 48);
		else
			str2 = ft_printf_pad(*(arr + 5) - l, 32);
		return (ft_printf_putstr_del(&str2) + ft_printf_prtd_ws(&str));
	}
	return (ft_printf_prtd_ws(&str));
}

int			ft_printf_s(const int *arr, unsigned long long int arg)
{
	int		l;
	char	*str;
	char	*str2;

	str2 = 0;
	if ((*(arr + 12) == 83 || *(arr + 8) || *(arr + 9)) && MB_CUR_MAX != 1)
		return (ft_printf_ws(arr, (wchar_t *)arg));
	if (!(char *)arg && !*(arr + 14))
		return (write(1, "(null)", 6));
	if (*(arr + 14))
		str = ft_printf_strndup((char *)arg, *(arr + 13));
	else
		str = ft_printf_strndup((char *)arg, ft_printf_strlen((char *)arg));
	l = ft_printf_strlen(str);
	if (*(arr + 2) && *(arr + 5) > l)
	{
		str2 = ft_printf_pad(*(arr + 5) - l, 32);
		return (ft_printf_putstr_del(&str) + ft_printf_putstr_del(&str2));
	}
	if (*(arr + 1) && *(arr + 5) > l)
		str2 = ft_printf_pad(*(arr + 5) - l, 48);
	else if (*(arr + 5) > l)
		str2 = ft_printf_pad(*(arr + 5) - l, 32);
	return (ft_printf_putstr_del(&str2) + ft_printf_putstr_del(&str));
}
