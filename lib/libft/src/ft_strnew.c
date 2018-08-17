/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:47:59 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/26 15:48:00 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;
	char *t;

	size++;
	s = (char*)malloc(sizeof(char) * size);
	if (!s)
		return (0);
	t = s;
	while (size--)
		*t++ = 0;
	return (s);
}
