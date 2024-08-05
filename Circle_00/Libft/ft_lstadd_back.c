/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:54:43 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/28 13:22:52 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Background ]
	(1) t_list *node
		pointer to the node.

	(2) t_list **node
		pointer (.)
		to the pointer(.)
		points to head node,
		which is first node in linked list.

		리스트의 시작 지점인 헤드 노드를 가리키는 포인터에 대한 포인터.

	t_list **node		// Pointer, points to the head node's pointer.
		.
		|
		v
		t_list *node	// pointer, points to the head node.
			.
			|
			v
			head node -> next node -> next node -> ...

	[ Definition ]
	Add new node to the last order of linked list.

	[ Logic ]
	1. Handling exceptional cases: if, if.
	2. Make tmp, cpy *node to tmp // tmp points head node now.
	3. While loop // following next -> next -> next until meet with NULL.
	4. When meet NULL -> node's next, which tmp points, points to new.
*/
void	ft_lstadd_back(t_list **node, t_list *new)
{
	t_list	*tmp;

	if (!node || !new)
		return ;
	if (!(*node))
	{
		*node = new;
		return ;
	}
	tmp = *node;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
