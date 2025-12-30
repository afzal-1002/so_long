/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/12/30 00:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 64
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define ANIM_FRAMES 4
# define ENEMY_SPEED 30

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_enemy
{
	int				x;
	int				y;
	int				dir;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
	int		anim_frame;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		collected;
	int		exit_x;
	int		exit_y;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_enemy		*enemies;
	t_img		wall;
	t_img		floor;
	t_img		collectible[ANIM_FRAMES];
	t_img		exit;
	t_img		player_img[ANIM_FRAMES];
	t_img		enemy_img;
	int			frame_count;
	int			current_frame;
}	t_game;

/* Map Parsing */
char	**parse_map(char *filename, t_game *game);
int		validate_map(t_game *game);
int		check_rectangular(t_game *game);
int		check_walls(t_game *game);
int		check_elements(t_game *game);
int		check_path(t_game *game);

/* Map Utils */
int		get_map_width(char *line);
int		get_map_height(char *filename);
int		count_lines(char *filename);
void	find_player(t_game *game);
void	count_collectibles(t_game *game);

/* Game Init */
int		init_game(t_game *game, char *map_file);
int		init_mlx(t_game *game);
int		load_textures(t_game *game);
void	init_enemies(t_game *game);

/* Rendering */
void	render_map(t_game *game);
void	render_tile(t_game *game, int x, int y);
void	put_image(t_game *game, t_img img, int x, int y);
void	render_ui(t_game *game);
void	render_move_counter(t_game *game);

/* Player Movement */
int		key_press(int keycode, t_game *game);
void	move_player(t_game *game, int new_x, int new_y);
int		is_valid_move(t_game *game, int x, int y);

/* Enemy */
void	add_enemy(t_game *game, int x, int y);
void	move_enemies(t_game *game);
int		check_enemy_collision(t_game *game);
void	free_enemies(t_enemy *enemies);

/* Animation */
int		update_animation(t_game *game);

/* Game Exit */
int		close_game(t_game *game);
void	free_map(char **map);
void	destroy_images(t_game *game);
void	exit_error(char *message, t_game *game);

/* Utils */
void	print_moves(int moves);
int		is_ber_file(char *filename);

#endif
