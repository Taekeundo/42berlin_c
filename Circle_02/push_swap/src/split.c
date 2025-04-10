#include "push_swap.h"

/* [D] */
static int	count_words(char *str, char separator)
{
	int		howManyWords;							// 몇개의 단어가 *str에 있는지 확인하는 return값.
	bool	insideWord;								// 현재 포인터가 word안에 있는지 없는지 확인하는 bool값. R u now insideWord? or not?

	howManyWords = 0;
	while (*str)
	{
		insideWord = false;							// 초기화, bool(자료형)에서 false는 0을 의미한다. (프로그램이 아직 단어 안에 없기 때문에)
		while (*str && *str == separator)			// 만약 포인터가 가리키는 값이 존재하고, 그 값이 ' '스페이스라면 계속 간다.
			str++;
		while (*str && *str != separator)			// 만약 포인터가 가리키는 값이 존재하고, 그 값이 ' '스페이스가 아니라면
		{
			if (insideWord == 0)					// 만약 insideWord가 0일 경우 "아직 단어 안에 들어가지 않았다면".
			{
				howManyWords++;						// 단어의 갯수를 1개 증가시킨다.
				insideWord = true;					// insideWord를 1로 변경시켜준다. // Now i'm inside true.
			}										// 단어의 '첫문자'에서 HowManyWord값을 +1 (단어당 1번만 올리기 위한 조건)
			str++;									// 다음칸으로 이동한다.
		}
	}
	return (howManyWords);							// 몇개의 단어가 문장에 존재하는지 int type으로 return한다.
}

/* [D] */
static char	*get_one_word(char *str, char separator)
{
	static int	cursor = 0;											// 단어가 2개일 경우 (index값)을 잃어버리면 안되기 때문에 static을 사용한다. 첫번째 함수실행시 cursor가 5까지 증가했다면, 두번째 함수 실행에서 cursor는 5로 시작한다.
	char		*result;											// argv[1]에 있는 여러 단어중 순서대로 return될 단어들 중 한개의 단어
	int			len;												// 단어의 길이를 저장하기 위한 변수 (길이를 알아야 malloc할 수 있다.)
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)								// 첫 문자가 separator(32)일 경우 지나간다.
		cursor++;
	while ((str[cursor + len] != separator) && str[cursor + len])	// 다음 문자가 (32 & '\0')가 아닐때 len를 증가시켜 길이를 구한다.
		len++;
	result = malloc((sizeof(char) * (size_t)len)+ 1);				// 단어를 담기 위한 메모리를 할당한다.
	if (result == NULL)
		return (NULL);
	while (str[cursor] != '\0' && (str[cursor] != separator))		// 단어의 문자를 하나씩 복사('\0' 또는 32 만날때까지)
		result[i++] = str[cursor++];
	result[i] = '\0';												// 마지막에 '\0'을 넣어줘서 array를 마무리해준다.
	return (result);
}

/* [D]
** I recreate an argv in the HEAP (saving memory in HEAP)
**
** (example)
** 		argv[0] -> name of program
** 		argv[1] -> p1 -> "42"
**				-> p2 -> "1332"
**				-> p3 -> "-21"
**				-> p4 -> NULL
*/
char	**ft_split(char *str, char separator)
{
	int		i;
	int		wordsNumber;
	char	**listofString;

	i = 0;
	wordsNumber = count_words(str, separator);
	if (!wordsNumber)											// 단어 없으면 프로그램 종료
		exit(1);
	listofString = malloc(sizeof(char *) * (size_t)(wordsNumber + 2));	// allocate two more space: 1 for argv[0]:(ex)push_swap(프로그램이름)" + 1 for '\0' (Final NULL)at the end.
	if (NULL == listofString)
		return (NULL);
	while (wordsNumber-- >= 0)									// if wordsNumber is 2 -> 2, 1, 0
	{
		if (i == 0)
		{
			listofString[i] = malloc(sizeof(char));				// argv[0]은 보통 이름이 들어가기때문에 '\0'이 들어갈 한 자리만 할당해준다.
			if (listofString[i] == NULL)
				return (NULL);
			listofString[i++][0] = '\0';						// listofstring[0][0] == argv[0][0]에 '\0'값을 넣어준다.
			continue ;											// while문의 가장 처음으로 jump한다.
		}
		listofString[i++] = get_one_word(str, separator);		// listofString[i]포인터가 (get_one_word포인터가 가리키는 첫번째 array)를 가리키도록 복사해준다.
	}
	listofString[i] = NULL;										// 마지막 listofString[i]포인터는 NULL을 가리킨다. array 마지막에 '\0'넣는것과 같은 개념.
	return (listofString);										// return값으로 **이중포인터의 모든 값을 출력한다. '\0' + word(1), word(2), word(i) + NULL.
}

/* [D]
** Here, main function is for testing split.c

int main(int argc, char **argv)
{
  int i = 0;
  argv = ft_split("12 34 66 1992", ' ');
  printf("\n");
  while (argv[i])
  {
    printf("\tpointer argv[%d]'s address: %p, value: %s\n", i, argv[i], argv[i]);
    i++;
    fflush(stdout);
  }
  printf("\n");
  i = 0;
  while (argv[i])
  {
    printf("\tpointer being freed argv[%d]'s address: %p\n", i, argv[i]);
    fflush(stdout);
    free(argv[i++]);
  }
  free(argv);
}
*/