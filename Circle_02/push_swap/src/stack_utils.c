#include "push_swap.h"

/* [D]
** Search for the current last node and append
*/
t_stack	*find_curr_last_node(t_stack *head)	// 헤드노드를 통해 마지막
{
	if (head == NULL)		// 헤드노드가 NULL을 가리킨다는건 현재 노드가 없다는 의미다.
		return (NULL);
	while (head->next)		// head가 가리키는 대상의 next가 가리키는 대상이 NULL이 아니라면 (존재한다면)
		head = head->next;	// head가 가리키는걸, head가 가리키는 대상의 next가 가리키는것으로 대체한다. (다음으로 넘어간다), while문을 통해 next가 NULL을 가리킬때까지(마지막노드) 간다.
	return (head);			// 그리고 최종적으로 'head포인터'를 리턴한다. head라는 포인터가 가리키는것!
}

/* [D]
** if와 else로 나눈 이유! 초반에 node가 없을 경우 첫 노드를 생성해줘야하기 때문에.
** (caution) stack == NULL, *stack == NULL.
*/
void	append_node(t_stack **stack, int nbr)
{
	t_stack	*new_node;
	t_stack	*curr_last_node;

	if (stack == NULL)					// 파라미터로 들어온 stack의 더블포인터가 존재하지 않는다면: 'A' points to something -> something points to t_stack. // A -> something -> t_stack.
		return ;						// A라는 스택 자체가 애초에 존재하지 않느냐는걸 묻는 if문이다.
	new_node = malloc(sizeof(t_stack));	// '스택구조체' 크기 만큼 메모리 할당, 할당실패시 함수 종료
	if (new_node == NULL)
		return ;
	new_node->next = NULL;				// node의 다음값이 NULL을 가리킨다. (마지막 노드로 사용할꺼니까)
	new_node->value = nbr;				// 값에는 nbr값을 복사해준다. (마지막 노드에 들어갈 값이 nbr)
	if (*stack == NULL)					// stack이라는 포인터가 가리키는 대상의 값이 NULL일 경우 (stack이 가리키는 포인터 a가 가리키는 값이 NULL일 경우)
	{									// &stack 자체는 존재하지만 그 값이 NULL일 경우 -> 아직 아무 '노드'도 존재하지 않을 경우
		*stack = new_node;				// new_node가 가리키는걸 stack이 가리키도록 복사해준다. head_node로서 new_node가 가리키는 값을 복사해준다.
		new_node->prev = NULL;			// 노드의 prev에는 NULL을 넣어준다. 아무것도 이전것을 가리키지 않는다.
	}									// !! 처음 노드를 연결해줄때 사용한다.
	else
	{
		curr_last_node = find_curr_last_node(*stack);	// 기존 마지막 노드를 찾은 뒤 curr_last_node에 복사해준다.
		curr_last_node->next = new_node;				// 기존 마지막 노드 next에 new_node를 연결시켜준다.
		new_node->prev = curr_last_node;				// new_node(이제는 이게 마지막 노드가 된다)prev로 curr_last_node와 연결해준다.
	}
}

/* [D]
** Return the pointer to node, which has smallest value.
** 가장 작은 value값을 가진 노드를 가리키는 포인터를 찾아 반환하는 함수.
*/
t_stack	*find_smallest(t_stack *stack)
{
	long	smallest;
	t_stack	*smallest_node;

	if (stack == NULL)		// stack이 아무것도 가리키고 있지 않을 경우 (더 이상 분류할게 없을 경우) -> 가장 작은 값을 찾을 필요없음 -> 함수종료
		return (NULL);
	smallest = LONG_MAX;	// integer중 가장 큰 값. 선언된 헤더파일 <limit.h>을 통해 확인.
	while (stack)			// stack이 가리키는 노드의 next가 NULL을 가리키지 않는동안 -> 처음노드부터 마지막 노드까지.
	{
		if (stack->value < smallest)	// 만약에 값이 작으면
		{
			smallest = stack->value;	// smallest (값) 교체
			smallest_node = stack;		// smallest (노드) 교체
		}
		stack = stack->next;			// 다음 노드 가리키기. while문에서 int count (count++)와 같은 개념.
	}
	return (smallest_node);	// 가장 작은 노드를 가리키는 pointer (return)
}

/* [D]
** Return the pointer to cheapest node.
** (variable)cheapest, which is bool type in struct = [Flag] for checking, which cheapest field is 1(true) or not.
** 언제 쓰이는지는 아직 모름.
*/
t_stack	*return_cheapest(t_stack *stack)
{
	if (stack == NULL)	// 함수 할당 실패 -> 가리키지 않는다면 또는 stack의 노드가 없다면
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)	// cheapest: bool type. (stack->cheapest != 0) -> (cheapest==true(1))을 물어보는 조건문이다.
			return (stack);		// 가장 적은 price를 갖은 최초의 stack이 맞다면 그 포인터 출력
		stack = stack->next;	// 아니면 다음 노드 확인
	}
	return (NULL);	// 어차피 while문에서 함수의 결과값은 100% return된다. (형식적으로 함수의 형태를 위해 써줬을뿐이다)
}

/* [D]
** stack에 저장된 노드의 갯수를 구하는 함수
** head노드의 포인터만 연결되면 나머지는 자동으로 측정된다.
*/
int	stack_len(t_stack *stack)
{
	int	count;

	if (stack == NULL) // a스택이 NULL을 가리킨다면 -> 아무것도 가리키지 않는 경우 -> 길이 잴 수 없음 -> 함수종료
		return (0);
	count = 0;
	while (stack)	// stack이 가리키는 노드가 존재할 경우 (마지막 node를 만날때까지)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}