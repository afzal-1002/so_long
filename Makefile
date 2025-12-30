# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: your_login <your_login@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/30 00:00:00 by your_login        #+#    #+#              #
#    Updated: 2025/12/30 00:00:00 by your_login       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
NAME_BONUS	= so_long_bonus

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -I./includes -I./libft -I./minilibx-linux

# Libraries
LIBFT		= ./libft/libft.a
MLX			= ./minilibx-linux/libmlx.a
MLX_FLAGS	= -L./minilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

# Source files
SRC_DIR		= src/
SRC_FILES	= main.c \
			  init_game.c \
			  parse_map.c \
			  validate_map.c \
			  check_path.c \
			  map_utils.c \
			  render.c \
			  movement.c \
			  exit.c \
			  utils.c

SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))

# Bonus source files
SRC_BONUS_DIR	= src_bonus/
SRC_BONUS_FILES	= main_bonus.c \
				  init_game_bonus.c \
				  parse_map_bonus.c \
				  validate_map_bonus.c \
				  check_path_bonus.c \
				  map_utils_bonus.c \
				  render_bonus.c \
				  movement_bonus.c \
				  animation_bonus.c \
				  enemy_bonus.c \
				  exit_bonus.c \
				  utils_bonus.c

SRC_BONUS		= $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS_FILES))

# Object files
OBJ_DIR		= obj/
OBJ			= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_BONUS_DIR	= obj_bonus/
OBJ_BONUS		= $(SRC_BONUS:$(SRC_BONUS_DIR)%.c=$(OBJ_BONUS_DIR)%.o)

# Colors
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
RESET		= \033[0m

# Rules
all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"

bonus: $(LIBFT) $(MLX) $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "$(YELLOW)Compiling $(NAME_BONUS)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "$(GREEN)✓ $(NAME_BONUS) created successfully!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS_DIR)%.c
	@mkdir -p $(OBJ_BONUS_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make -C ./libft
	@echo "$(GREEN)✓ libft built!$(RESET)"

$(MLX):
	@echo "$(YELLOW)Building minilibx...$(RESET)"
	@make -C ./minilibx-linux
	@echo "$(GREEN)✓ minilibx built!$(RESET)"

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@make -C ./libft clean
	@make -C ./minilibx-linux clean
	@echo "$(GREEN)✓ Clean complete!$(RESET)"

fclean: clean
	@echo "$(RED)Removing executables...$(RESET)"
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C ./libft fclean
	@echo "$(GREEN)✓ Full clean complete!$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re
