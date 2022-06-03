/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:36:12 by sebonie           #+#    #+#             */
/*   Updated: 2021/10/09 15:15:15 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;

	if (!lst)
		return (NULL);
	else
	{
		list = ft_lstnew(f(lst->content));
		if (!list)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		list->next = ft_lstmap(lst->next, f, del);
		return (list);
	}
}
