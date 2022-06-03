/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:10:52 by sebonie           #+#    #+#             */
/*   Updated: 2021/10/09 15:11:04 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;

	if (!dst && !src)
		return (dst);
	dest = (unsigned char *) dst;
	source = (unsigned char *) src;
	if (dst < src)
	{
		while (len--)
			*dest++ = *source++;
	}
	else
	{
		while (len--)
			dest[len] = source[len];
	}
	return (dst);
}
