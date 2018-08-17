/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:42:48 by vveselov          #+#    #+#             */
/*   Updated: 2018/06/14 15:16:17 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_check.h"

void	put_er(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

void	er_type_o(int fl, char *s, int i)
{
	if (fl == 3 || fl == 10)
		while (asm_isnum(s[i]))
			i++;
	else if (fl == 4 || (fl == 7 && ++i) || fl == 8 || fl == 11)
		while (asm_islet(s[i]) || asm_isnum(s[i]))
			i++;
	else if (fl == 5 && ++i)
		while (s[i] && s[i] != '\"')
			i++;
	else if (fl == 6)
		while (s[i] && s[i] != ':')
			i++;
	write(1, s, i + (fl > 4 && fl < 7));
	write(1, "\"\n", 2);
}

void	er_type(int fl, char *s)
{
	int		i;

	i = 0;
	if (fl == 1)
		put_er("] COMMAND_NAME \".name");
	else if (fl == 2)
		put_er("] COMMAND_COMMENT \".comment");
	else if (fl == 3 && ++i)
		put_er("] INDIRECT \"");
	else if (fl == 4)
		put_er("] INSTRUCTION \"");
	else if (fl == 5)
		put_er("] STRING \"");
	else if (fl == 6)
		put_er("] LABEL \"");
	else if (fl == 7)
		put_er("] INDIRECT_LABEL \"");
	else if (fl == 8 && (i += 2))
		put_er("] DIRECT_LABEL \"");
	else if (fl == 10 && ++i && (i += (s[1] == '-')))
		put_er("] DIRECT \"");
	else if (fl == 11)
		put_er("] REGISTER \"");
	er_type_o(fl, s, i);
}

void	pref_er(char *s, int pos[2], int *fl)
{
	char	*num;
	int		i;

	if (*fl == 17 || *fl == 18)
	{
		*fl = ((*fl != 17) ? 8 : 7);
		i = 2;
		put_er("No such label ");
		while (asm_isnum(s[i]) || asm_islet(s[i]))
			i++;
		write(1, &s[2], i - 2);
		put_er(" while attempting to dereference token [TOKEN][");
	}
	else
		put_er("Syntax error at token [TOKEN][");
	num = asm_itoa(pos[0], 3);
	write(1, num, 3);
	free(num);
	write(1, ":", 1);
	num = asm_itoa(pos[1], 3);
	write(1, num, 3);
	free(num);
}

int		error_menager(char *s, int pos[2], int fl)
{
	if (fl == -1 || fl == 32 || fl == -32)
		lexical_er(pos);
	else
		pref_er(s, pos, &fl);
	if (fl == 0)
		write(1, "] END \"(null)\"\n", 15);
	else if (fl == -2)
		write(1, "] ENDLINE\n", 10);
	else if (fl == 9)
		put_er("] SEPARATOR \",\"\n");
	else if (fl > 0 && fl != 32)
		er_type(fl, s);
	return (-1);
}
