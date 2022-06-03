/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:17:37 by sebonie           #+#    #+#             */
/*   Updated: 2021/10/13 18:17:37 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	free_buff(int read_res, char *buff)
{
	if (buff)
		free(buff);
	return (read_res);
}

int	ft_strlen_bonus(const char *s)
{
	int	size;

	size = 0;
	if (!s)
		return (0);
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strjoin_bonus(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	*result;

	len1 = ft_strlen_bonus(s1);
	len2 = ft_strlen_bonus(s2);
	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < len1)
		result[i] = s1[i];
	while (++j < len2)
		result[i + j] = s2[j];
	result[j + i] = '\0';
	if (s1)
		free(s1);
	return (result);
}
