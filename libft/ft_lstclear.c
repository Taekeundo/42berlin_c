/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:09:44 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/28 12:34:24 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Delete every each node using recursive function(ft_lstclear),
	And deallocate the memory. Each node pointer to the NULL.

	Order to delete starts from the last node.

	리스트의 모든 요소들을 삭제하고 해제. 마지막 리스트의 포인터 NULL설정

	[ Memo ]
	lst == NULL	 : list doesn't exist.
	del == NULL	 : fail to call [f] del.
	*lst == NULL : lst pointer to Empty(NULL).
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !del || !(*lst))
		return ;
	ft_lstclear(&(*lst)->next, del);
	(del)((*lst)->content);
	free(*lst);
	*lst = NULL;
}
