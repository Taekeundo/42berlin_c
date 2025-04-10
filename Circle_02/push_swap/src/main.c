#include "push_swap.h"

// [D]
int main(int argc, char **argv)
{
    t_stack *a;    // pointer to stack tpye 'A' and name is 'a'.
    t_stack *b;    // pointer to stack tpye 'B' and name is 'b'.

    a = NULL; // init pointer // 현재 아무것도 안가리키고 있다.
    b = NULL; // init pointer // 현재 아무것도 안가리키고 있다.
    
    // (FIRST part) Check whether the input value meets the right conditions.
    if (argc == 1 || (argc == 2 && argv[1][0] == '\0')) // 입력값 없거나, " "비어있다면 프로그램 종료.
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' '); // Divide argv[1] based on the sace. -> 스페이스 기준으로 나눠진 여러 단어를 얻는다.

    // (SECOND part) Create Stack.
    stack_init(&a, argv + 1, argc == 2);
    // Parameter(1. To where, 2. Which info, What 3. flag(condition))
    // 어떤 스택에 어떤 정보를 복사(초기화)할것인가? 그때의 조건은 무엇인가?
    //      1. Where: 포인터 a가 가리키는 스택에다가
    //      2. What: argv + 1 값을 복사한다.
    //               왜 argv + 1 값을 복사하는가? argv를 가리키면 "push_swap" (프로그램 이름을 나타낸다) argv + 1 은 다른말로 pointer to (argv + 1: argv[1])을 의미한다.
    //      3. Condition: argc의 개수가 2개일때만 할 수 있다.
    // Part1,2를 통해 argv[1]의 모든값을 ' '기준으로 나누고 node에 연결시켜서 저장해뒀다.
    // 이제부터 알고리즘을 통해 'sort'하기만 하면 된다.

    // (THIRD part) Algorithm
    // 이미 모든 argv[1]의 값들은 stack'a'에 linked list형태로 저장되어있다.
    if (!flag_stack_sorted(a))          // bool: 참 '1'(더이상 분류할게 없음), 거짓 '0'(분류필요)일때만 if문 실행.
    {
        if (stack_len(a) == 2)          // Only for len'2' = argv[1]의 개수 2개 -> no need algorithm.
            sa(&a, false);              // false(flag) -> 정돈 안됐다는 뜻.
        else if (stack_len(a) == 3)     // Only for len'3' = argv[1]의 개수 3개 -> [F] tiny_sort.
            tiny_sort(&a);              // Compare value in three nodes, and arrange it.
        else                            // The number of (*argv[1]) is over 3. (x >= 4) -> [F] push_swap
            push_swap(&a, &b);          // Only left (3 nodes in stack 'A') and push else.
    }
    freeStack(&a);                      // Don't need 'a' anymore. (Everything is already sorted)
}