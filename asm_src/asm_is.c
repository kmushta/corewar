/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_is.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:43:08 by vveselov          #+#    #+#             */
/*   Updated: 2018/06/14 17:08:21 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_check.h"

int		asm_isnum(int c)
{
	if (c >= 0x30 && c <= 0x39)
		return (1);
	return (0);
}

int		asm_islet(int c)
{
	if ((c >= 0x61 && c <= 0x7a) || c == '_')
		return (1);
	return (0);
}

int		asm_issp(int c)
{
	if (c == 0x20 || c == 0x09)
		return (1);
	else if (c == 0x0a || c == ';' || c == '#')
		return (2);
	else if (c == '%' || c == ':')
		return (-3);
	else if (c == ',')
		return (-2);
	else if (c == 0)
		return (-1);
	return (0);
}
