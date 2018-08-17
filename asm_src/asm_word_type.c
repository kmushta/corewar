/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_word_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:58:33 by vveselov          #+#    #+#             */
/*   Updated: 2018/06/14 17:13:00 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_check.h"

int		rest_types(char *s, int pos[2], int i, int sw)
{
	while (!asm_issp(s[++i]))
	{
		if (s[i] == '.')
		{
			pos[1] += i;
			return ((asm_word_type(&s[i], pos) > 0) ? sw : -1);
		}
		else if (s[i] == '-')
			break ;
		else if (sw == 3 && asm_islet(s[i]))
			sw = 4;
		else if (sw == -3 && asm_islet(s[i]))
			return (3);
		else if (!asm_islet(s[i]) && !asm_isnum(s[i]))
		{
			if (s[i] != '\"')
				pos[1] += i;
			return ((s[i] == '\"') ? sw : -1);
		}
	}
	if (s[0] == '%' || s[0] == ':' || (i == 0 && (sw > 4 || s[0] == '-')))
		return (-32);
	if (sw < 5 && s[i] == ':')
		return (6);
	return ((sw < 0) ? -sw : sw);
}

int		comm_str_types(char *s, int pos[2])
{
	int		i;
	int		tmp[2];

	i = 0;
	tmp[0] = pos[0];
	tmp[1] = pos[1] + 1;
	if (s[0] == '.')
	{
		if (asm_strnequ(s, ".name", 5))
			return (1);
		else if (asm_strnequ(s, ".comment", 8))
			return (2);
		return (-1);
	}
	else if (s[0] == '\"' && ++i)
	{
		while (s[i] && s[i] != '\"' && ++tmp[1])
			i++;
		if (!s[i] && !(i = 0))
			return (asm_string_skip(s, &i, pos, 0));
		return (5);
	}
	return (0);
}

int		dir_ind_label(char *s, int pos[2], int n)
{
	int		i;
	int		tmp;

	i = n;
	tmp = pos[1];
	tmp += n;
	while (asm_isnum(s[i]) || asm_islet(s[i]))
	{
		i++;
		tmp++;
	}
	if (!asm_issp(s[i]))
	{
		pos[1] = tmp;
		return (-1);
	}
	return (5 + n);
}

int		direct(char *s, int pos[2])
{
	int		i;
	int		tmp;

	i = 2;
	tmp = pos[1];
	tmp += 2;
	if (s[i] == '-')
	{
		i++;
		tmp++;
	}
	while (asm_isnum(s[i]))
	{
		i++;
		tmp++;
	}
	if (!asm_issp(s[i]) && !asm_islet(s[i]))
	{
		pos[1] = tmp;
		return (-1);
	}
	return (10);
}

int		asm_word_type(char *s, int pos[2])
{
	int		sw;
	int		i;

	i = 0;
	sw = 3;
	if (!s[0] || s[0] == '\n')
		return ((s[0] == '\n') ? 12 : 0);
	else if (s[0] == '.' || s[0] == '\"')
		return (comm_str_types(s, pos));
	else if (s[0] == ':' && (asm_isnum(s[1]) || asm_islet(s[1])))
		return (dir_ind_label(s, pos, 2));
	else if (s[0] == '%' && s[1] == ':' && (asm_islet(s[2]) || asm_isnum(s[2])))
		return (dir_ind_label(s, pos, 3));
	else if (s[0] == '%' && (asm_isnum(s[1]) ||
		(s[1] == '-' && asm_isnum(s[2]))))
		return (direct(s, pos));
	else if (s[0] == ',')
		return (9);
	else if (s[0] == '-' && asm_isnum(s[1]))
		return (rest_types(s, pos, i, -3));
	else if (s[0] == 'r' && ((asm_isnum(s[1]) && asm_issp(s[2])) ||
		(asm_isnum(s[1]) && asm_isnum(s[2]) && asm_issp(s[3]))))
		return (11);
	return (rest_types(s, pos, i - 1, sw));
}
