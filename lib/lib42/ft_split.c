/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:01:08 by sebonie           #+#    #+#             */
/*   Updated: 2021/10/09 15:14:04 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			size++;
		while (s[i] != c && s[i])
			i++;
	}
	return (size);
}

static char	*make_word(char const *s, char c)
{
	int		i;
	char	*result;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	result = malloc(sizeof(char) * (i + 1));
	if (!(result))
	{
		free(result);
		return (NULL);
	}
	ft_strlcpy(result, s, i + 1);
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words_num;
	char	**result;

	if (!s)
		return (NULL);
	words_num = count_words(s, c);
	result = malloc(sizeof(s) * (words_num + 1));
	if (!(result))
		return (NULL);
	i = -1;
	while (++i < words_num)
	{
		while (s[0] == c)
			s++;
		result[i] = make_word(s, c);
		if (!(result[i]))
		{
			free(result);
			return (NULL);
		}
		s += ft_strlen(result[i]);
	}
	result[i] = 0;
	return (result);
}
