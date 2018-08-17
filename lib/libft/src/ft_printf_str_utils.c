/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 14:40:36 by kmushta           #+#    #+#             */
/*   Updated: 2017/12/24 14:40:37 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_printf_strnew(unsigned int size)
{
	char	*ptr;

	size++;
	if (!(ptr = (char *)malloc(sizeof(char) * size)))
		return (0);
	while (--size)
		*(ptr + size) = 0;
	*ptr = 0;
	return (ptr);
}

unsigned int	ft_printf_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char			*ft_printf_pad(unsigned int size, char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	*(str + size) = 0;
	while (--size)
		*(str + size) = c;
	*str = c;
	return (str);
}

char			*ft_printf_strrev(char *str)
{
	char			temp;
	unsigned int	i;
	unsigned int	j;

	if (!(i = ft_printf_strlen(str)))
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

char			*ft_printf_strndup(const char *str, unsigned int n)
{
	char			*new;
	unsigned int	i;

	if (!(new = ft_printf_strnew(n)))
		return (0);
	if (str)
	{
		i = 0;
		while (*(str + i) && i < n)
		{
			*(new + i) = *(str + i);
			i++;
		}
	}
	return (new);
}
