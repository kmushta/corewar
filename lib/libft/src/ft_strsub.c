/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:49:49 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/29 16:49:50 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	char const	*from;
	char		*to;

	if (s)
	{
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (0);
		from = s + start;
		to = str;
		while (len)
		{
			*to++ = *from++;
			len--;
		}
		*to = 0;
		return (str);
	}
	return (0);
}
