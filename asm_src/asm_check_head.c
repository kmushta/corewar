/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:23:52 by vveselov          #+#    #+#             */
/*   Updated: 2018/06/12 17:20:46 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_check.h"

int		asm_command_skip(int *i, int pos[2], int fl, int *ct)
{
	if (fl == 1)
	{
		if (*ct & 1)
			return (-1);
		pos[1] += 5;
		*i += 5;
		*ct |= 1;
	}
	else
	{
		if (*ct & 2)
			return (-1);
		pos[1] += 8;
		*i += 8;
		*ct |= 2;
	}
	return (0);
}

int		asm_string_skip(char *s, int *i, int pos[2], int fl)
{
	int		len;

	len = 0;
	pos[1]++;
	(*i)++;
	while (s[*i] && s[*i] != '\"')
	{
		if (s[*i] == '\n')
		{
			pos[0]++;
			pos[1] = 0;
		}
		pos[1]++;
		len++;
		(*i)++;
	}
	if (fl == 0)
		return (0);
	(*i)++;
	pos[1]++;
	if (fl == 1 && len > 128)
		return (-1);
	if (fl == 2 && len > 2048)
		return (-2);
	return (0);
}

int		asm_check_head(char *s, int *i, int pos[2])
{
	int		fl;
	int		command;
	int		ct;

	ct = 0;
	while (ct != 3)
	{
		asm_skip_space(s, i, pos, 2);
		if ((command = asm_word_type(&s[*i], pos)) != 1 && command != 2)
			return (error_menager(&s[*i], pos, command));
		if (asm_command_skip(i, pos, command, &ct) == -1)
			return (error_menager(&s[*i], pos, command));
		if (asm_skip_space(s, i, pos, 1))
			return (error_menager(&s[*i], pos, -2));
		if ((fl = asm_word_type(&s[*i], pos)) != 5)
			return (error_menager(&s[*i], pos, fl));
		if ((fl = asm_string_skip(s, i, pos, command)) < 0)
			return (spec_error(fl));
		if (!asm_skip_space(s, i, pos, 3))
			return (error_menager(&s[*i], pos, asm_word_type(&s[*i], pos)));
	}
	asm_skip_space(s, i, pos, 2);
	return (0);
}
