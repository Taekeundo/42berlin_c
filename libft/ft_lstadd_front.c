/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:28:33 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/28 13:42:46 by tkwak            ###   ########.fr       */
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
	Add new node to the front of linked list.

	[ Logic ]
	1. Find exceptions and handlig.
		If Param(1): "node" points to empty(Nothing),
			New node is the only node.
			From now on 'head node' is Param(2): 'new' node.

	2. new->next = *node;
		(New) points to (orignal)head node's pointer.
		
	3. *node = new;
		Change start pointer
		From now on node's head(*node) is (New).
*/
void	ft_lstadd_front(t_list **node, t_list *new)
{
	if (*node == NULL)
	{
		*node = new;
		return ;
	}
	new->next = *node;
	*node = new;
}
