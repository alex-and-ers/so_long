/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:08:49 by sebonie           #+#    #+#             */
/*   Updated: 2022/04/20 13:28:35 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_colls(char **map)
{
	int	colls;
	int	i;
	int	j;

	i = 0;
	colls = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == MAP_COLL)
				colls++;
			j++;
		}
		i++;
	}
	return (colls);
}

static void	find_player_pos(t_solong *solong)
{
	int		i;
	int		j;

	i = 0;
	while (solong->map[i])
	{
		j = 0;
		while (solong->map[i][j])
		{
			if (solong->map[i][j] == MAP_PLAYER)
			{
				solong->player_y = i;
				solong->player_x = j;
			}
			j++;
		}
		i++;
	}
}

static void	pisc_path_check(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		err_msg("Can't open pic on this path->");
		ft_putstr_fd(path, 2);
		ft_putchar_fd('\n', 2);
		exit(0);
	}
	close(fd);
}

static void	use_xpms_to_image(t_solong *solong)
{
	void	*mlx;
	int		width;
	int		height;

	mlx = solong->mlx;
	pisc_path_check(PLAYER);
	solong->player = mlx_xpm_file_to_image(mlx, PLAYER, &width, &height);
	pisc_path_check(WALL);
	solong->wall = mlx_xpm_file_to_image(mlx, WALL, &width, &height);
	pisc_path_check(COLL);
	solong->coll = mlx_xpm_file_to_image(mlx, COLL, &width, &height);
	pisc_path_check(GROUND);
	solong->ground = mlx_xpm_file_to_image(mlx, GROUND, &width, &height);
	pisc_path_check(EXIT_O);
	solong->opened_door = mlx_xpm_file_to_image(mlx, EXIT_O, &width, &height);
	pisc_path_check(EXIT_C);
	solong->closed_door = mlx_xpm_file_to_image(mlx, EXIT_C, &width, &height);
}

void	game_init(t_solong *solong)
{
	use_xpms_to_image(solong);
	find_player_pos(solong);
	solong->is_door_open = 0;
	solong->moves = 0;
	solong->under_player = MAP_GROUND;
	solong->n_colls = count_colls(solong->map);
}
