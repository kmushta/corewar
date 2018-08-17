/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_writers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 14:39:28 by kmushta           #+#    #+#             */
/*   Updated: 2017/12/24 14:39:29 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_printf_putstr_del(char **str)
{
	unsigned int	i;

	if (!*str)
		return (0);
	i = write(1, *str, ft_printf_strlen(*str));
	free(*str);
	return (i);
}

unsigned int	ft_printf_putstr(const char *str)
{
	return (write(1, str, ft_printf_strlen(str)));
}
