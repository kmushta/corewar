/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:45:04 by vveselov          #+#    #+#             */
/*   Updated: 2018/06/14 17:09:12 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ASM_CHECK_H
# define __ASM_CHECK_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_label
{
	char			*label;
	struct s_label	*next;
}					t_label;

int					asm_check(char *s);
int					asm_check_body(char *s, int pos[2], t_label *list);
int					asm_body_label(char *s, int *i, int pos[2], int *tmp);
int					asm_body_end(char *s, int i, int tmp, int last);
int					asm_check_operation(char *s, int *i, int pos[2],
					t_label *list);

int					asm_skip_space(char *s, int *i, int pos[2], int space_fl);
int					last_line(char *s, int *i, int pos[2]);
int					asm_strlen(char *s);
int					asm_strnequ(char *s1, char *s2, int n);
char				*asm_itoa(int n, int prec);

int					asm_issp(int c);
int					asm_islet(int c);
int					asm_isnum(int c);

int					error_menager(char *s, int pos[2], int fl);
void				pref_er(char *s, int pos[2], int *fl);
void				er_type(int fl, char *s);
void				er_type_o(int fl, char *s, int i);
void				put_er(char *s);

int					asm_check_head(char *s, int *i, int pos[2]);
int					asm_string_skip(char *s, int *i, int pos[2], int fl);
int					asm_command_skip(int *i, int pos[2], int fl, int *ct);

int					asm_op(char *s, int pos[2], t_label *list, int j);
int					asm_op_end(char *s, int *i, int sep, int pos[2]);
int					asm_op_type(char *s, int arg, int pos[2], t_label *list);
int					op_skip(char *s, int *i, int pos[2], int w);
int					op_label_check(char *s, t_label *list, int n);

t_label				*collect_labels(char *s, int i, int pos[2]);
void				add_label(t_label **list, char *s, int *i);
void				del_labels(t_label *list);
t_label				*new_label(char *s, int *i);

int					spec_error(int fl);
void				lexical_er(int pos[2]);
int					op_coutnt_er(int j);
int					op_par_er(int par, int w, int j);

int					asm_word_type(char *s, int pos[2]);
int					direct(char *s, int pos[2]);
int					dir_ind_label(char *s, int pos[2], int n);
int					comm_str_types(char *s, int pos[2]);
int					rest_types(char *s, int pos[2], int i, int sw);

#endif
