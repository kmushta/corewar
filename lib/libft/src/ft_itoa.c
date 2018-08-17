/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:02:16 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/31 14:02:18 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_strlen(char *s)
{
	int i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

static void	ft_itoa_putnbr(char *c, int n)
{
	if (n < 10 && n > -10)
	{
		if (n > -1)
			*c++ = n + 48;
		else
		{
			*c++ = 48 - n;
			*c++ = '-';
		}
		*c++ = 0;
	}
	else
	{
		ft_itoa_putnbr(c + 1, n / 10);
		if (n < 10)
			*c = 48 - n % 10;
		else
			*c = n % 10 + 48;
	}
}

char		*ft_itoa(int n)
{
	char	buff[STR_INT_LEN + 1];
	char	*arr;
	char	*it;
	char	*it2;
	int		len;

	ft_itoa_putnbr(buff, n);
	len = ft_itoa_strlen(buff);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	it = arr;
	it2 = buff + len - 1;
	while (len--)
		*it++ = *it2--;
	*it = 0;
	return (arr);
}
