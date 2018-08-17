/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:04:05 by kmushta           #+#    #+#             */
/*   Updated: 2018/06/13 15:04:06 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <fcntl.h>
# include <ncurses.h>
# include "libft.h"
# include "op.h"
# include <zconf.h>

typedef struct			s_flag
{
	unsigned long int	d;
	unsigned long int	s;
	char				v;
	char				a;
	char				n;
	char				nc;
	short				champs[MAX_PLAYERS];
}						t_flag;

typedef struct			s_process
{
	char				carry;
	int					reg[REG_NUMBER];
	int					live;
	unsigned char		stay;
	int					position;
	int					cycle;
	int					name;
	unsigned char		func;
	unsigned char		byte;
	struct s_process	*next;
	int					num;
	unsigned char		col;
	unsigned long int	live_cycle;
}						t_process;

typedef struct			s_base
{
	unsigned char		battle[MEM_SIZE];
	unsigned char		owner[MEM_SIZE];
	int					name_proc;
	int					champ_win;
	unsigned long int	champ_cycle;
	unsigned long int	cycle;
	struct s_flag		flag;
	int					max_check;
	int					cycle_to_die;
	int					processes;
	char				go;
	int					speed;
}						t_base;

typedef struct			s_drop
{
	struct s_base		*base;
	struct s_process	*proc;
}						t_drop;

void					champ_on_field(unsigned char *champ, t_header *head,
	t_base *base, int numb);
void					zero_base(t_base *base);
int						get_champs_count(t_header **head);
t_base					battlefield(t_header **head, char *name);
unsigned char			enc_byte(unsigned char enc, char arg_num);
int						to_int(t_base *base, int pos, int size);
void					put_int(t_base *base, int num, int pos, int size);
void					set_own(t_base *base, unsigned char own, int pos,
	int size);
void					cycle_flags(t_base *base, t_header *header,
	t_process *head);
void					cycle_flags2(t_base *base);
void					cycle_flags3(t_base *base);
void					cycle(int num_champ, t_base *base, t_header **header);
int						counting_lives(t_process **head);
void					kill_you2(t_process **head, t_base *base);
void					kill_you(t_process **head, t_base *base);
void					set_to_zero(t_process **head);
void					cycle_die(t_process **head, t_base *base,
	t_header *header);
int						no_col(short *tab, short n);
void					add_fl(short *tab, short n);
int						is_val_n(t_flag *flag, char *str);
int						make_flag2(t_flag *flag, char **argv, int *i);
int						make_flag(t_flag *flag, char **argv, int *i, int *j);
void					rewrite_reg(t_process *proc, t_process *new_proc);
t_process				*fork_proc(int position, t_process *proc, t_base *base);
unsigned char			*read_str(char *file, t_header **head);
void					nc_out(t_header *head, t_base *base);
void					init_base(t_base *base, t_flag *flag, int *n);
void					nc_con(t_base *base, int i);
void					nc_coff(t_base *base, int i);
void					nc_pairs(void);
void					nc_print_std(void);
void					nc_draw(t_base *base, t_header *header);
void					ref_nc(t_base *base);
void					red_speed1(t_base *base);
void					red_speed2(t_base *base);
void					red_speed(t_base *base);
void					rm_pc(t_base *base, int pos);
void					add_pc(t_base *base, int pos);
void					init_pcs(t_base *base, t_process **head);
void					init_nc(t_flag flag);
void					renew(t_base *base);
void					op_add(t_process *proc, t_base *base, int i);
void					op_aff(t_process *proc, t_base *base, int i);
int						first_op(int *i, t_base *base,
	t_process *proc, int *arg);
int						second_op(int *i, t_base *base,
	t_process *proc, int *arg);
void					arg_op(int *arg, t_base *base, int i);
void					in_reg(t_base *base,
	t_process *proc, int i, int num);
void					op_and(t_process *proc, t_base *base, int i);
void					op_fork(t_process *proc, t_process **head_proc,
	t_base *base, int i);
void					op_ld_carry(t_process *proc, int tmp);
void					op_ld(t_process *proc, t_base *base, int i);
int						op_ldi_arg1(t_drop *tmp, int *arg, int *val);
int						op_ldi_arg2(t_drop *tmp, int *arg, int i, int *val);
void					op_ldi(t_process *proc, t_base *base, int i);
void					op_lfork(t_process *proc, t_process **head_proc,
	t_base *base, int i);
void					operation_part2(t_process *proc, t_base *base,
	t_process **head_proc);
void					operation(t_process *proc, t_base *base,
	t_header **head, t_process **head_proc);
void					print_live(t_base *base, t_header *current, int j,
	int n);
void					op_live(t_header **head, t_process *proc, t_base *base,
	int i);
void					op_lld(t_process *proc, t_base *base, int i);
void					op_lldi_carry(t_process *proc, int tmp);
void					op_lldi_print(t_drop *tmp, int val1, int val2, int pos);
void					op_lldi(t_process *proc, t_base *base, int i);
void					op_or(t_process *proc, t_base *base, int i);
void					op_st(t_process *proc, t_base *base, int i);
void					op_sti(t_process *proc, t_base *base, int i);
void					op_sub(t_process *proc, t_base *base, int i);
void					op_xor(t_process *proc, t_base *base, int i);
void					op_zjmp(t_process *proc, t_base *base, int i);
void					print_move(t_base *base, int pos, int shift);
int						run_pc2(t_process *proc, int label);
void					run_pc(t_process *proc, t_base *base);
int						op_cycle(int i);
void					print_win(t_base base, t_header **head);
void					introducing(t_header **head);
int						dump_print(t_base base);
int						print_usage(char *name);
t_process				*new_process(int position, int name, int num);
void					pushback_proc(t_process **head, t_process *new);
void					start_position(t_process **head,
	t_header **header_champ, int number_champ, t_base *base);
t_header				*new_champ(char *argv, int i);
void					pushback(t_header **head, t_header *new);
void					run(t_process *proc, t_base *base, t_header **head,
	t_process **head_proc);
void					run_process(t_base *base, t_process **head,
	t_header **header);
void					validate_magic(unsigned char *champ, char *argv);
void					validate_name(unsigned char *champ, t_header *head,
	char *argv);
void					validate_commit(unsigned char *champ, t_header *head,
	char *argv);
void					validate_prog_size(unsigned char *champ,
	t_header *head);
void					validate_champ(unsigned char *champ, t_header *head,
	char *argv);

#endif
