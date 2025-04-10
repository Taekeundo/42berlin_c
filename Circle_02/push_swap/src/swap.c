#include "push_swap.h"

/* [D]
** argv[i][j] == **argv == *argv[] 모두 같은 의미다.
** *argv[1]의 경우 사용자 입력값 중 첫번째 노드를 의미한다. (이미 ft_split으로 parameter값이 나눠져 있다.)
** (example) *argv[1] == {42 1180}; // 2개로 구성되어있을 경우
** 			*head는 항상 첫번째 노드인 '42'의 주소를 가리킨다.
** 			*head + 1은 그 다음 노드인 '1180'의 주소를 가리킨다.
** 순서를 기억하자.
** 1. *head (from A to B) // 첫번째 노드 B로 변경
** 2. A->prev: B && A->next: C // 노드 A를 두번째 위치로 변경했다는 가정으로 prev, next값 변경
** 3. C가 존재하는지 확인 (C의 next가 NULL일 경우 if문 안들어감) // 만약 *C가 NULL일 경우 A->next는 NULL을 가리킨다.
** 4. B->next: A && B->prev: NULL // 노드 B를 첫번째 위치로 변경했다는 가정으로 prev, next값 변경
*/
static void	swap(t_stack **head)
{
	int	len;

	len = stack_len(*head);
	if (*head == NULL || head  == NULL || len == 1)	// head가 아무것도 가리키지 않거나, head가 가리키는 포인터가 아무것도 가리키지 않거나, 길이기 1(헤드노드만 존재할 경우) swap할꺼 없음 -> 함수종료
		return ;									// 0. *head == &A. [ head -> "A B C D" ]
	*head = (*head)->next;							// 1. [ head -> "B C D" ] == now (*head) is &B (not &A). // A를 가리키던 head포인터가 이제 B를 가리킨다.
	(*head)->prev->prev = *head;					// 2. [Change A's prev] // On 'B'->prev(='A')->prev(='head') cpy B == now [A->prev] is 'B'.
	(*head)->prev->next = (*head)->next;			// 3. [Change A's next] // On 'B'->prev(='A')->next(='B') cpy C(=B's next) == now [A->next] is 'C'.
	if ((*head)->next)								// B's next exist (존재한다면), 현재 C로 존재한다.
		(*head)->next->prev = (*head)->prev;		// 4. [Change C's prev] // On 'B'->next(='C')->prev(='B') cpy A(=B's prev) == now [C->prev] is 'A'.
	(*head)->next = (*head)->prev;					// 5. [Change B's next] // On 'B'->next cpy A(=B's prev) == now [B->next] is 'A'.
	(*head)->prev = NULL;							// 6. [Change B's prev] // On 'B'->prev cpy NULL == now [B->prev] is 'NULL'.
}

/* [D]
** a스택 위 2개 자리 변경
** parameter_checker: false인 경우 -> 분류가 필요하다는 말이다.
** parameter_checker: true인 경우 -> 참이기 때매 분류가 필요 없다.
** 분류가 필요할때만 sa함수를 실행하기 위해서 checker를 함수에 만들어뒀다.
** (example) stack_len함수의 결과가 2일 경우 sa(&a, false); 이런식으로
** 처음부터 false플래그를 사용해서 무조건 sa가 실행 될 수 있게 만든다.
** 이미 'flag_stack_sorted'함수 안으로 들어왔다는건 무조건 분류가 필요하다는 소리인데
** stack_len를 해보니까 2가 나왔다는건 -> 2개의 노드에 값이 저장되어있는데 위치를 바꾸란 소리다.
** 이럴때 flag를 사용해서 무조건 함수가 실행되고, sa를 출력하게 만들어주면 된다.
*/
void	sa(t_stack	**a, bool checker)
{
	swap(a);
	if (!checker)				// checker를 flag로 사용해서 필요에 따라 메시지를 출력한다.
		write(1, "sa\n", 3);
}

/* [D]
** b스택 위 2개 자리 변경 (sa와 기능 동일한 함수)
*/
void	sb(t_stack **b, bool checker)
{
	swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

/* [D]
** a스택, b스택 한꺼번에 맨 위 2개 노드 값 변경
*/
void	ss(t_stack **a, t_stack **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}