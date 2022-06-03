/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:18:10 by sebonie           #+#    #+#             */
/*   Updated: 2022/04/20 14:19:30 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	rectangle_checker(char **map)
{
	int	i;
	int	len;
	int	len2;

	len = 0;
	i = 0;
	while (map[i])
	{
		len2 = ft_strlen(map[i]);
		if (!len)
			len = len2;
		else if (len != len2)
		{
			err_msg("Map shape must be rectangular!");
			return (0);
		}
		i++;
	}
	return (1);
}

int	exit_checker(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == MAP_EXIT)
				return (1);
			j++;
		}
		i++;
	}
	err_msg("Must be at least one exit!");
	return (0);
}

int	colls_checker(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == MAP_COLL)
				return (1);
			j++;
		}
		i++;
	}
	err_msg("Must be at least one collectible!");
	return (0);
}

int	map_validator(char **map)
{
	if (map_chars_validator(map)
		&& colls_checker(map)
		&& exit_checker(map)
		&& player_validator(map)
		&& rectangle_checker(map)
		&& validate_walls(map))
		return (1);
	return (0);
}
