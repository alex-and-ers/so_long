/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:47:34 by sebonie           #+#    #+#             */
/*   Updated: 2021/10/10 17:34:32 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n, unsigned int *num, int *sign)
{
	int	size;

	if (n >= 0)
	{
		*num = n;
		*sign = 1;
	}
	else
	{
		*num = -n;
		*sign = 0;
	}
	if (n > 0)
		size = 0;
	else
		size = 1;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	int				sign;
	int				size;
	char			*result;

	size = get_size(n, &num, &sign);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size--] = '\0';
	while (num >= 10)
	{
		result[size] = num % 10 + '0';
		num = num / 10;
		size--;
	}
	result[size] = num % 10 + '0';
	if (!sign)
		result[0] = '-';
	return (result);
}
