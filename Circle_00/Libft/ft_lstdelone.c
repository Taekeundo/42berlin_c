/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:01:10 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/28 12:09:01 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Delete content, which is saved in Param(1): "node"
	by using the function Param(2): "del" and deallocate memory.
*/
void	ft_lstdelone(t_list *node, void (*del)(void*))
{
	if (node == NULL || del == NULL)
		return ;
	del(node->content);
	free(node);
}
