#include "push_swap.h"

/* [D]
** Push a node to the top from src to dest (가장 위 노드 1개만 보내는거다)
** 1. 옆으로 이동시킬 노드를 보관할 (node_to_push)라는 컨테이너를 하나 만든다.
** 2. (node_to_push)컨테이너에 *src가 가리키는 첫번째 노드 값을 복사해준다.
** 3. *src는 이제부터 (*src + 1)부터 시작한다. (첫번째 *src의 노드를 (node_to_push)컨테이너에 복사하고 *src노드에서는 더이상 취급하지 않고 날려버림)
** 4. Origin(*src + 1)의 prev값을 NULL로 수정해준다. // 왜냐하면 이제부터 Origin(*src + 1)이 *src의 헤드노드로 취급되기 때문에.
** 5. (node_to_push)컨테이너도 다른 스택으로 이동하게 될 경우 가장 위에 저장되기 때문에 head노드로서 역할을 할 수 있도록 prev값에 NULL을 복사해준다.
** 6. *dest가 NULL이라면 == dest에 아무 노드도 존재하지 않는다면. --> (node_to_push)컨테이너의 값(*src)을 복사해준다. 다음 노드가 없기에 컨테이너의 next값도 NULL처리 해준다.
** 7. *dest에 애초에 노드가 존재했다면, stack에 Push시킨 새로운 노드 뒤로 기존 dest노드를 붙여준다. 당연히 *dest 첫번째 노드의 prev값은 (NULL)에서 컨테이너로 연결시켜줘야한다.
** 
*/
static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*node_to_push;							// place to save (src)

	if (*src == NULL)								// If stack doesn't point anything. (NULL)
		return ;									// There is no component(src) to push to **dest. so exit function.
	node_to_push = *src;							// cpy *src to 'node_to_push'.
	*src = (*src)->next;							// *src의 위치를 *src + 1으로 한칸 이동 (next노드로 이동).
	if (*src)										// 만약에 이동한 (origin)*src + 1 == (curr)*src가 NULL이 아닐 경우 // (origin)*src+1값이 존재할 경우
		(*src)->prev = NULL;						// (origin)*src + 1 -> prev (==(origin)*src))의 값에 NULL을 복사한다. // 2번째 노드의 prev값이 NULL이 된다.
	node_to_push->prev = NULL;						// node_to_push(*src) -> prev (==(origin)NULL))의 값에 NULL을 복사한다.
	if (*dest == NULL)								// *dest==NULL // dest가 가리키는 노드가 없다. (= 아무 노드도 존재하지 않는다)
	{
		*dest = node_to_push;						// dest에다가 node_to_push((prev값이 NULL)로 설정된 *src)를 복사한다.
		node_to_push->next = NULL;					// (node_to_push)의 next값에도 NULL을 복사한다. (노드가 존재하지 않기 때문에)
	}
	else											// dest에 node가 존재한다면,
	{
		node_to_push->next = *dest;					// (node_to_push)컨테이너의 next에 *dest를 붙여준다. push를 통해 보낸 컨테이너 노드의 뒤에 기존 *dest노드를 붙여준다.
		node_to_push->next->prev = node_to_push;	// 반대로 *dest의 첫 노드 prev에 컨테이너를 연결해준다 (양방향노드)
		*dest = node_to_push;						// *dest가 가리켰던 주소에 (컨테이너)를 연결시킨다. (헤드노드)가 변경된거다.
	}
}

/* [D]
** stack 'b'의 top노드를 stack'a'로 보낸다.
*/
void	pa(t_stack **a, t_stack **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

/* [D]
** stack 'a'의 top노드를 stack'b'로 보낸다.
*/
void	pb(t_stack **b, t_stack **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
