/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:05:24 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/29 17:05:26 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	len;
	char			*tmp;

	if (s1 && s2)
	{
		len = 0;
		tmp = (char *)s1;
		while (*tmp++)
			len++;
		tmp = (char *)s2;
		while (*tmp++)
			len++;
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (0);
		tmp = str;
		while (*s1)
			*tmp++ = *s1++;
		while (*s2)
			*tmp++ = *s2++;
		*tmp = 0;
		return (str);
	}
	return (0);
}
