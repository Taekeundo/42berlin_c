/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:48:25 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/28 13:18:45 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Check the size of node, how many nodes is connected.
*/
int	ft_lstsize(t_list *node)
{
	int	size;

	size = 0;
	while (node)
	{
		node = node->next;
		size++;
	}
	return (size);
}
