/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:31:30 by tkwak             #+#    #+#             */
/*   Updated: 2023/07/20 16:42:05 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	[F]
	[ What i learned ]
	(1) Format Specifiers
		1. Definition
		It provides information about the data type of a variable.

		2. Tpyes
									[ type ]
		Integer types
		%d: decimal					int
		%i: decimal					int
		%u: decimal					unsinged int
		%x: hexadecimal (lower)		unsigned int
		%X: hexadecimal (upper)		unsigned int

		Character types				
		%c: single character		int
		%s: string of characters	char *
		
		Floating point types
		%f: floating point			float
	
		Pointer types
		%p: pointer address			long long
	
		Percentage (%)				print (%)

	----------------------------------------------------------------

	(2) Variadic function
		1. Definition
		Function that accepts a variable number of arguments.
	
		2. Form
		"int	ft_printf(const char *str, ...);"
		= '...' indicates, function can accept a variable number of arguments,
		  following the fixed argumet 'str'.

		3. Why
		Flexibility in function calls.
		= It allows functions to hangle a dynamic number of arguments.
		= Useful for cases where the number of types of arguments aren't known.

		ex) %d %c %s %p -> cover all formats of variable.

		4. header file
		"#include <stdarg.h>"

		5. Macros
		"va_list ap"
		= One of the data type like list.
		= It points to the each address of a variable argument.
		= Way for C functions to accept a variable number of arguments.
		
		ap:
		= argument pointer, points each variable arguement.

		ap
		 |---------------------------|---------------------------|--- ...
		 |                           |                           |
		 v                           v                           v
		variable argument(1)	variable argument(2)	variable argument(3)

		va_start(ap, str)
		= Initialize Param(1): "ap" (va_list type)
		  with the start of the va using Param(2): "str".
		= Param(2): "str" // last fixed factor.
		= 마지막 고정 인자인 "str"를 기준으로 va_list(가변인자) 초기화.

		va_arg (ap, type)
		= Search from Param(1): "ap"
		  It can only take (va), which has same type
		  with Param(2): "type"(ex: int, char, ...).		  
		= va_list에서 다음 인자를 지정된 타입으로 가져오고,
		  ap를 다음 인자를 가리키도록 업데이트하는 기능.

		va_end (ap)
		= Initialize the Param(1): "ap" to NULL before function over.(clean)
*/
int	main(void)
{
	ft_printf(" %p %p \n", 0, 0);
	int	a = 5;
	ft_printf("%d\n", a);
	return (0);
}

/*	[ Testing ]
	int *b = &a;
	printf("Address of a: %p\n", &a);
	printf("Address of pointer(b): %p\n", b);
	ft_printf("%p\n");
	printf("ft_printf's return value: %d\n", ft_printf("%p"));
*/
