/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_op_er.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:38:30 by vveselov          #+#    #+#             */
/*   Updated: 2018/06/12 21:31:56 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_check.h"

int		op_par_er(int par, int w, int j)
{
	const char	operation[16][6] = {"live", "ld", "st", "add", "sub", "and",
"or", "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff"};
	char		*num;

	put_er("Invalid parameter ");
	num = asm_itoa(par, 0);
	put_er(num);
	free(num);
	put_er(" type ");
	if (w == 11)
		put_er("register");
	else if (w == 7 || w == 3)
		put_er("indirect");
	else if (w == 10 || w == 8)
		put_er("direct");
	put_er(" for instruction ");
	put_er((char *)operation[j]);
	write(1, "\n", 1);
	return (-1);
}

int		op_coutnt_er(int j)
{
	const char	operation[16][6] = {"live", "ld", "st", "add", "sub", "and",
"or", "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff"};

	put_er("Invalid parameter count for instruction ");
	put_er((char *)operation[j]);
	write(1, "\n", 1);
	return (-1);
}

void	lexical_er(int pos[2])
{
	char	*num;

	put_er("Lexical error at [");
	num = asm_itoa(pos[0], 0);
	put_er(num);
	free(num);
	write(1, ":", 1);
	num = asm_itoa(pos[1], 0);
	put_er(num);
	free(num);
	write(1, "]\n", 2);
}

int		spec_error(int fl)
{
	if (fl == -1)
		put_er("Champion name too long (Max length 128)\n");
	else if (fl == -2)
		put_er("Champion comment too long (Max length 2048)\n");
	else if (fl == -3)
		put_er("Syntax error - unexpected end of input (Perhaps \
you forgot to end with a newline ?)\n");
	return (-1);
}
