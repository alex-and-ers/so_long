/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:04:40 by sebonie           #+#    #+#             */
/*   Updated: 2022/04/20 11:39:47 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	*memsize_change(void *starting_point, size_t curr_size,
	size_t new_size)
{
	void	*ptr;

	ptr = ft_calloc(1, new_size);
	if (ptr)
	{
		if (curr_size < new_size)
			ft_memmove(ptr, starting_point, curr_size);
		else
		{
			ft_memmove(ptr, starting_point, new_size);
			((char *)ptr)[new_size - 1] = 0;
		}
	}
	free(starting_point);
	starting_point = NULL;
	return (ptr);
}

static char	*nl_sym_cleaner(char *line)
{
	char	size;

	if (!line)
		return (NULL);
	size = ft_strlen(line);
	if (line[size - 1] == '\n')
		line = memsize_change(line, size + 1, size);
	return (line);
}

static void	fill_map(int fd, char ***map)
{
	char	*line;
	int		i;
	int		size;

	i = 0;
	size = 1;
	while (1)
	{
		line = get_next_line(fd);
		(*map)[i] = nl_sym_cleaner(line);
		if (!(*map)[i])
			return ;
		if (i == size - 1)
		{
			*map = memsize_change(*map, sizeof(char *) * size,
					sizeof(char *) * size * 2);
			size *= 2;
			if (!*map)
				return ;
		}
		i++;
	}
}

static char	**prepare_map(int fd)
{
	char	**map;

	map = malloc(sizeof(char *));
	if (!map)
		return (NULL);
	fill_map(fd, &map);
	if (!map[0])
	{
		err_msg("Something went wrong with map parsing. Check filepath!");
		free_map(map);
		return (NULL);
	}
	return (map);
}

char	**create_map(char *path)
{
	char	**map;
	int		fd;

	if (!ber_checker(path))
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		err_msg("Can't open file!");
		return (NULL);
	}
	map = prepare_map(fd);
	close(fd);
	if (!map)
		return (NULL);
	if (!map_validator(map))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}
