/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:32:49 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/29 15:32:51 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*it;
	char			*str;

	if (s && f)
	{
		it = (char *)s;
		i = 0;
		while (*it++)
			i++;
		str = (char *)malloc(sizeof(char) * (i + 1));
		if (!str)
			return (0);
		it = str;
		while (*s)
			*it++ = (*f)(*s++);
		*it = 0;
		return (str);
	}
	return (0);
}
