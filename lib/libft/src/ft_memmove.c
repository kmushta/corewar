/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:53:19 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/28 12:53:21 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *s1;
	unsigned char *s2;

	if ((unsigned char *)dst != (unsigned char *)src)
	{
		s1 = (unsigned char *)dst;
		s2 = (unsigned char *)src;
		if ((size_t)s2 < (size_t)s1)
		{
			s1 += len - 1;
			s2 += len - 1;
			while (len--)
				*s1-- = *s2--;
		}
		else
			while (len--)
				*s1++ = *s2++;
	}
	return (dst);
}
