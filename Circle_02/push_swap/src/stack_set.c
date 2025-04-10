#include "push_swap.h"

/* [D]
** Set the current_position of every node (first_node's current_position) is 0.
** Set the above_median of every node (first_node's above_medain) is 1 (true).
** *argv[1]의 갯수가 홀수든, 짝수든 상관없이 (중간값 + 1)순서까지 above_median값을 true(1)로 넣어준다.
*/
void	set_current_position(t_stack *stack)
{
	int	i;
	int	mid_position;

	i = 0;
	if (stack == NULL)
		return ;
	mid_position = stack_len(stack) / 2;	// 최종 개수를 반으로 쪼개어 median(중앙값)을 구한다.
	while (stack)							// 다음 node가 연결되어있는 동안
	{
		stack->current_position = i;		// 가장 첫번째 노드의 current_position값에 i를 넣는다. (ex) 첫번째 노드는 이제부터 0번째 순서다.
		if (mid_position >= i)				// 1개 이상일 경우 (ex) *argv[1]:2개 -> mid_position == 2/2; == 1 -> (1 >= 0) true.
			stack->above_median = true;		// 현재 노드가 중앙 노드보다 위에 있으면 above_median(type: bool)변수에 true(1)을 넣는다.
		else
			stack->above_median = false;	// 현재 노드가 중앙 노드보다 아래 있으면 above_median(type: bool)변수에 false(0)을 넣는다.
		stack = stack->next;				// 모든 노드(처음 ~ 끝)의 above_median값을 채워준다.
		i++;
	}
}
/* Example (1) Even numbers
**	 		 stack 'A'		above_median
**	[0]			6				true
**	[1]			3				true
**	[2]			9				true
**	[3]			8				false
**
**	mid_position = 2 (stack_len(A)(= 4) / 2)
**	(if) 				(mid_position >= i)
**		i = 0;	|			2 >= 0 (Okay)		stack[A][0]'s above_median: true (1)
**		i = 1;	|			2 >= 1 (Okay)		stack[A][1]'s above_median: true (1)
**		i = 2;	|			2 >= 2 (Okay)		stack[A][2]'s above_median: true (1)
**	(else) 			
**		i = 3;	|			3 >= 2 (No)			stack[A][3]'s above_median: false (0)
**
** Example (2) Odd numbers
**	 		 stack 'B'		above_median
**	[0]			5				true				
**	[1]			7				true
**	[2]			1				true
**	[3]			2				false
**	[4]			11				false
**
**	mid_position = 2,5 (stack_len(A)(= 5) / 2) but type of (mid) is integer. so round down value.
**	(if) 				(mid_position >= i)
**		i = 0;	|			2 >= 0 (Okay)		stack[B][0]'s above_median: true (1)
**		i = 1;	|			2 >= 1 (Okay)		stack[B][1]'s above_median: true (1)
**		i = 2;	|			2 >= 2 (Okay)		stack[B][2]'s above_median: true (1)
**	(else) 			
**		i = 3;	|			2 >= 3 (No)			stack[B][3]'s above_median: false (0)
**		i = 4;	|			2 >= 4 (No)			stack[B][3]'s above_median: false (0)
**
**	[Conclusion]
**	Even numbers in stack:	Until (mid_position + 1), above_median: true.
**	Odd numbers in stack:	Until (mid_position - 0.5), above_median: true.
*/

/* [D]
** Best matching value among stack 'A', which is smallest-bigger node with value from stack 'B'.
** [a][i] = -20 32 3 7; [b][j] = -10 27 2 6 --> target_node[b][1] == [a][1], [b][2] == [a][2] ...
** Finds and sets the most appropriate target node in stack 'A' for each node in stack 'B'.
** Smallest-greater value: closest value in stack 'A' that is greater than the node in the current b stack.
** Every node in stack 'B' gets its target node in stack 'A'.
** !! If no node is Bigger, best_match is the Smallest node !!
** Not exactly 1:1 correspondence function, but almost simular function.
** A스택 노드 하나씩 체크하면서 (curr)b's top value보다 가장 가깝게 큰 값을 가진 a's top을 찾아 매칭한다.
*/
static void	set_target_node(t_stack *a,
							t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long			best_match_index;

	while (b)												// while in while // check all nodes, before ending of stack 'B'.
	{
		best_match_index = LONG_MAX;						// cpy value of LONG_MAX to 'best_match_index'. (while(b) 초기화값)
		current_a = a;										// cpy the pointer (to current's node from stack 'A') to the pointer (current_a).
		while (current_a)
		{													// 2 conditions
			if (current_a->value > b->value					// (1) top value from stack 'a' > stack 'b'.
				&& current_a->value < best_match_index)		// (2) top value from stack 'a' < best_match_index (first try: Long_MAX, second try: value from first node from 'A')
			{
				best_match_index = current_a->value;		// 'best_match_index' is now top value from stack 'A'.
				target_node = current_a;					// cpy the pointer (to current's node from stack 'A') to the pointer to (target_node).
			}
			current_a = current_a->next;					// retry all process in (current_a = stack'A').
		}
		if (best_match_index == LONG_MAX)					// best_match_index값이 초기 설정한 LONG_MAX에서 변화없다는건 -> b스택의 현재 '노드' 값 보다 큰게 a스택에 없음을 의미한다. // b의 가장 큰 값은 a의 가장 작은값을 가리키게 한다.
			b->target_node = find_smallest(a);				// In the field of target_node from stack'B', cpy node, has smallest value, in stack 'A'.
		else
			b->target_node = target_node;					// b노드 순서마다 (curr)value.b와 가장 가까운 target_node(stack'A'에서)를 연결해준다.
		b = b->next;
	}
}
/* Example [F]set_target_node
** 
**	 		 stack 'A'        stack 'B'
**	(curr)		6				  5			(curr)
**				3				  7
**				9				  1
**				8				  2
**
**	1st loop
**      top'A' > top'B		&&	(curr)A < best_match_index							 best_match_index		target_node of [b][1]
**		  6 > 5 (Okay)		&& 		6	< LONG_MAX (Okay)		Go to (if) 				    6		 		   [a][1]
**		  3 > 5 (NO)		&&		3	<   6  (Okay)	   		Not go to (if)				-					 -
**		  9 > 5 (Okay)		&&		9	<   6  (NO)				Not go to (if)				-					 -
**		  8 > 5 (Okay)		&&		8	<   6  (NO)				Not go to (if)				-					 -
**
**		[b][1]->target_node: [a][1]
**		(init) best_match_index: LONG_MAX
**
**	 		 stack 'A'        stack 'B'
**	(curr)		6				  5		  
**				3				  7			(curr)
**				9				  1
**				8				  2
**
**	2nd loop
**      top'A' > top'B	  	&&	(curr)A < best_match_index							 best_match_index		target_node of [b][2]
**		  6 > 7 (No)		&& 		6	< LONG_MAX (Okay)		Not go to (if) 			 LONG_MAX				NULL
**		  3 > 7 (No)		&&		3	< LONG_MAX (Okay)  	   	Not go to (if)				-					 -
**		  9 > 7 (Okay)		&&		9	< LONG_MAX (Okay)		Go to (if) 					9		 		   [a][3]
**		  8 > 7 (Okay)		&&		8	<   9  (Okay)			Go to (if) 					8		 		   [a][4]
**
**		[b][2]->target_node: [a][4]
**
**	 		 stack 'A'        stack 'B'
**	(curr)		6				  5		  
**				3				  7
**				9				  1			(curr)
**				8				  2
**
**	3rd loop
**      top'A' > top'B	  	&&	(curr)A < best_match_index							 best_match_index		target_node of [b][2]
**		  6 > 1 (Okay)		&& 		6	< LONG_MAX (Okay)		Go to (if) 					6		 		   [a][1]
**		  3 > 1 (Okay)		&&		3	<   6  (Okay)		   	Go to (if) 					3		 		   [a][2]
**		  9 > 1 (Okay)		&&		9	< 	3  (No)				Not go to (if)				-					 -
**		  8 > 1 (Okay)		&&		8	<   3  (No)				Not go to (if)				-					 -
**
**		[b][3]->target_node: [a][2]
**
**	 		 stack 'A'        stack 'B'
**	(curr)		6				  5		  
**				3				  7
**				9				  1
**				8				  2			(curr)
**
**	4th loop
**      top'A' > top'B	  	&&	(curr)A < best_match_index							 best_match_index		target_node of [b][2]
**		  6 > 2 (Okay)		&& 		6	< LONG_MAX (Okay)		Go to (if) 					6		 		   [a][1]
**		  3 > 2 (Okay)		&&		3	<   6  (Okay)		   	Go to (if) 					3		 		   [a][2]
**		  9 > 2 (Okay)		&&		9	< 	3  (No)				Not go to (if)				-					 -
**		  8 > 2 (Okay)		&&		8	<   3  (No)				Not go to (if)				-					 -
**
**		[b][4]->target_node: [a][2]
**
**	[Conclusion]
**						   *target_node
**	[b][1]:5	--match--	[a][1]: 6
**	[b][2]:7	--match--	[a][4]: 8
**	[b][3]:1	--match--	[a][2]: 3
**	[b][4]:2	--match--	[a][2]: 3
*/

/* [D]
** Set the prices, every node has respective price.
** Price means, "How many moves to bring to the top".
** The price is proportial to the position and the length. 
** The price checks for the relative positions in the stack.
** 한마디로 정렬이 필요한 총 횟수를 의미한다.
*/
void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);														// check how many *argv[1] is there in both stack 'A' and 'B'.
	len_b = stack_len(b);														// 두개의 길이를 알아야 median을 사용 할 수 있다.
	while (b)
	{
		b->push_price = b->current_position;									// 몇번째 노드인지 의미하는 current_position값을 price에 복사한다.
		if (!(b->above_median))													// 현재 노드가 중간순서보다 뒤(아래)에 있다면 // If the target node is not above the median in stack 'B'.
			b->push_price = len_b - (b->current_position);						// (예를들어) B스택 가장 아래 있는 노드의 경우 길이 4, 순서 3 == 4 - 3 == 1 // price:1 // 1번만 움직이면 push할 수 있다.
		if (b->target_node->above_median)										// 중간보다 위에 있다면 (bool: treu == 1)
			b->push_price += b->target_node->current_position;					// target_node의 현재 포지션 값을 더해준다. 
		else
			b->push_price += len_a - (b->target_node->current_position);		// a노드의 길이에서 - 타겟노드의 현재포지션을 빼주고 그걸 b's push_price에 더해준다.
		b = b->next;
	}
}
/* Example
**
**	 stack 'A'        stack 'B'			price
**	[a][0] = 3		 [b][0] = 2		  	  0			already on the top.
**	[a][1] = 5		 [b][1] = 4		  	  2			on stack 'B', [b][1] swap 1 time + on stack 'A', [a][1] swap 1 time = total 2 times.
**	[a][2] = 7		 [b][2] = 6		  	  1			on stack 'B', [b][1] rotate 1 time + on stack 'A', [a][1] ro 1 time = total 2 times.
**
**	Check node [b][1]
**	1. len_a == 3 && len_b == 3
**	2. [b][1]'s current_position = '1' // [b][1]'s initial price = '1' // 일단 top이 아니고서는 무조건 1번은 움직이여 하기 때문에 +1 해준다.
**	3. bool([b][1] true?) -> true -> condition not met, so not into (if)condition
**	4. bool([b][1]'s target_node = [a][1] true?) -> true -> into the second (if)condition.
**		[b][1]'s push_price:1 + [a][1]'s current_position:1 = 2(Final price)
**	5. check next node 'B'. -> [b][2]
**
**	Check node [b][2]
**	1. len_a == 3 && len_b == 3
**	2. [b][2]'s current_position = '2'
**	3. bool([b][1] true?) -> false -> go into first (if)condition.
**		len_b(3) - b's current_position(2) = 1 (Final price)
**	4. bool([b][1]'s target_node = [a][2] true?) -> condition not met, so not into (if)condition
*/

/* [D]
** Flag for the cheapest node.
** target_node, current_position을 고려하여 push할때 상대적으로 움직임이 가장 적은 node(효율적인 노드)를 cheapest로 설정하고 그게 맞는지 bool함수로 체크한다.
*/
void	set_cheapest(t_stack *b)
{
	long		best_price;					// 값 저장을 위한 변수
	t_stack		*best_price_node;			// cheapest노드를 가리키는 포인터

	if (b == NULL)							// If no connection with stack.
		return ;
	best_price = LONG_MAX;					// 기준, 첫 while에서 어떤 값이든 LONG_MAX보단 작기 때문에. 만약 같다면 다음 노드로.
	while (b)
	{
		if (b->push_price < best_price)		// 노드를 쭉 체크한다. // push_price값이 가장 적은값을 마주했을경우 // 여러개의 노드의 best_price가 같을 경우 첫번째 best_price가 선택된다.
		{
			best_price = b->push_price;		// 그 값을 best_price에 넣어준다.
			best_price_node = b;			// 그 노드를 가리킨다.
		}
		b = b->next;						// 다음 노드로 이동.
	}
	best_price_node->cheapest = true;		// 해당노드의 cheapest필드에만 true, 나머지 노드들의 cheapest필드에는 값이 담기지 않는다.
}

/* [D]
 * All the necessary values to make the push
 * 		~Relative Positions
 * 		~Target node, the b node to make emerge
 * 		~Price for every configuration
 * 		~Cheapest in the current configuration
*/
void	init_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);	// give 'current_position' and 'above_median' of every node in stack 'A'.
	set_current_position(b);	// give 'current_position' and 'above_median' of every node in stack 'B'.
	set_target_node(a, b);		// Matching , which closest value between pointer in stack 'B' to point to stack 'A'. Value 'B' has to be smaller than Value 'A'. Stack 'A' doesn't have any target_node. Only B can have.
	set_price(a, b);			// Put the price(type: int) to every node. price means "How many moves to bring to the top".
	set_cheapest(b);			// Among the best price nodes, choose first node, and only this node has '1(true)_type: bool' in the cheapeat field.
}