# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarbie <abarbie@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 01:29:31 by abarbie           #+#    #+#              #
#    Updated: 2021/03/16 01:36:42 by abarbie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HDR = $(LIBFT_DIR)libft.h
LIBFT_SRC_LIST = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_strcmp.c ft_strpass.c ft_strcpy.c

LIBFT_SRC = $(addprefix $(LIBFT_DIR), $(LIBFT_SRC_LIST))
LIBFT_OBJ_LIST = $(patsubst %.c, %.o, $(LIBFT_SRC_LIST))
LIBFT_OBJ = $(addprefix $(LIBFT_DIR), $(LIBFT_OBJ_LIST))

HDR_DIR = ./includes/
HDR_LIST = push_swap.h
HDR = $(addprefix $(HDR_DIR), $(HDR_LIST))

SRC_DIR = ./srcs/
SRC_LIST =	args_a.c args_b.c \
			errors.c \
			operations_p.c operations_r.c operations_rr.c operations_s.c \
			stack_a.c stack_b.c stack_c.c stack_d.c \
			stack_visual.c

SRC_PS_LIST = push_swap_a.c push_swap_b.c
SRC_CH_LIST = checker.c

SRC_PS_LIST += $(SRC_LIST)
SRC_CH_LIST += $(SRC_LIST)

SRC_PS = $(addprefix $(SRC_DIR), $(SRC_PS_LIST))
SRC_CH = $(addprefix $(SRC_DIR), $(SRC_CH_LIST))

OBJ_DIR = ./obj/
OBJ_PS_LIST = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_PS_LIST))
OBJ_CH_LIST = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_CH_LIST))

MAKE = make -sC
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBS = -lft -L./libft
INCLUDE = -I$(HDR_DIR)

.PHONY: all clean fclean re

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(LIBFT) $(LIBFT_OBJ) $(OBJ_DIR) $(OBJ_PS_LIST)
	@$(CC) $(OBJ_PS_LIST) $(LIBS) -o $@ $(INCLUDE)
	@echo "$(NAME_PS) created"

$(NAME_CH): $(LIBFT) $(LIBFT_OBJ) $(OBJ_DIR) $(OBJ_CH_LIST)
	@$(CC) $(OBJ_CH_LIST) $(LIBS) -o $@ $(INCLUDE)
	@echo "$(NAME_CH) created"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(OBJ_DIR) created"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(SRC_DIR) $(HDR) $(HDR_DIR) $(LIBFT) $(LIBFT_DIR)
	@$(CC) $(FLAGS) -c $< -o $@ $(INCLUDE)

$(LIBFT): $(LIBFT_OBJ) $(LIBFT_DIR)
	@$(MAKE) $(LIBFT_DIR)
	@echo "$(LIBFT) created"

clean:
	@$(MAKE) $(LIBFT_DIR) clean
	@echo "$(LIBFT_DIR)*.o deleted"
	@rm -rf $(OBJ_DIR)
	@echo "$(OBJ_DIR) deleted"

fclean: clean
	@$(MAKE) $(LIBFT_DIR) fclean
	@echo "$(LIBFT) deleted"
	@rm -rf $(NAME_PS)
	@echo "$(NAME_PS) deleted"
	@rm -rf $(NAME_CH)
	@echo "$(NAME_CH) deleted"

re: fclean all
