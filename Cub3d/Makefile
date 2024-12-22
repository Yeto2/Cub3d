# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 16:59:05 by yessemna          #+#    #+#              #
#    Updated: 2024/12/22 10:11:19 by lamhal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc #-g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -Iinclude
MLX_LIB = MLX42/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib"
OBJ_DIR = obj
MANDATORY = mandatory
BONUS = bonus
BUILD = MLX42/build
NAME = cub3d
NAME_BONUS=cub3D_bonus

SRC = $(MANDATORY)/main.c $(MANDATORY)/utils/ft_split.c $(MANDATORY)/utils/get_next_line.c $(MANDATORY)/utils/ft_strcmp.c \
		$(MANDATORY)/utils/ft_strlen.c $(MANDATORY)/utils/ft_itoa.c $(MANDATORY)/utils/ft_isalpha.c $(MANDATORY)/utils/ft_strncmp.c $(MANDATORY)/utils/ft_substr.c \
		$(MANDATORY)/utils/ft_open/ft_open_tools.c $(MANDATORY)/utils/ft_open/ft_open.c $(MANDATORY)/utils/ft_malloc/ft_malloc_tools.c \
		$(MANDATORY)/utils/ft_malloc/ft_malloc.c $(MANDATORY)/utils/strjoin.c $(MANDATORY)/utils/ft_bzero.c $(MANDATORY)/utils/ft_calloc.c\
		$(MANDATORY)/utils/ft_putendl.c $(MANDATORY)/utils/ft_strdup.c $(MANDATORY)/utils/ft_atoi.c $(MANDATORY)/utils/tools.c\
		$(MANDATORY)/utils/printf/ft_hexa.c $(MANDATORY)/utils/printf/ft_printf.c $(MANDATORY)/utils/printf/ft_putchar.c \
		$(MANDATORY)/utils/printf/ft_putnbr.c $(MANDATORY)/utils/printf/ft_putstr.c $(MANDATORY)/parsing/checkers.c \
		$(MANDATORY)/parsing/fill_map_data.c $(MANDATORY)/parsing/handlers.c $(MANDATORY)/utils/join_char.c $(MANDATORY)/utils/print_err.c \
		$(MANDATORY)/parsing/esolate_check.c $(MANDATORY)/parsing/is_rounded.c $(MANDATORY)/parsing/prepare.c \
		$(MANDATORY)/parsing/clean.c $(MANDATORY)/parsing/map_validity.c $(MANDATORY)/parsing/checkers_.c $(MANDATORY)/utils/ft_strchr.c \
		$(MANDATORY)/raycast/2dmap.c $(MANDATORY)/raycast/moves.c $(MANDATORY)/raycast/render3d.c $(MANDATORY)/parsing/color_handling.c \
		$(MANDATORY)/raycast/find_intrs.c $(MANDATORY)/raycast/pos_angl.c $(MANDATORY)/raycast/ray_steps.c \
		$(MANDATORY)/textures/texters.c $(MANDATORY)/textures/handlers.c \

OBJ = $(SRC:$(MANDATORY)/%.c=$(MANDATORY)/%.o)

SRC_B = $(BONUS)/main_bonus.c $(BONUS)/utils/ft_split_bonus.c $(BONUS)/utils/get_next_line_bonus.c $(BONUS)/utils/ft_strcmp_bonus.c \
		$(BONUS)/utils/ft_strlen_bonus.c $(BONUS)/utils/ft_itoa_bonus.c $(BONUS)/utils/ft_isalpha_bonus.c $(BONUS)/utils/ft_strncmp_bonus.c $(BONUS)/utils/ft_substr_bonus.c \
		$(BONUS)/utils/ft_open/ft_open_tools_bonus.c $(BONUS)/utils/ft_open/ft_open_bonus.c $(BONUS)/utils/ft_malloc/ft_malloc_tools_bonus.c \
		$(BONUS)/utils/ft_malloc/ft_malloc_bonus.c $(BONUS)/utils/strjoin_bonus.c $(BONUS)/utils/ft_bzero_bonus.c $(BONUS)/utils/ft_calloc_bonus.c\
		$(BONUS)/utils/ft_putendl_bonus.c $(BONUS)/utils/ft_strdup_bonus.c $(BONUS)/utils/ft_atoi_bonus.c $(BONUS)/utils/tools_bonus.c\
		$(BONUS)/utils/printf/ft_hexa_bonus.c $(BONUS)/utils/printf/ft_printf_bonus.c $(BONUS)/utils/printf/ft_putchar_bonus.c \
		$(BONUS)/utils/printf/ft_putnbr_bonus.c $(BONUS)/utils/printf/ft_putstr_bonus.c $(BONUS)/parsing/checkers_bonus.c \
		$(BONUS)/parsing/fill_map_data_bonus.c $(BONUS)/parsing/handlers_bonus.c $(BONUS)/utils/join_char_bonus.c $(BONUS)/utils/print_err_bonus.c \
		$(BONUS)/parsing/esolate_check_bonus.c $(BONUS)/parsing/is_rounded_bonus.c $(BONUS)/parsing/prepare_bonus.c \
		$(BONUS)/parsing/clean_bonus.c $(BONUS)/parsing/map_validity_bonus.c $(BONUS)/parsing/checkers__bonus.c $(BONUS)/utils/ft_strchr_bonus.c \
		$(BONUS)/raycast/2dmap_bonus.c $(BONUS)/raycast/render_2d_bonus.c $(BONUS)/raycast/moves_bonus.c $(BONUS)/raycast/render3d_bonus.c $(BONUS)/parsing/color_handling_bonus.c \
		$(BONUS)/raycast/find_intrs_bonus.c $(BONUS)/raycast/pos_angl_bonus.c $(BONUS)/raycast/ray_steps_bonus.c \
		$(BONUS)/textures/texters_bonus.c $(BONUS)/textures/handlers_bonus.c \

OBJ_B = $(SRC_B:$(BONUS)/%.c=$(BONUS)/%.o)

all: $(BUILD) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) -o $(NAME)

$(MANDATORY)/%.o: $(MANDATORY)/%.c $(MANDATORY)/cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BUILD) $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_B)
	@$(CC) $(CFLAGS) $(OBJ_B) $(MLX_LIB) -o $(NAME_BONUS)

$(BONUS)/%.o: $(BONUS)/%.c $(BONUS)/cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD):
	@if [ ! -d MLX42/build ]; then \
		(cd MLX42 && cmake -B build);\
	fi
	@make -C MLX42/build

clean:
	@rm -rf $(OBJ) $(OBJ_B)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@rm -rf MLX42/build

re: fclean all

.PHONY: all clean fclean re