/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_oppo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:49:38 by sebonie           #+#    #+#             */
/*   Updated: 2022/04/20 11:35:23 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move2(t_solong *solong, int *coord, int dir1, int dir2)
{
	int		x;
	int		y;

	x = coord[0];
	y = coord[1];
	if (solong->map[x + dir1][y + dir2] == '0')
	{
		mlx_put_image_to_window(solong->mlx, solong->window, solong->ground,
			y * TILE, x * TILE);
		solong->map[x][y] = '0';
		solong->map[x + dir1][y + dir2] = 'U';
	}
}

static void	move1(t_solong *solong, int x, int y)
{
	int	dir;
	int	random;
	int	coord[2];

	coord[0] = x;
	coord[1] = y;
	random = ((solong->moves * y - x) / x * y) % 2;
	if (random == 1)
	{
		dir = solong->player_y - x;
		if (dir < 0)
			move2(solong, coord, -1, 0);
		else if (dir > 0)
			move2(solong, coord, 1, 0);
	}
	else
	{
		dir = solong->player_x - y;
		if (dir < 0)
			move2(solong, coord, 0, -1);
		else if (dir > 0)
			move2(solong, coord, 0, 1);
	}
}

void	move_oppo(t_solong *solong)
{
	int	i;
	int	j;

	i = 0;
	while (solong->map[i])
	{
		j = 0;
		while (solong->map[i][j])
		{
			if (solong->map[i][j] == 'U')
			{
				move1(solong, i, j);
				j++;
				i++;
			}
			j++;
		}
		i++;
	}
}
