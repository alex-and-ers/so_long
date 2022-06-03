/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:55:36 by sebonie           #+#    #+#             */
/*   Updated: 2021/10/05 15:20:52 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			i;

	i = 0;
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}
