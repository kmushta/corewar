/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:19:26 by vveselov          #+#    #+#             */
/*   Updated: 2018/06/14 17:07:46 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_check.h"

char	*asm_itoa(int n, int prec)
{
	char	*ret;
	int		ct;
	int		l;

	ct = 0;
	l = n;
	while (++ct && (l / 10) != 0)
		l /= 10;
	if (ct > prec)
		prec = ct;
	if (!(ret = (char *)malloc(sizeof(char) * (prec + 1))))
		return (NULL);
	ret[prec--] = '\0';
	while (prec != -1)
	{
		ret[prec] = '0' + (n % 10);
		n /= 10;
		prec--;
	}
	return (ret);
}

int		asm_strnequ(char *s1, char *s2, int n)
{
	while (n && (*s1 || *s2))
	{
		if (*s1++ != *s2++)
			return (0);
		n--;
	}
	return (1);
}

int		asm_strlen(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int		last_line(char *s, int *i, int pos[2])
{
	int		sp;
	int		tmp;

	while ((sp = asm_issp(s[*i])) > 0)
	{
		if (sp == 2)
		{
			while (s[*i] && s[*i] != '\n')
			{
				(*i)++;
				pos[1]++;
			}
			tmp = pos[1];
			pos[1] = 0;
			pos[0]++;
		}
		(*i)++;
		pos[1]++;
	}
	pos[0]--;
	pos[1] = tmp;
	return (1);
}

int		asm_skip_space(char *s, int *i, int pos[2], int space_fl)
{
	int		sp;

	while ((sp = asm_issp(s[*i])) > 0)
	{
		if (sp == 2)
		{
			if (space_fl == 1)
				return (last_line(s, i, pos));
			if (space_fl == 3)
			{
				while (s[*i] != '\n')
					(*i)++;
				return (1);
			}
			while (s[*i] && s[*i] != '\n')
				(*i)++;
			pos[0]++;
			pos[1] = 0;
		}
		(*i)++;
		pos[1]++;
	}
	return (0);
}
