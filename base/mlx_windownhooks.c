/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_windownhooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:11:08 by sebonie           #+#    #+#             */
/*   Updated: 2022/04/09 15:36:34 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	define_window_size(int *width, int *height, char **map)
{
	*width = 0;
	*height = 0;
	while (map[*height])
		(*height)++;
	while (map[0][*width])
		(*width)++;
	*width *= TILE;
	*height *= TILE;
}

void	window_init(t_solong *solong)
{
	int	width;
	int	height;

	define_window_size(&width, &height, solong->map);
	solong->window = mlx_new_window(solong->mlx, width, height, "So_long");
}

static int	wasd_esc_button(int keycode, t_solong *solong)
{
	if (keycode == KEY_W
		|| keycode == KEY_A
		|| keycode == KEY_S
		|| keycode == KEY_D
	)
		moves_processor(solong, keycode);
	else if (keycode == KEY_ESC)
		finish_all(solong, NULL);
	return (0);
}

static int	red_cross_button(t_solong *solong)
{
	finish_all(solong, NULL);
	return (0);
}

void	hooks_init(t_solong *solong)
{
	mlx_key_hook(solong->window, wasd_esc_button, solong);
	mlx_hook(solong->window, 17, 0, red_cross_button, solong);
	window_processor(solong);
	mlx_loop(solong->mlx);
}
