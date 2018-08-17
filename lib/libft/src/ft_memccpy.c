/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:57:37 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/25 18:57:39 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char *src;
	unsigned char *dest;

	src = (unsigned char *)s2;
	dest = (unsigned char *)s1;
	while (n--)
	{
		*dest = *src;
		if (*dest == (unsigned char)c)
			return (dest + 1);
		dest++;
		src++;
	}
	return (0);
}
