#include "push_swap.h"

/* [D]
** Bottom to top
*/
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	int				len;

	len = stack_len(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last = find_curr_last_node(*stack);
	last->prev->next = NULL;				// *(last - 1)의 next값을 NULL로 만들어준다.
	last->next = *stack;					// last노드는 이제부터 기존의 first_node를 가리킨다.
	last->prev = NULL;						// last노드는 이제부터 first_node가 되었기 때문에, prev값에 NULL을 넣어준다.
	*stack = last;							// *stack은 이제부터 last노드를 가리킨다.
	last->next->prev = last;				// last->next: 기존 first_node의 prev값이 last를 가리키게 한다.
}

/* [D]
** a스택의 가장 아래 노드를 가장 위로 올린다.
*/
void	rra(t_stack **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

/* [D]
** b스택의 가장 아래 노드를 가장 위로 올린다.
*/
void	rrb(t_stack **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

/* [D]
** a,b스택의 가장 아래 노드를 가장 위로 올린다.
*/
void	rrr(t_stack **a, t_stack **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}