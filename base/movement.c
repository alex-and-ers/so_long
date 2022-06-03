/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:12:26 by sebonie           #+#    #+#             */
/*   Updated: 2022/04/10 13:44:23 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	visit_open_door(t_solong *solong)
{
	ft_putstr_fd("Congratz! You won!!! Number of clicks: ", 1);
	ft_putnbr_fd(solong->moves, 1);
	ft_putstr_fd("!\n", 1);
	finish_all(solong, NULL);
}

static void	decrease_coll_count(t_solong *solong, int x, int y)
{
	solong->n_colls--;
	solong->map[y][x] = MAP_GROUND;
	if (!solong->n_colls)
		solong->is_door_open = 1;
}

static void	make_movement2(t_solong *solong, int x, int y)
{
	char	**map;

	map = solong->map;
	solong->moves++;
	map[solong->player_y][solong->player_x] = solong->under_player;
	solong->under_player = map[y][x];
	map[y][x] = MAP_PLAYER;
	solong->player_x = x;
	solong->player_y = y;
}

static void	make_movement(t_solong *solong, int x, int y)
{
	char	**map;

	map = solong->map;
	if (map[y][x] != MAP_WALL)
	{
		if (map[y][x] == MAP_COLL)
			decrease_coll_count(solong, x, y);
		make_movement2(solong, x, y);
		show_clicks_number(solong->moves);
		window_processor(solong);
	}
	if (solong->under_player == MAP_EXIT && solong->n_colls == 0)
		visit_open_door(solong);
}

void	moves_processor(t_solong *solong, int keycode)
{
	int	x;
	int	y;

	x = solong->player_x;
	y = solong->player_y;
	if (keycode == KEY_W)
		y--;
	else if (keycode == KEY_S)
		y++;
	else if (keycode == KEY_A)
		x--;
	else if (keycode == KEY_D)
		x++;
	make_movement(solong, x, y);
}
