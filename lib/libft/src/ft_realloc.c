/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:38:25 by kmushta           #+#    #+#             */
/*   Updated: 2017/12/03 13:38:26 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void **src, size_t size, size_t new_size)
{
	unsigned char	*new;
	size_t			i;

	if (!src)
		return (0);
	if (new_size == size)
		return (*src);
	if (!new_size)
		new_size++;
	if (!(new = (unsigned char *)malloc(sizeof(unsigned char) * new_size)))
		return (0);
	i = 0;
	if (*src)
	{
		while (i < size && i < new_size)
		{
			*(new + i) = *(*(unsigned char **)src + i);
			i++;
		}
		free(*src);
	}
	while (i < new_size)
		*(new + i++) = 0;
	*src = (void *)new;
	return (*src);
}
