# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 16:59:05 by yessemna          #+#    #+#              #
#    Updated: 2024/10/16 06:03:11 by yessemna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
LDFLAGS = -lmlx -framework OpenGL -framework AppKit
OBJ_DIR = obj
# Directories
MANDATORY = mandatory
NAME = cub3d

# Source files
SRC = $(MANDATORY)/main.c
OBJ = $(SRC:$(MANDATORY)/%.c=$(MANDATORY)/%.o)

# Default rule
all: $(NAME)

# Linking the executable
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

# Compiling source files to object files
$(OBJ_DIR)/%.o: $(MANDATORY)/%.c $(MANDATORY)/cube3d.h
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -rf $(OBJ_DIR)/*.o

# Clean up all build artifacts
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re