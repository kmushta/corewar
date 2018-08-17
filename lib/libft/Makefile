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

NAME := libft.a

SRC_DIR := ./src/
OBJ_DIR := ./obj/
INC_DIR := ./inc/

SRC := ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_lstadd.c \
	ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memdel.c ft_memmove.c ft_memset.c ft_pow.c ft_putchar_fd.c \
	ft_putchar.c ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c \
	ft_putstr_fd.c ft_putstr.c ft_realloc.c ft_sqrt.c ft_strcat.c \
	ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
	ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
	ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
	ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
	ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c \
	ft_strtrim.c ft_swap.c ft_tolower.c ft_toupper.c get_next_line.c \
	ft_printf_c.c ft_printf_d.c ft_printf_o.c ft_printf_p.c \
	ft_printf_putwchar.c ft_printf_readers.c ft_printf_s.c \
	ft_printf_str_utils.c ft_printf_u.c ft_printf_utils.c ft_printf_writers.c \
	ft_printf_wstr_utils.c ft_printf_x.c ft_printf.c ft_abs.c ft_atol.c \
	ft_is_int.c ft_strarrdel.c ft_strarrlen.c ft_strpos.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC_FLAGS := -O2 -Wall -Wextra -Werror

HEADER_FLAGS := -I $(INC_DIR)

CC := gcc

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
