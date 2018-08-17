/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wstr_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:18:26 by kmushta           #+#    #+#             */
/*   Updated: 2017/12/25 17:18:28 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t			*ft_printf_wstrnew(unsigned int size)
{
	wchar_t	*ptr;

	size++;
	if (!(ptr = (wchar_t *)malloc(sizeof(wchar_t) * size)))
		return (0);
	while (--size)
		*(ptr + size) = 0;
	*ptr = 0;
	return (ptr);
}

wchar_t			*ft_printf_wstrrev(wchar_t *str)
{
	wchar_t			temp;
	unsigned int	i;
	unsigned int	j;

	if (!(i = ft_printf_wstrlen(str)))
		return (str);
	i--;
	j = 0;
	while (j < i)
	{
		temp = *(str + j);
		*(str + j) = *(str + i);
		*(str + i) = temp;
		i--;
		j++;
	}
	return (str);
}

unsigned int	ft_printf_sizeofwchar(const wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	return (0);
}

unsigned int	ft_printf_wstrlen(const wchar_t *s)
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		i += ft_printf_sizeofwchar(*s);
		s++;
	}
	return (i);
}

wchar_t			*ft_printf_wstrndup(const wchar_t *str, unsigned int n)
{
	wchar_t			*new;
	unsigned int	i;
	unsigned int	size;

	if (!(new = ft_printf_wstrnew(n)))
		return (0);
	i = 0;
	size = 0;
	while (*(str + i) && i < n)
	{
		size += ft_printf_sizeofwchar(*(str + i));
		if (size > n)
			return (new);
		*(new + i) = *(str + i);
		i++;
	}
	return (new);
}
