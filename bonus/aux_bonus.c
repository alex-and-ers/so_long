/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:55:30 by sebonie           #+#    #+#             */
/*   Updated: 2022/04/20 14:01:03 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	err_msg(char *err)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err, 2);
	ft_putchar_fd('\n', 2);
}

void	show_clicks_number(t_solong *solong)
{
	char	*clicks;

	clicks = ft_itoa(solong->moves);
	mlx_string_put(solong->mlx, solong->window, 16, 16, 0x800080, "Clicks: ");
	mlx_string_put(solong->mlx, solong->window, 88, 16, 0x800080, clicks);
	free(clicks);
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
	mlx_destroy_image(solong->mlx, solong->oppo->pic1);
	mlx_destroy_image(solong->mlx, solong->oppo->pic2);
	free_map(solong->map);
	free(solong->oppo);
	if (err)
		err_msg(err);
	exit(0);
}

void	pisc_path_check(char *path)
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
