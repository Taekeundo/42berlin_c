/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:47:00 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/28 13:24:33 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*newnode;

	newnode = NULL;
	while (lst != NULL)
	{
		tmp = ft_lstnew((*f)(lst -> content));
		if (tmp == NULL)
		{
			ft_lstclear(&newnode, del);
			return (NULL);
		}
		ft_lstadd_back(&newnode, tmp);
		lst = lst -> next;
	}
	return (newnode);
}
