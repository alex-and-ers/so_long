/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:54:16 by sebonie           #+#    #+#             */
/*   Updated: 2021/10/09 15:16:40 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_size;

	i = 0;
	dst_size = 0;
	while ((dst[dst_size] != '\0') && dst_size < dstsize)
		dst_size++;
	while ((src[i] != '\0') && ((dst_size + i + 1) < dstsize))
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	if (dst_size != dstsize)
		dst[dst_size + i] = '\0';
	return (dst_size + ft_strlen(src));
}
