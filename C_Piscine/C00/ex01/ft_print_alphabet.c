/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:37:41 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/09 14:41:02 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/*	[F]
	[ What i've learned ]
	1. Basic form of declaration of variable

		char  c  =  'A'
		----  -  -  ---
		(1)  (2)(3)	(4)

		(1): Data type				// sort.
		(2): Data name (= variable) // empty box.
		(3): Assignment operator	// assign from rhs to the (2).
		(4): Value					// Real value in variable.

	2. Operators
		Assignment operator (=)
			Assign the value(rhs) to the variable(lhs).

		Comparison operators (<, >, <=, >=, ==, !=)

		Increment, Decrement operators (++; --;)
			go to the the next address from the order.
			go to the previous address from the order.

		Arithmetic operator
			+: Addition
			-: Subtraction
			*: Multiplication
			/: Division
			%: Modulus (remainder)
		
		Compound assignment operators
			

	3. While loop
		format:
			while (condition)
			{
				infinite loop until meeting with (exit)condition.
			}

	[ Definition ]
	Print out the alphabet from 'a' to 'z' with using while loop.
*/
void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		write(1, &c, 1);
		c++;
	}
}
