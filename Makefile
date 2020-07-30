# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/31 22:43:12 by lnoisome          #+#    #+#              #
#    Updated: 2020/07/17 23:00:41 by lnoisome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEMIN_NAME = lem\-in

RED = "\033[1;31m"
GREEN = "\033[1;32m"
RESET = "\033[0;0m"
CYAN = "\033[1;35m"

CC = gcc
FLAGS = -Wall -Wextra -Werror
# FLAGS = -g


LEMIN_DIR = ./lem_in_src/
LEMIN_HEADER = ./includes/

C_SRC = main.c \
	get_next_line.c \
	read_way.c \
	create_structure.c \
	follow_line.c \
	free_lemin.c \
	error.c \
	set.c \
	add_room.c \
	tied_room.c \
	del_content.c \
	convert.c \
	put_zero.c \
	solution.c \
	fill_path.c \
	path_tmp.c \
	put_minus.c \
	find_p1.c \
	set_next.c \
	calc_ant.c \
	solve.c \
	free_way.c \
	print_way.c

C_FILES = $(addprefix $(LEMIN_DIR), $(C_SRC))
C_OBJ = $(addprefix $(LEMIN_DIR), $(patsubst %.c, %.o, $(C_SRC)))
D_FILES_LEM = $(addprefix $(LEMIN_DIR), $(patsubst %.c, %.d, $(C_SRC)))

LIBFT_DIR = ./libft_src/

L_SRC = ft_memset.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdub.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strnew.c \
		ft_strsub.c \
		ft_atoi.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_putchar.c \
		ft_memdel.c \
		ft_isinteger.c \
		ft_strequ.c \
		ft_strcmp.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstnew.c \
		ft_memcpy.c \
		ft_strsplit.c \
		ft_strdup.c

LIBA_FILES = $(addprefix $(LIBFT_DIR), $(L_SRC))
LIBA_OBJ = $(addprefix $(LIBFT_DIR), $(patsubst %.c, %.o, $(L_SRC)))
D_FILES_LIBA = $(addprefix $(LIBFT_DIR), $(patsubst %.c, %.d, $(L_SRC)))

LEMIN_FILES = $(C_FILES) $(LIBA_FILES)
LEMIN_OBJ = $(C_OBJ) $(LIBA_OBJ)
D_FILES = $(D_FILES_LEM) \& $(D_FILES_LIBA)
.PHONY: all clean fclean re

all: $(LEMIN_NAME)

$(LEMIN_NAME): $(LEMIN_OBJ)
	@$(CC) $(LEMIN_OBJ) -I $(LEMIN_HEADER) -o $(LEMIN_NAME)
	@echo $(GREEN)$(LEMIN_NAME) -\> Build done!$(RESET)

$(LEMIN_DIR)%.o: $(LEMIN_DIR)%.c
	@$(CC) $(FLAGS) -I $(LEMIN_HEADER) -MD -c $< -o $@
	@echo $(CYAN)Compiling... $<$(RESET)

$(LIBFT_DIR)%.o: $(LIBFT_DIR)%.c
	@$(CC) $(FLAGS) -I $(LIBFT_DIR) -MD -c $< -o $@
	@echo $(CYAN)Compiling... $<$(RESET)

clean:
	@rm -rf $(LEMIN_OBJ) $(D_FILES)
	@echo $(RED)Object files was deleted$(RESET)

fclean: clean
	@rm -rf $(LEMIN_NAME) $(D_FILES)
	@echo $(RED)$(LEMIN_NAME) was deleted$(RESET)

include $(wildcard $(D_FILES))

re: fclean all
