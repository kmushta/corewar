# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmushta <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 16:56:19 by kmushta           #+#    #+#              #
#    Updated: 2018/03/01 16:56:22 by kmushta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VM := corewar
ASM := asm

VM_SRC_DIR := ./vm_src/
ASM_SRC_DIR := ./asm_src/
OBJ_DIR := ./vm_obj/
INC_DIR := ./inc/
LIB_DIR := ./lib/

VM_SRC := battlefield.c convert.c cycle.c cycle_die.c flag.c fork.c main.c \
	nc_draw.c nc_input.c nc_pc.c nc_utils.c op_add.c op_aff.c op_and.c \
	op_fork.c op_ld.c op_ldi.c op_lfork.c op_list.c op_live.c op_lld.c \
	op_lldi.c op_or.c op_st.c op_sti.c op_sub.c op_xor.c op_zjmp.c operation.c \
	print.c process.c push.c run.c validate.c

ASM_SRC := asm_check.c asm_check_chars.c asm_check_error.c asm_word_type.c \
	asm_check_head.c asm_labels.c main_asm.c output.c ft_del.c argc_fill.c \
	exec.c exec_size.c fill_t_cor.c asm_is.c asm_check_op.c asm_op_er.c \
	flag_a.c get_cor.c get_file.c get_lable.c 

VM_OBJ = $(addprefix $(OBJ_DIR), $(VM_SRC:.c=.o))
ASM_OBJ = $(addprefix $(OBJ_DIR), $(ASM_SRC:.c=.o))

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR := $(LIB_DIR)libft/
LIBFT_INC := $(LIBFT_DIR)inc/
LIBFT_FLAGS := -lft -L $(LIBFT_DIR)

CC_FLAGS := -Wall -Wextra -Werror -O2

LINK_FLAGS := $(LIBFT_FLAGS) -lncurses

HEADER_FLAGS := -I $(INC_DIR) -I $(LIBFT_INC)

CC := gcc

all: $(VM) $(ASM)

$(VM): $(LIBFT) $(VM_OBJ)
	@$(CC) $(VM_OBJ) $(LINK_FLAGS) -o $(VM)

$(ASM): $(LIBFT) $(ASM_OBJ)
	@$(CC) $(ASM_OBJ) $(LINK_FLAGS) -o $(ASM)

$(VM_OBJ): $(INC_DIR)corewar.h $(INC_DIR)op.h | $(OBJ_DIR)

$(ASM_OBJ): $(INC_DIR)asm.h $(INC_DIR)asm_check.h | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(VM_OBJ)
	@rm -f $(ASM_OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(VM)
	@rm -f $(ASM)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(VM_SRC_DIR)
vpath %.c $(ASM_SRC_DIR)

.PHONY: all clean fclean re
