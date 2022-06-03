/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:22:30 by sebonie           #+#    #+#             */
/*   Updated: 2022/04/20 14:14:08 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	proper_chars_check(char **map, int i, int j)
{
	char	exit;
	char	wall;
	char	player;
	char	coll;
	char	space;

	exit = 'E';
	wall = '1';
	player = 'P';
	coll = 'C';
	space = '0';
	if (
		map[i][j] == exit || map[i][j] == wall || map[i][j] == player
		|| map[i][j] == coll || map[i][j] == space
	)
		return (1);
	err_msg("You can use only ['E''1''P''C''0'] chars in your map!");
	return (0);
}

int	map_chars_validator(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!proper_chars_check(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	send_player_err(int players_count)
{
	if (players_count == 0)
		err_msg("You can't start the game without player sym on map!");
	else
		err_msg("In my game can be only one player sym on map!");
	return (0);
}

int	player_validator(char **map)
{
	int	i;
	int	j;
	int	players_count;

	i = 0;
	players_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == MAP_PLAYER)
				players_count++;
			if (players_count > 1)
				return (send_player_err(players_count));
			j++;
		}
		i++;
	}
	if (players_count == 0)
		return (send_player_err(players_count));
	return (1);
}
