# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 16:59:05 by yessemna          #+#    #+#              #
#    Updated: 2024/10/24 20:31:25 by yessemna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc #-fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror -Ofast
LDFLAGS = -lmlx -framework OpenGL -framework AppKit
OBJ_DIR = obj
MANDATORY = mandatory
NAME = cub3d

SRC = $(MANDATORY)/main.c $(MANDATORY)/utils/ft_split.c $(MANDATORY)/utils/get_next_line.c $(MANDATORY)/utils/ft_strcmp.c \
		$(MANDATORY)/utils/ft_strlen.c $(MANDATORY)/utils/ft_strncmp.c $(MANDATORY)/utils/ft_substr.c \
		$(MANDATORY)/utils/ft_open/ft_open_tools.c $(MANDATORY)/utils/ft_open/ft_open.c $(MANDATORY)/utils/ft_malloc/ft_malloc_tools.c \
		$(MANDATORY)/utils/ft_malloc/ft_malloc.c $(MANDATORY)/utils/strjoin.c $(MANDATORY)/utils/ft_bzero.c $(MANDATORY)/utils/ft_calloc.c\
		$(MANDATORY)/utils/ft_putendl.c $(MANDATORY)/utils/ft_strdup.c $(MANDATORY)/utils/ft_atoi.c $(MANDATORY)/utils/tools.c\
		$(MANDATORY)/utils/printf/ft_hexa.c $(MANDATORY)/utils/printf/ft_printf.c $(MANDATORY)/utils/printf/ft_putchar.c \
		$(MANDATORY)/utils/printf/ft_putnbr.c $(MANDATORY)/utils/printf/ft_putstr.c $(MANDATORY)/parsing/checkers.c \
		$(MANDATORY)/parsing/fill_map_data.c $(MANDATORY)/parsing/handlers.c $(MANDATORY)/utils/join_char.c \

OBJ = $(SRC:$(MANDATORY)/%.c=$(MANDATORY)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

$(MANDATORY)/%.o: $(MANDATORY)/%.c $(MANDATORY)/cube3d.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# .PHONY: all clean fclean re
