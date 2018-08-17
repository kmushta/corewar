/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:41:39 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/31 12:41:40 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*it;
	char			*it2;
	char			*arr;

	if (!s)
		return (0);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	it = (char *)s;
	while (*it)
		it++;
	it--;
	while ((*it == ' ' || *it == '\n' || *it == '\t') && it >= s)
		it--;
	it++;
	arr = (char *)malloc(sizeof(char) * (it - s + 1));
	if (!arr)
		return (0);
	it2 = arr;
	while (s != it)
		*it2++ = *s++;
	*it2 = 0;
	return (arr);
}
