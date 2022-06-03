/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:08:49 by sebonie           #+#    #+#             */
/*   Updated: 2022/04/20 14:04:03 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static void	init_oppo_pics(t_solong *solong)
{
	t_oppo	*oppo;
	int		width;
	int		height;

	oppo = malloc(sizeof(t_oppo));
	if (!oppo)
		finish_all(solong, "Something went wrong with pics!");
	solong->oppo = oppo;
	oppo->pic_index = 0;
	pisc_path_check(OPPO1);
	oppo->pic1 = mlx_xpm_file_to_image(solong->mlx, OPPO1, &width, &height);
	pisc_path_check(OPPO2);
	oppo->pic2 = mlx_xpm_file_to_image(solong->mlx, OPPO2, &width, &height);
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
	init_oppo_pics(solong);
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
