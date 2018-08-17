/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:48:03 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/29 14:48:06 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnstr_len(const char *s)
{
	size_t i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

static int		ft_strnstr_cmp(const char *s1, const char *s2, size_t len)
{
	if (!len)
		return (0);
	while (--len && *s1 == *s2 && (*s1 || *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*s;
	char	*end;
	size_t	size;
	char	*test;

	test = 0;
	if (!big || !little)
		size = *test;
	s = (char *)big;
	end = s + len;
	size = ft_strnstr_len(little);
	if (!size)
		return (s);
	end -= (size - 1);
	while (s < end && *s)
	{
		if (!ft_strnstr_cmp(s, little, size))
			return (s);
		s++;
	}
	return (0);
}
