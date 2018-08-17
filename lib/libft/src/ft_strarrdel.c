/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:23:22 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/17 17:23:23 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarrdel(char ***str)
{
	char	**split;

	if (str && *str)
	{
		split = *str;
		while (*split)
		{
			free(*split);
			split++;
		}
		free(*str);
	}
}
