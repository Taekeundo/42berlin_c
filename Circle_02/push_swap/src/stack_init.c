#include "push_swap.h"

/* [D]
** Converting every string type(made of ASCII) into a 'long'type.
** atoi랑 동일한 기능이고 long만 사용했을뿐이다.
** Goal: checking overflow
** Static type을 사용해서 함수가 종료된 이후에도 value를 사용 할 수 있다.
*/
static long	ft_atol(const char *pAscii)
{
	int		i;
	long	num;
	int		flagNegative;
	
	i = 0;
	num = 0;
	flagNegative = 1;
	while (pAscii[i] && (pAscii[i] == ' ' || pAscii[i] == '\t'
			|| pAscii[i] == '\n' || pAscii[i] == '\r'
			|| pAscii[i] == '\v' || pAscii[i] == '\f'))
		i++;
	if (pAscii[i] == '+')
		i++;
	else if (pAscii[i] == '-')
	{
		flagNegative *= -1;
		i++;
	}
	while (pAscii[i] >= '0' && pAscii[i] <= '9')
	{
		num = (num * 10) + (pAscii[i] - '0');
		i++;
	}
	return (num * flagNegative);
}

/* [D]
** !!Create!!
**		the stack with the command line values
** !!Check Error!! 
**		1. Input errors: [F]validateInput
** 		2. Over|Underflow
**		3. Duplicate values: [F]errorRepetition
** !!Save value to stack!!
** 		1. use [F]ft_atol
**		2. use [F]append_node
** !!Memo!!
**		long사용 이유: input으로 들어오는 모든 integer를 다 받기 위해
** !!🏁Flag!!
** (bool타입의 flag_argc_2)이 가능할때만 argv[i][j] 더블어레이에 값들이 할당되기때문에 그런 상황들을 구분하기 위해 flag를 사용한다.
*/
void	stack_init(t_stack **a, char **argv, bool flag_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (validateInput(argv[i]))					// validateInput함수가 true(1)일 경우 errorFree함수 호출
			errorFree(a, argv, flag_argc_2);		// flag판별: argc 2개 맞다면 -> freeMatrix함수 실행 -> a스택의 argv값을 free
		nbr = ft_atol(argv[i]);						// convert the data's type from Character to Long. And cpy argv[i]가 가리키는 값을 nbr에 복사한다.
		if (nbr > INT_MAX || nbr < INT_MIN)			// check over- and underflow. Whether nbr is within the range of integer.
			errorFree(a, argv, flag_argc_2);		// flag판별: argc 2개 맞다면 -> freeMatrix함수 실행 -> a스택의 argv값을 free
		if (errorRepetition(*a, (int)nbr))			// argv[i]가 같은 숫자를 "가리킨"다면 error! // 여기서 a라는 포인터가 가리키는 포인터가 가리키는 값 (실제 2차 배열에 존재하는 값을 의미한다.)
			errorFree(a, argv, flag_argc_2);		// 함수자체가 int파라메터를 받는거로 선언되어있어서 형변환을 해준다.
		append_node(a, (int)nbr);					// 더블포인터 (a)에 nbr이 저장된 노드를 이어붙인다. 새 노드 만들고, 가장 뒤 노드에 이어붙이고 prev, next 연결시킨다.
		i++;										// argv[1]에 담긴 모든 숫자가 처리될때까지 반복한다.
	}
	if (flag_argc_2)								// flag_argc_2조건이 안맞았다면 여기까지 오지도 않았겠지만 혹시 몰라 그냥 조건으로 붙여준다.
		freeMatrix(argv);							// argv[i][j] 더블 어레이에 처음 저장해뒀던 값들이 이제는 이미 node로 다 복사됐기 때문에 더이상 필요없다.
}