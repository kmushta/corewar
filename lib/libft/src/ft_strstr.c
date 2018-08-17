/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:07:44 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/28 17:07:45 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	const char *it1;
	const char *it2;
	const char *it3;

	it1 = big;
	if (!*little)
		return ((char *)big);
	while (*it1)
	{
		it2 = it1;
		it3 = little;
		while (*it3)
		{
			if (*it2 != *it3)
				break ;
			it2++;
			it3++;
		}
		if (!(*it3))
			return ((char *)it1);
		it1++;
	}
	return (0);
}
