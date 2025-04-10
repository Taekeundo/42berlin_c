#include "push_swap.h"
/* [D]
** Matrix starts from -1
** because 'i' artificially made Up??
** [i] 왜 이게 -1부터 꼭 시작해야하는지 잘 모르겠다.
*/
void	freeMatrix(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)	// argv가 가리키는 포인터가 가리키는 값이 NULL이거나 argv가 가리키는 값이 NULL이거나
		return ;						// free할 필요가 없다.
	while (argv[i++])					// argv[i]가 가리키는 값이 존재하는동안 // (ex) v[0]이 가리키는 값이 존재한다면 '\0'이라도 존재한다면.
		free(argv[i]);					// 할당 해제
	free(argv - 1);						// main에서 실행 된 argv -1 (ex) "42 132 23" 전체를 free한다.
	return ;
}

/* [D]
** 오류 발생했을때 그동안 할당된 stack이 가리키는것들이 가리키는 메모리를 해지하고, 마지막에 stack이 가리킨것도 해지해주는 함수.
** 더블포인터!! 속 내용 먼저 해지 && 포인터 해지!!
*/
void	freeStack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (stack == NULL)			// 이미 stack이 NULL이라면 free할게 없다 -> 함수 종료
		return ;
	current = *stack;			// stack이 가리키는것을 current에 복사한다.
	while (current)				// NULL을 가리키지 않는동안 (ex) argv[0], argv[1], argv[2], argv[3]는 NULL을 가리키지 않는다. argv[4]는 NULL을 가리킨다.
	{
		tmp = current->next;	// current가 가리키는 대상의 next -> 다른말로 stack의 node가 가리키는 next값을 tmp에 복사한다.
		free(current);			// current를 free해준다.
		current = tmp;			// current에 next node를 복사해준다. -> "다음노드 가리키고 현재노드 해제" 반복!
	}
	*stack = NULL;				// while문에서는 current에 값을 복사해서 stack이 가리키는 값들을 해지한거지, stack은 아직 해지되지 않았다. 그래서 따로 해주는거다.
	return ;
}

/* [D]
** main함수에서 stack_init함수의 3번째 parameter인 "bool flag_argc_2"의 실제 값은 "argc == 2"다.
** 만약 argc가 2개라면 참(1)이다. "flag_argc_2"의 return값은 1이 된다.
*/
void	errorFree(t_stack **a, char **argv, bool flag_argc_2)
{
	freeStack(a);				// free stack 'a' (first parameter)
	if (flag_argc_2)			// flag의 값이 1이라면 (argc == 2가 참)이라면.
		freeMatrix(argv);		// Double array에서 먼저 속 값들을 free해주고 그걸 가리키는 pointer도 free해준다.
	write(2, "Error\n", 6);		// flag가 0이라면 -> argc가 2개가 아니란 소리다. -> "Error"
	exit(1);					// 'main'함수 종료!
	return ;
}

/* [D]
** Check validity from input
** 인풋값들이 subject조건에 맞는지 체크하는 함수
*/
int	validateInput(char *str_nbr)
{
	if (!(*str_nbr == '+'
			|| *str_nbr == '-'
			|| (*str_nbr >= '0' && *str_nbr <= '9')))	// +, -, 0<= x <= 9 아닐 경우 return(1).
		return (1);
	if ((*str_nbr == '+'
			|| *str_nbr == '-')
		&& !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

/* [D]
** 만약 argv[i]가 같은 숫자를 가리킨다면 error!
*/
int	errorRepetition(t_stack *a, int nbr)
{
	if (a == NULL)				// a가 아무것도 가리키지 않는다면 함수종료.
		return (0);
	while (a != NULL)			// a가 next를 가리키는 동안
	{
		if (a->value == nbr)	// a가 가리키는 구조체의 value값이 nbr(현재 '42')일 경우 프로그램 종료
			return (1);
		a = a->next;			// 아니라면 a는 다음 노드를 탐색한다.
	}
	return (0);
}
