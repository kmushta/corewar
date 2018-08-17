/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 20:13:07 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/25 20:13:08 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_lstaddend(t_list **lst, void *str)
{
	t_list *temp;

	if (!(*lst))
	{
		*lst = (t_list*)malloc(sizeof(t_list));
		(*lst)->content = str;
		(*lst)->next = NULL;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = (t_list*)malloc(sizeof(t_list));
	temp->next->content = str;
	temp->next->next = NULL;
}

void	ft_reg(char *str)
{
	if (str[0] == '0')
	{
		if (str[1] != '\0')
			ft_printf("%-18s", &str[1]);
		else
			ft_printf("%-18s", str);
	}
	else
		ft_printf("%-18s", str);
}

void	ft_read(char *argv, t_cor c, char *tmp, int out)
{
	t_list	*lst;
	t_lb	*l;
	int		len;

	l = NULL;
	lst = NULL;
	ft_get_lst(&lst, tmp);
	ft_lable(&l, lst);
	ft_zero(&(c.exec_size), 4);
	len = 0;
	ft_exec_size(&l, &len);
	ft_ex_s(len, &c.exec_size);
	c.exec = (char*)malloc(sizeof(char) * (len + 1));
	(c.exec)[len] = '\0';
	ft_magic(&c);
	ft_exec(&(c.exec), l);
	if (out != 1)
		ft_print_cr(c, argv, len);
	else
		ft_a_flag(l, c.f_n, c.f_c, len);
	ft_del_all(lst, l, c.exec);
}

int		ft_file(char *argv, int len, int out)
{
	t_cor	c;
	char	file[len + 1];
	int		fd;

	file[len] = '\0';
	fd = open(argv, O_RDONLY);
	read(fd, file, len);
	close(fd);
	if (asm_check(file))
		return (1);
	ft_get_n_c(file, &c);
	ft_cl_file(&file, len);
	ft_space(&file, len);
	ft_skip_nl(&file, len);
	fd = ft_no_n_c(file);
	ft_read(argv, c, &file[fd + 1], out);
	ft_strdel(&(c.f_n));
	ft_strdel(&(c.f_c));
	return (0);
}

int		main(int argc, char **argv)
{
	int		len;
	int		fd;
	int		i;

	i = 0;
	if (argc == 1)
	{
		ft_usage();
		return (0);
	}
	while (argv[i + 1])
		if (ft_strcmp(argv[i++], "-a") == 0)
			argc = 1;
	fd = open(argv[i], O_RDONLY);
	if (fd < 0 || argv[i][ft_strlen(argv[i]) - 1] != 's')
	{
		ft_inv_file(argv[i]);
		return (0);
	}
	len = lseek(fd, (size_t)0, SEEK_END);
	close(fd);
	if (ft_file(argv[i], len, argc) != 1 && argc != 1)
		ft_writing(argv[i]);
	return (0);
}
