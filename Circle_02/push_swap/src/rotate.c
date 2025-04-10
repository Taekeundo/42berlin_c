#include "push_swap.h"

/* [D]
** Top node to bottom position
** static - 계속 사용 가능
*/
static void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	int				len;

	len = stack_len(*stack);								// argv[1]에 몇개 있는지 체크
	if (stack == NULL || *stack == NULL || len == 1)		// parameter검사.
		return ;											// stack이 argv[1]을 안가리키고 있거나, argv[1][i]의 값이 없거나, 길이가 1개 (rotate가 필요없음)
	last_node = find_curr_last_node(*stack);				// [마지막 노드] 마지막 노드를 찾아서 *last_node가 가리키게 복사한다.
	last_node->next = *stack;								// 마지막 노드가 stack을 가리키게 만든다.
	*stack = (*stack)->next;								// 스택은 다음 스택을 가리키도록 재구성한다. 이제부터 스택은 2번째 노드를 가리킨다.
	(*stack)->prev = NULL;									// 기존 2번째 스택의 prev에 NULL을 넣어서 첫번째 노드로 만들어준다.
	last_node->next->prev = last_node;						// [첫번쨰 노드 -> 마지막 노드 취급] 첫번째 노드였던 (last_node->next)의 prev가 last_node를 가리킨다.
	last_node->next->next = NULL;							// [첫번쨰 노드 -> 마지막 노드 취급] 첫번째 노드였던 (last_node->next)의 next가 NULL을 가리키게 만든다.
}	

/* [D]
** rotate stack 'A'
** checker is always '0' or '1'
*/
void	ra(t_stack **a, bool checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

/* [D]
** rotate stack 'B'
** checker is always '0' or '1'
*/
void	rb(t_stack **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

/* [D]
** rotate both stack 'A' & stac 'B'
** checker is always '0' or '1'
*/
void	rr(t_stack **a, t_stack **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}