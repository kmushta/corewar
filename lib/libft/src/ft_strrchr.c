/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 14:58:08 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/28 14:58:09 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char *r;

	r = s;
	while (*r)
		r++;
	if (!c)
		return ((char *)r);
	while (r != s)
	{
		if (*r == (char)c)
			return ((char *)r);
		r--;
	}
	if (*r == (char)c)
		return ((char *)r);
	return (0);
}
