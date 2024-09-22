# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 16:59:05 by yessemna          #+#    #+#              #
#    Updated: 2024/09/16 21:36:08 by yessemna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC = cc
# CFLAGS = -Wall -Wextra -Werror -Ofast
# LDFLAGS = -lmlx -framework OpenGL -framework AppKit
# MANDATORY = mandatory
# NAME = cub3d

# SRC = $(MANDATORY)/test.c	\

# OBJ = $(SRC:.c=.o)


# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

# %.o : %.c $(MANDATORY)/cube3d.h
# 	@$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm -rf $(OBJ_DIR)/*.o

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
LDFLAGS = -lmlx -framework OpenGL -framework AppKit

# Directories
MANDATORY = mandatory
NAME = cub3d

# Source files
SRC = $(MANDATORY)/test.c
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