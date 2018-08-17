/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:44:04 by vveselov          #+#    #+#             */
/*   Updated: 2018/06/14 15:19:39 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_check.h"

int		asm_check_operation(char *s, int *i, int pos[2], t_label *list)
{
	const char	operation[16][6] = {"live", "ld", "st", "add", "sub", "and",
"or", "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff"};
	int			j;
	int			l;

	l = *i;
	while (asm_islet(s[l]) || asm_isnum(s[l]))
		l++;
	l -= (*i);
	j = -1;
	while (++j < 16)
		if (asm_strnequ((char *)operation[j], &s[*i], l) &&
		l == asm_strlen((char *)operation[j]))
			break ;
	if (j < 16)
	{
		*i += l;
		pos[1] += l;
		j = asm_op(&s[*i], pos, list, j);
		if (j < 0)
			return (j);
		*i += j;
		return (0);
	}
	return (error_menager(&s[*i], pos, 4));
}

int		asm_body_end(char *s, int i, int tmp, int last)
{
	if (tmp == 0)
		return (0);
	else if (s[i] == '\0')
		return (spec_error(-3));
	s[last] = '\0';
	return (0);
}

int		asm_body_label(char *s, int *i, int pos[2], int *tmp)
{
	while (s[*i - 1] != ':')
	{
		(*i)++;
		pos[1]++;
	}
	if (!asm_skip_space(s, i, pos, 3))
		*tmp = asm_word_type(&s[*i], pos);
	return (1);
}

int		asm_check_body(char *s, int pos[2], t_label *list)
{
	int		i;
	int		last;
	int		sw;
	int		tmp;

	i = 0;
	last = 0;
	sw = 0;
	while (sw >= 0)
	{
		asm_skip_space(s, &i, pos, 2);
		if ((tmp = asm_word_type(&s[i], pos)) == 6)
			sw = asm_body_label(s, &i, pos, &tmp);
		if (tmp == 4 && (sw = 1))
		{
			if (asm_check_operation(s, &i, pos, list))
				return (-1);
		}
		else if (sw == 0 && tmp != 4)
			return (error_menager(&s[i], pos, tmp));
		if (!asm_skip_space(s, &i, pos, 3))
			return (asm_body_end(s, i, tmp, last));
		last = i;
	}
	return (0);
}

int		asm_check(char *s)
{
	int		i;
	int		pos[2];
	t_label	*list;

	i = 0;
	pos[0] = 1;
	pos[1] = 1;
	if (asm_check_head(s, &i, pos))
		return (-1);
	if (!s[i])
		return (error_menager(&s[i], pos, 0));
	list = collect_labels(s, i, pos);
	if (list && list->label[0] == '?')
	{
		del_labels(list);
		return (-1);
	}
	i = asm_check_body(&s[i], pos, list);
	del_labels(list);
	return (i);
}
