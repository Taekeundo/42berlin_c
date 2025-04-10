#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

// [D]
// *** Struct ***
typedef struct s_stack
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;
/*
value				실제 값
current_position	전체 노드에서 현재 몇번째에 위치해 있는지 (순서)를 표시하기 위한 값
push_price			How many moves does node need to bring to the top in stack.
above_median;		노드의 순서가 중앙값보다 위에 있는지 확인하는 변수.
cheapest;			Checks bool whether current node is most efficient node for [F]push_price.
*target_node;		서로 다른 스택에서 조건에 가장 가까운 노드를 가리키는 포인터.
*next;				다음 노드와 연결
*prev;				이전 노드와 연결
*/

// [D]
//*** Handle [input] --> ./push_swap "1 -42 1337" ***
char			**ft_split(char *str, char separator);

// [D]
//*** Handle [errors] --> free ***
void			freeMatrix(char **argv);
void			errorFree(t_stack **a, char **argv, bool flag_argc_2);
void			freeStack(t_stack **stack);
int				errorRepetition(t_stack *a, int nbr);
int				validateInput(char *str_nbr);

// [D]
//*** Stack create & initialize ***
void			stack_init(t_stack **a, char **argv, bool flag_argc_2);
void			init_nodes(t_stack *a, t_stack *b);
void			set_current_position(t_stack *stack);
void			set_price(t_stack *a, t_stack *b);
void			set_cheapest(t_stack *b);

// [D]
//*** linked list ***
void			append_node(t_stack **stack, int nbr);
t_stack			*find_curr_last_node(t_stack *head);
t_stack			*find_smallest(t_stack *stack);
t_stack			*return_cheapest(t_stack *stack);
bool			flag_stack_sorted(t_stack *stack);
int				stack_len(t_stack *stack);
void			finish_rotation(t_stack **s, t_stack *n, char c);

// [D]
//*** Algorithms for sorting ***
void			tiny_sort(t_stack **a);
void			handle_five(t_stack **a, t_stack **b);
void			push_swap(t_stack **a, t_stack **b);

// [D]
//*** Commands for sorting ***
void			sa(t_stack **a, bool checker);
void			sb(t_stack **b, bool checker);
void			ss(t_stack **a, t_stack **b, bool checker);
void			ra(t_stack **a, bool checker);
void			rb(t_stack **b, bool checker);
void			rr(t_stack **a, t_stack **b, bool checker);
void			rra(t_stack **a, bool checker);
void			rrb(t_stack **b, bool checker);
void			rrr(t_stack **a, t_stack **b, bool checker);
void			pa(t_stack **a, t_stack **b, bool checker);
void			pb(t_stack **b, t_stack **a, bool checker);

#endif