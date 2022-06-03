/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:23:51 by sebonie           #+#    #+#             */
/*   Updated: 2022/04/20 11:31:11 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	firstnlast_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	firstnlast_sym(char *line)
{
	return (line[0] == '1' && line[ft_strlen(line) - 1] == '1');
}

int	validate_walls(char **map)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (map[i])
	{
		if (i == 0 || !map[i + 1])
			res = firstnlast_line(map[i]);
		else
			res = firstnlast_sym(map[i]);
		if (!res)
		{
			err_msg("Your game field must be surrounded with walls!");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	path_checker(char *path)
{
	int	slash;
	int	tmp;

	slash = 0;
	while (path[slash])
	{
		if (path[slash] == '/')
			tmp = slash;
		slash++;
	}
	return (tmp);
}

int	ber_checker(char *path)
{
	int		len;
	int		tmp;
	char	*substr;

	len = ft_strlen(path);
	tmp = path_checker(path);
	substr = ft_substr(path, ++tmp, len);
	if (ft_strlen(substr) > 4 && path[len - 1] == 'r' && path[len - 2] == 'e'
		&& path[len - 3] == 'b' && path[len - 4] == '.')
	{
		free(substr);
		return (1);
	}
	err_msg("You can use only '[mapname].ber' maps!");
	free(substr);
	return (0);
}
