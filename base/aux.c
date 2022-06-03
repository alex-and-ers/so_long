/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:55:30 by sebonie           #+#    #+#             */
/*   Updated: 2022/04/10 14:53:37 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_msg(char *err)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err, 2);
	ft_putchar_fd('\n', 2);
}

void	show_clicks_number(int clicks)
{
	ft_putstr_fd("Click: ", 1);
	ft_putnbr_fd(clicks, 1);
	ft_putchar_fd('\n', 1);
}

int	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (-1);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

int	finish_all(t_solong *solong, char *err)
{
	mlx_destroy_window(solong->mlx, solong->window);
	mlx_destroy_image(solong->mlx, solong->player);
	mlx_destroy_image(solong->mlx, solong->wall);
	mlx_destroy_image(solong->mlx, solong->coll);
	mlx_destroy_image(solong->mlx, solong->opened_door);
	mlx_destroy_image(solong->mlx, solong->closed_door);
	mlx_destroy_image(solong->mlx, solong->ground);
	free_map(solong->map);
	if (err)
		err_msg(err);
	exit(0);
}
