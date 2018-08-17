/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:23:31 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/26 17:23:32 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned long int	len;
	char				*dest;
	char				*temp;
	const char			*src;

	len = 0;
	temp = (char *)s1;
	while (*temp++)
		len++;
	dest = (char*)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	temp = dest;
	src = s1;
	while (*src)
		*temp++ = *src++;
	*temp = 0;
	return (dest);
}
