/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:49:45 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/28 18:49:47 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlcat_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		bytes;
	char		*q;
	const char	*p;
	char		ch;

	bytes = 0;
	q = dst;
	p = src;
	while (bytes < size && *q)
	{
		q++;
		bytes++;
	}
	if (bytes == size)
		return (bytes + ft_strlcat_strlen(src));
	while ((ch = *p++))
	{
		if (bytes + 1 < size)
			*q++ = ch;
		bytes++;
	}
	*q = 0;
	return (bytes);
}
