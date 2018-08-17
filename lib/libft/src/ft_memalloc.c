/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:14:33 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/26 15:14:35 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*p;
	char	*t;
	size_t	i;

	if (!size)
		return (0);
	p = (void*)malloc(size);
	if (!p)
		return (0);
	t = p;
	i = 0;
	while (i++ < size)
		*t++ = 0;
	return (p);
}
