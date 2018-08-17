/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 11:14:05 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/26 11:14:05 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ASM_H
# define __ASM_H

# include <fcntl.h>
# include "libft.h"
# include "op.h"
# include "asm_check.h"

typedef struct	s_cor
{
	char	*f_n;
	char	*f_c;
	char	name[PROG_NAME_LENGTH + 1];
	char	comment[COMMENT_LENGTH + 1];
	char	exec_size[4];
	char	magic[4];
	char	*exec;
}				t_cor;

typedef struct	s_lb
{
	char		*name;
	int			len;
	int			p;
	struct s_lb	*op;
	struct s_lb	*next;
}				t_lb;

typedef struct	s_d
{
	t_lb	*h;
	t_lb	*l;
	char	*name;
	char	*op;
	int		i;
	int		j;
	int		len;
	int		incr;
}				t_d;

void			ft_usage(void);
void			ft_wr(char *name);
void			ft_writing(char *name);
void			ft_wr_a(int num, char *name, char *com);
void			ft_inv_file(char *name);

void			ft_del_all(t_list *lst, t_lb *lb, char *name);
void			ft_del_lb(t_lb *l);
void			ft_del_lst(t_list *lst);

void			ft_num(char *arg, char **res, int *j, int i);
int				ft_op_id(char *op, char **res, int *j);
void			ft_dir_n(char *arg, int lb, char **res, int *j);
int				ft_arg_fill(char *op, char *arg, char **res, int *j);
int				ft_ct(t_lb *arg, char **res, int *j);

int				ft_ind(t_d d, char *name);
int				ft_dir_lb(t_d d, char **res, int *j);
void			ft_ex(t_d *d, char **ex, t_lb *arg, int *i);
void			ft_exec(char **ex, t_lb *l);

int				ft_args_len(char *s, char *op);
void			ft_operation(t_lb **op, t_list *lt);
int				ft_cotage(char *s);
void			ft_lable(t_lb **l, t_list *lt);
void			ft_exec_size(t_lb **lb, int *len);

void			ft_zero(char (*tmp)[], int len);
void			ft_magic(t_cor *c);
void			ft_name(char *c, char (*name)[], int len);
void			ft_str(char **str, char *tmp);
void			ft_get_n_c(char file[], t_cor *c);

void			ft_ex_s(int len, char (*t)[]);
void			ft_cod(int num, char *op, char *a);
void			ft_pr_di(t_lb *a, int i, char *op);
void			ft_pr_nums(char *name, t_lb *arg);
void			ft_a_flag(t_lb *lb, char *name, char *com, int num);

void			ft_print_cor(char *name, int l, int fd);
char			*ft_out(char *argv);
void			ft_print_cr(t_cor c, char *argv, int exec_len);
void			ft_pr_a(t_lb *arg);

void			ft_skip_com(char *f, int *i);
void			ft_skip_nl(char (*f)[], int len);
void			ft_cl_file(char (*f)[], int len);
void			ft_space(char (*f)[], int len);
int				ft_no_n_c(char file[]);

void			ft_lable_add(t_lb **l, char *name, t_lb *op);
int				ft_in_lable(char s);
void			ft_get_lst(t_list **lst, char *file);
int				ft_args_num(char *s);
int				ft_lb(char *s);

void			ft_reg(char *str);
void			ft_lstaddend(t_list **lst, void *str);

#endif
