/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:54:36 by sebonie           #+#    #+#             */
/*   Updated: 2022/04/20 15:03:12 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include <fcntl.h>
# include "../lib/lib42/libft.h"
// # include "../lib/mlx/mlx.h"
# include <mlx.h>

# define MAP_PLAYER 'P'
# define MAP_WALL '1'
# define MAP_COLL 'C'
# define MAP_GROUND '0'
# define MAP_EXIT 'E'

# define PLAYER "pics/pers_idle.xpm"
# define WALL "pics/wall_grey.xpm"
# define COLL "pics/gem_green.xpm"
# define GROUND "pics/ground_brown.xpm"
# define EXIT_O "pics/door_open.xpm"
# define EXIT_C "pics/door_blue.xpm"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define TILE 64

typedef struct s_solong {
	void	*mlx;
	void	*window;
	void	*player;
	void	*wall;
	void	*coll;
	void	*ground;
	void	*opened_door;
	void	*closed_door;
	int		n_colls;
	int		is_door_open;
	int		player_x;
	int		player_y;
	char	under_player;
	int		moves;
	char	**map;
}			t_solong;

void	err_msg(char *err);
void	show_clicks_number(int clicks);
int		free_map(char **map);
int		finish_all(t_solong *solong, char *err);
void	game_init(t_solong *solong);
void	window_init(t_solong *solong);
void	hooks_init(t_solong *solong);
void	moves_processor(t_solong *solong, int keycode);
void	window_processor(t_solong *solong);

//map_proc
int		map_chars_validator(char **map);
char	**create_map(char *path);
int		player_validator(char **map);
int		map_validator(char **map);
int		ber_checker(char *path);
int		colls_checker(char **map);
int		exit_checker(char **map);
int		rectangle_checker(char **map);
int		validate_walls(char **map);

#endif
