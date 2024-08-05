/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:31:49 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/28 12:35:02 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Goes through each node in liked list (= iterate),
	applies a given Param(2): "f" function to the content of each node.

	= 연결된 모든 리스트의 content에 f (function)를 적용하는 함수
*/
void	ft_lstiter(t_list *node, void (*f)(void *))
{
	if (node == NULL || f == NULL)
		return ;
	while (node != NULL)
	{
		f(node->content);
		node = node->next;
	}
}
