#include "push_swap.h"

/* [D]
** Check if a given stack is sorted
*/
bool	flag_stack_sorted(t_stack *stack)
{
	if (stack == NULL)		// 현재 node가 아무것도 가리키지 않는다면, 분류할게 없음 -> 함수종료(true로 안써주고 1로 써준 이유: 분류할게 없는것과 분류가 되있는건 다른거다)
		return (1);
	while (stack->next)		// node의 next가 존재할때
	{
		if (stack->value > stack->next->value)	// 현재 노드와, 다음노드의 value값을 비교
			return (false);						// 현재 노드의 값이 더 클 경우 ascending조건에 맞지않음 -> 분류 필요함 -> 거짓 false
		stack = stack->next;					// stack이 가리키는 값 다음 노드를 가리킨다.
	}											// 모든 노드의 앞,뒤 관계를 비교하며 분류가 필요한지 살펴본다.
	return (true);
}

/* [D]
** 모든 노드를 순서대로 검사해서 노드.value중 어떤 pointer가 가장 큰 노드를 지정하고 있는지 return한다.
** Check all nodes sequentially and find which pointer to node has highest value inside.
*/
static t_stack	*find_highest(t_stack *stack)
{
	int				highest;			// for checking value in node.
	t_stack	*highest_node;

	if (stack == NULL)					// no node
		return (NULL);
	highest = INT_MIN;					// Headerfile(limit.h) // Current highest value is INT_MIN.
	while (stack)						// Until node doesn't point NULL
	{
		if (stack->value > highest)		// check value in node, if it is bigger than highest.
		{
			highest = stack->value;		// cpy value in current node to highest.
			highest_node = stack;		// According to value of highest, highest_node is also changed.
		}
		stack = stack->next;			// stack points next node.
	}
	return (highest_node);				// pointer is type the return value of this function.
}

/* [D]
** For 3 nodes, easy to sort.
** If the 1* is the biggest, ra (biggestto bottom)
** If the 2* is the biggest, rra (biggest to bottom)
** The Biggest is now at the bottom.
*/
void	tiny_sort(t_stack **a)
{
	t_stack	*highest_node;					// target_node for highest value between 3 nodes.

	highest_node = find_highest(*a);		// cpy *highest to *node. (now highest_node pointer points highest_node)
	if (*a == highest_node)					// If first node on stack 'A' is biggest, ra --> send first node(biggest) to bottom.
		ra(a, false);
	else if ((*a)->next == highest_node)	// If second node on stack 'A' is biggest, rra --> send third node to bottom --> (previous second node=biggest)is now on bottom.
		rra(a, false);						// The three nodes have already been arranged in ascending order through over (if, else if) conditions.
	if ((*a)->value > (*a)->next->value)	// If biggest node is already on bottom, but first node's value is smaller than second node's
		sa(a, false);						// Do swap(top two values from stack 'a').
}

/* [D]
** Handle for 5 nodes as input.
** node개수가 3개 될 때까지, a노드 중 가장 작은 노드를 찾아 b로 보낸다.
*/
void	handle_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)							// a스택에 노드가 3개 초과하는 동안
	{
		init_nodes(*a, *b);								// Fill all fields of t_stack 'A' & 'B'. (Initialize both nodes.)
		finish_rotation(a, find_smallest(*a), 'a');		// a스택에서 -> 가장 작은 노드가 가장 위에 올때까지 rotate실행 -> a스택이기 때문에 ra, rra가 실행 되도록 flag값 설정.
		pb(b, a, false);								// sent top node(smallest) from stack'A' to stack'B' until the number of nodes in stack 'a' equal 3.
	}
}