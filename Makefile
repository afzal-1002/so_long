# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/30 00:00:00 by mafzal            #+#    #+#              #
#    Updated: 2025/12/30 23:26:31 by mafzal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a
MLX = ./minilibx-linux/libmlx.a
MLX_FLAGS = -L./minilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

SRC = src/main.c src/init_game.c src/parse_map.c src/validate_map.c \
	  src/check_path.c src/map_utils.c src/render.c src/movement.c \
	  src/exit.c src/utils.c src/textures.c

SRC_BONUS = src_bonus/main_bonus.c src_bonus/init_game_bonus.c \
			src_bonus/parse_map_bonus.c src_bonus/validate_map_bonus.c \
			src_bonus/check_path_bonus.c src_bonus/map_utils_bonus.c \
			src_bonus/render_bonus.c src_bonus/movement_bonus.c \
			src_bonus/animation_bonus.c src_bonus/enemy_bonus.c \
			src_bonus/exit_bonus.c src_bonus/utils_bonus.c \
			src_bonus/textures_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

bonus: $(LIBFT) $(MLX) $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -I./includes -I./libft -I./minilibx-linux -c $< -o $@

$(LIBFT):
	make -C ./libft

$(MLX):
	make -C ./minilibx-linux

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make -C ./libft clean
	make -C ./minilibx-linux clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C ./libft fclean

re: fclean all

.PHONY: all bonus clean fclean re
