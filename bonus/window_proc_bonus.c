/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_proc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:31:44 by sebonie           #+#    #+#             */
/*   Updated: 2022/04/20 11:37:59 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	*collnexit(t_solong *solong, char ch, int i, int j)
{
	void	*pic;

	mlx_put_image_to_window(solong->mlx, solong->window, solong->ground,
		j * TILE, i * TILE);
	if (ch == MAP_EXIT && solong->is_door_open)
		pic = solong->opened_door;
	else if (ch == MAP_EXIT && !solong->is_door_open)
		pic = solong->closed_door;
	else if (ch == MAP_COLL)
		pic = solong->coll;
	else
		pic = solong->ground;
	return (pic);
}

static void	*get_pic(t_solong *solong, char ch, int i, int j)
{
	void	*pic;

	if (ch == MAP_WALL)
		pic = solong->wall;
	else if (ch == MAP_COLL || ch == MAP_EXIT || ch == 'U')
		pic = collnexit(solong, ch, i, j);
	else if (ch == MAP_PLAYER)
		pic = solong->player;
	else
		pic = solong->ground;
	if (!pic)
		finish_all(solong, "Connot get pic. Check path to pics!");
	return (pic);
}

static void	*pic_init(t_solong *solong)
{
	void	*pic;

	if (solong->oppo->pic_index % 12 == 0)
		pic = solong->oppo->pic2;
	else
		pic = solong->oppo->pic1;
	solong->oppo->pic_index++;
	return (pic);
}

int	opponent_animator(t_solong *solong)
{
	int		i;
	int		j;
	void	*pic;

	pic = pic_init(solong);
	i = 0;
	while (solong->map[i])
	{
		j = 0;
		while (solong->map[i][j])
		{
			if (solong->map[i][j] == 'U')
			{
				mlx_put_image_to_window(solong->mlx, solong->window,
					solong->ground, j * TILE, i * TILE);
				mlx_put_image_to_window(solong->mlx, solong->window, pic,
					j * TILE, i * TILE);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	window_processor(t_solong *solong)
{
	int		i;
	int		j;
	void	*pic;

	i = 0;
	pic = get_pic(solong, solong->under_player, i, 0);
	mlx_put_image_to_window(solong->mlx, solong->window, pic,
		solong->player_x * TILE, solong->player_y * TILE);
	while (solong->map[i])
	{
		j = 0;
		while (solong->map[i][j])
		{
			if (solong->map[i][j] != 'U')
			{
				pic = get_pic(solong, solong->map[i][j], i, j);
				mlx_put_image_to_window(solong->mlx, solong->window, pic,
					j * TILE, i * TILE);
			}
			j++;
		}
		i++;
	}
}
