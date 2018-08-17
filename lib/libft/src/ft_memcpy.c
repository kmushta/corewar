/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:40:37 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/25 18:40:44 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned char *dest;
	unsigned char *src;

	dest = (unsigned char *)str1;
	src = (unsigned char *)str2;
	while (n--)
		*dest++ = *src++;
	return (str1);
}
