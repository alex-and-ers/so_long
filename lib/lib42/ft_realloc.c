/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:25:36 by sebonie           #+#    #+#             */
/*   Updated: 2022/03/26 18:25:42 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *initial_ptr, size_t initial_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = ft_calloc(1, new_size);
	if (new_ptr)
	{
		if (initial_size < new_size)
			ft_memmove(new_ptr, initial_ptr, initial_size);
		else
		{
			ft_memmove(new_ptr, initial_ptr, new_size);
			((char *)new_ptr)[new_size - 1] = 0;
		}
	}
	free(initial_ptr);
	initial_ptr = NULL;
	return (new_ptr);
}
