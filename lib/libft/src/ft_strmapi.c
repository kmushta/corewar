/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:27:33 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/29 16:27:35 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		i = 0;
		while (*s)
			*it++ = (*f)(i++, *s++);
		*it = 0;
		return (str);
	}
	return (0);
}
