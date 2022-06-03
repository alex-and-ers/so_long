/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:54:21 by sebonie           #+#    #+#             */
/*   Updated: 2022/04/12 18:27:08 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_solong	solong;

	if (ac != 2)
	{
		err_msg("Number of argumnets != 2!");
		return (0);
	}
	solong.map = create_map(av[1]);
	if (solong.map)
	{
		solong.mlx = mlx_init();
		game_init(&solong);
		window_init(&solong);
		hooks_init(&solong);
	}
	return (0);
}
