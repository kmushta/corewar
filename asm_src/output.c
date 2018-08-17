/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 14:55:31 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/27 14:55:31 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_wr(char *name)
{
	write(1, "Writing output program to ", 26);
	write(1, name, ft_strlen(name));
	write(1, "\n", 1);
}

void	ft_usage(void)
{
	write(1, "Usage: ./asm [-a] <sourcefile.s>\n    ", 37);
	write(1, "-a : Instead of creating a .cor file, outputs a stripped ", 57);
	write(1, "and annotated version of the code to the standard output\n", 57);
}

void	ft_writing(char *name)
{
	write(1, "Writing output program to ", 26);
	write(1, name, ft_strlen(name) - 1);
	write(1, "cor\n", 4);
}

void	ft_wr_a(int num, char *name, char *com)
{
	write(1, "Dumping annotated program on standard output\n", 45);
	write(1, "Program size : ", 15);
	ft_putnbr(num);
	write(1, " bytes\nName : \"", 15);
	write(1, name, ft_strlen(name));
	write(1, "\"\nComment : \"", 13);
	write(1, com, ft_strlen(com));
	write(1, "\"\n\n", 3);
}

void	ft_inv_file(char *name)
{
	write(1, "Can't read source file ", 23);
	write(1, name, ft_strlen(name));
	write(1, "\n", 1);
}
