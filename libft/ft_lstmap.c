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

/*	[F]
	[ Definition ]
	연결 리스트의 각(모든) content에 f 함수를 적용한 결과를 반환.

	[ Logic ]
	1. Goes through Param(1): "lst" linked list,
	2. make new node and save the result,
		which is applied by Param(2): "f" to the (lst->content).
	3. If new_node works well -> add it at the end of the current node.

	[ Korean ]
	(1) 새 리스트 newnode & 첫번째 노드인 tmp 선언
	(2) newnode: NULL 초기화
	(3) ft_lstnew(): f함수를 적용한 값을 content로 하는 새 노드를 할당.
	(4) newnode 할당에 실패하면 현재까지 만든 새 리스트와 리스트의
		content를 free해야 하므로 ft_lstclear() 이용한 뒤 NULL리턴.
	(5) newnode 맨 뒤에 tmp를 넣은 후 다음 lst로 넘어간다.
	(6) 마지막 node에 NULL을 저장한 후 newnode 리턴.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_node;
	void	*set;

	if (!lst || !f || !del)
		return (NULL);
	new_head = NULL;
	while (lst)
	{
		set = f(lst->content);
		new_node = ft_lstnew(set);
		if (!new_node)
		{
			del(set);
			ft_lstclear(&new_head, (*del));
			return (new_head);
		}
		ft_lstadd_back(&new_head, new_node);
		lst = lst -> next;
	}
	return (new_head);
}
