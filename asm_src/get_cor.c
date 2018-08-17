/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:57:16 by oltkache          #+#    #+#             */
/*   Updated: 2018/06/11 16:57:17 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_print_cor(char *name, int l, int fd)
{
	int i;

	i = 0;
	while (i < l)
		write(fd, &name[i++], 1);
}

char	*ft_out(char *argv)
{
	int		len;
	char	*file;

	len = ft_strlen(argv);
	while (len >= 0 && argv[len] != '.')
		--len;
	if (len <= 0)
		len = ft_strlen(argv);
	file = (char*)malloc(sizeof(char) * (len + 5));
	ft_strncpy(file, argv, len);
	file[len++] = '.';
	file[len++] = 'c';
	file[len++] = 'o';
	file[len++] = 'r';
	file[len] = '\0';
	return (file);
}

void	ft_print_cr(t_cor c, char *argv, int exec_len)
{
	int		fd;
	int		l;
	char	*file;

	ft_name(c.f_n, &(c.name), PROG_NAME_LENGTH);
	ft_name(c.f_c, &(c.comment), COMMENT_LENGTH);
	file = ft_out(argv);
	if (!file)
		return ;
	fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	ft_strdel(&file);
	l = 4;
	ft_print_cor(c.magic, l, fd);
	l = PROG_NAME_LENGTH;
	ft_print_cor(c.name, l, fd);
	l = 4;
	ft_print_cor("\0\0\0\0", l, fd);
	ft_print_cor(c.exec_size, l, fd);
	l = COMMENT_LENGTH;
	ft_print_cor(c.comment, l, fd);
	l = 4;
	ft_print_cor("\0\0\0\0", l, fd);
	l = exec_len;
	ft_print_cor(c.exec, l, fd);
	close(fd);
}

void	ft_pr_a(t_lb *arg)
{
	t_lb *a;

	a = arg;
	while (a)
	{
		ft_printf("%-18s", a->name);
		a = a->next;
	}
}
