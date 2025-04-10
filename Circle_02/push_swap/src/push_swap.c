#include "push_swap.h"

/*	[D]
**	Rotate two stacks, a and b, simultaneously until the specified conditions are met.
**	스택 A의 top노드가 (cheapest_node->target_node)가 될 때까지 수행한다.
**	cheapest는 stack'B'로부터 (price)필드의 값이 가장 낮은 최초의 노드를 의미한다.
*/
static void	rotate_both(t_stack **a,
						t_stack **b,
						t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)					// a의 top(=head)노드가 cheapest_node의 타겟노드가 아닐 경우 && cheapest_node가 b의 top(=head)노드가 아닐 경우 (= 아직 아래 있다면) -> 그 외에 둘 중 하나라도 해당하는 경우에는 rr을 사용할 수 없다.
		rr(a, b, false);						// a,b를 두개 다 돌린다.
	set_current_position(*a);					// a,b모두 돌렸으니 순서가 변경되었기 때문에, 새로 position값을 부여해준다.
	set_current_position(*b);
}

/*	[D]
**	rotate_both의 반대 개념
*/
static void	reverse_rotate_both(t_stack **a,
								t_stack **b,
								t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

/* [D]
** 스택에서 원하는 노드가 top으로 올 때까지 계속 rotate하는 function. 
*/
void	finish_rotation(t_stack **stack,
							t_stack *final_top_stack,
							char stack_name)	// (param1)타겟 스택, (param2)타겟노드(Top에 위치시키고 싶은), (param3) flag역할 == 어떤 스택(a || b)에서 rotate할지에 따라 그에 맞는 function(ra, rb, rra, rrb)을 사용해야하기때문에.
{
	while (*stack != final_top_stack)			// final_top_stack스택이 맨 위에 올 때까지 계속 반복한다.
	{
		if (stack_name == 'a')					// 만약 (param3)스택 이름이 'a'일 경우
		{
			if (final_top_stack->above_median)			// 가장 위 노드의 above_median값이 1인 경우 (true) // 중간line보다 위에 있는 경우
				ra(stack, false);				// final_top_stack보다 위에 있는 노드들을 위에서부터 하나씩 rotate하는게 빠르니까 [F]ra를 사용한다.
			else
				rra(stack, false);				// 중간 line보다 아래 있는 경우 rra가 더 빠르니까 그거 사용한다.
		}
		else if (stack_name == 'b')				// b스택도 a와 마찬가지.
		{
			if (final_top_stack->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}

/* [D]
** Find cheapest_node from stack 'B' & target_node from cheapest_node from stack 'A'.
** Condition check, whether can use the function (rr || rrr)
** (After if, else if condition)
** Rotate nodes from stack 'B' first to move cheapest_node to the top of stack 'B'.
** Rotate nodes from stack 'A' first to move target_node to the top of stack 'A'.
** push top node from stack 'B' (cheapest_node) to stack 'A'.
*/
static void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = return_cheapest(*b);					// b스택에서 가장 효율적인 노드(cheapest)를 찾아 포인터를 복사한다.
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)		// cheapest노드가 중간라인보다 위에 위치하고 && 그 노드의 target_node 또한 중간라인보다 위에 위치할 경우
		rotate_both(a, b, cheapest_node);					// a,b스택을 동시에 rotate시킨다. 한 스택씩 rotate하면 더 오래걸리니까, 시간 단축시키려고 만든 함수다.
	else if (!(cheapest_node->above_median)					// 그게 아니라면 // cheapest노드(in 'B')와 target노드(in 'A')가 모두 중간라인보다 아래 있을 경우
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);			// 동시에 r-rotate.
	finish_rotation(b, cheapest_node, 'b');					// B스택에서 cheapest노드가 가장 위로 올 때 까지 계속 돌린다.
	finish_rotation(a, cheapest_node->target_node, 'a');	// A스택에서 cheapest노드가 가장 위로 올 때 까지 계속 돌린다.
	pa(a, b, false);										// B스택의 cheapest노드를 A스택으로 보낸다.
}

/* [D]
** sort function.
*/
void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;				// 가장 작은 value를 갖고있는 t_stack구조체를 가리키는 포인터
	int				len_a;			// (A스택) 노드 개수 담아 둘 integer.

	len_a = stack_len(*a);			// (A스택) 노드 개수 체크.
	if (len_a == 5)					// (A스택) 노드 5개 -> 3개 남을때까지 b로 이동.
		handle_five(a, b);
	else
	{
		while (len_a-- > 3)			// (A스택) 노드 개수 3개 될 때까지, 노드를 (B스택)으로 push.
			pb(b, a, false);
	}
	tiny_sort(a);					// (A스택) 노드 3개 전용 sort함수.
	while (*b)
	{
		init_nodes(*a, *b);			// 줄세우기
		move_nodes(a, b);			// cheapest_node && target_node 찾아서 rotate시키고 정렬 -> while루프 반복.
	}
	set_current_position(*a);		// 순서 다시 부여 // give the new position after while loop.
	smallest = find_smallest(*a);	// (A스택) 가장 value값 작은 node포인터 복사.
	if (smallest->above_median)		// 위치가 중간라인보다 위에 있다면
		while (*a != smallest)		// smallest노드가 top position으로 올 때까지 계속 rotate execute(실행).
			ra(a, false);
	else
		while (*a != smallest)		// 위치가 중간라인보다 아래에 있다면
			rra(a, false);			// smallest노드가 top position으로 올 때까지 계속 reverse rotate execute(실행).
}