/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:29:35 by vveselov          #+#    #+#             */
/*   Updated: 2018/06/14 17:08:14 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_check.h"

int		op_label_check(char *s, t_label *list, int n)
{
	int		len;

	while (list)
	{
		len = asm_strlen(list->label) - 1;
		if (asm_strnequ(&s[n], list->label, len) &&
		asm_issp(s[len + n]))
			return (8);
		list = list->next;
	}
	return ((-16 - n));
}

int		op_skip(char *s, int *i, int pos[2], int w)
{
	if (w == 10 && ++(*i) && ++pos[1])
	{
		if (s[*i] == '-' && ++pos[1])
			(*i)++;
		while (asm_isnum(s[*i]) && ++pos[1])
			(*i)++;
	}
	else if (w == 8 && ((*i) += 2) && (pos[1] += 2))
		while ((asm_isnum(s[*i]) || asm_islet(s[*i])) && ++pos[1])
			(*i)++;
	else
		while (!asm_issp(s[*i]))
		{
			pos[1]++;
			(*i)++;
		}
	asm_skip_space(s, i, pos, 3);
	return (0);
}

int		asm_op_type(char *s, int arg, int pos[2], t_label *list)
{
	int		w;

	if ((w = asm_word_type(s, pos)) == -1)
		return (-1);
	if (w == 11 && (arg & 4))
		return (w);
	else if (w == 10 && (arg & 2))
		return (w);
	else if (w == 8 && (arg & 2))
		return (op_label_check(s, list, 2));
	else if (w == 7 && (arg & 1))
		return (op_label_check(s, list, 1));
	else if (w == 3 && (arg & 1))
		return (w);
	else if (w == 11 || w == 10 || w == 8 || w == 7 || w == 3)
		return (w + 32);
	return (w > 0 ? -w : w);
}

int		asm_op_end(char *s, int *i, int sep, int pos[2])
{
	int		fl;
	int		w;

	fl = 0;
	w = 0;
	asm_skip_space(s, i, pos, 3);
	if (s[*i] == ',' && (fl = 1))
	{
		(*i)++;
		pos[1]++;
		asm_skip_space(s, i, pos, 3);
	}
	if (fl && s[*i] == '\n')
		return (-2);
	if (((!sep && fl) || (sep && !fl)) && !asm_skip_space(s, i, pos, 1))
		return (asm_word_type(&s[*i], pos));
	asm_skip_space(s, i, pos, 3);
	if (s[*i] != '\n' && !fl)
		return (!sep ? asm_word_type(&s[*i], pos) : -16);
	return (0);
}

int		asm_op(char *s, int pos[2], t_label *list, int j)
{
	const int	args[16] = {0x2, 0x4B, 0x5C, 0x4CC, 0x4CC, 0x4FF, 0x4FF,
0x4FF, 0x2, 0x4EF, 0x6FC, 0x2, 0x4B, 0x4EF, 0x2, 0x4};
	int			w;
	int			i;
	int			par;
	int			arg;

	i = 0;
	par = 0;
	arg = args[j];
	while (arg)
	{
		if (asm_skip_space(s, &i, pos, 1))
			return (error_menager(&s[i], pos, -2));
		if ((w = asm_op_type(&s[i], arg, pos, list)) >= 32 || w <= 0)
			return (w <= 0 ? error_menager(&s[i], pos, -w) :
					op_par_er(par, w - 32, j));
		else if (w > 0)
			op_skip(s, &i, pos, w);
		if ((w = asm_op_end(s, &i, (arg & 8), pos)) != 0)
			return (w == -16 ? op_coutnt_er(j) : error_menager(&s[i], pos, w));
		par++;
		arg >>= 4;
	}
	return (i);
}
