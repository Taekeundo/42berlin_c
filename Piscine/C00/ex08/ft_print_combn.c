/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:08:10 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/27 20:09:09 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/*	[F]
	[ What i've learned ]
	1. Data type: Array, String
		Array:
		Collection of elements of the same type stored
		in contiguous memory locations.

		ex) int arr[5] = {1, 2, 3, 4, 5};

		String:
		Specific type(char) of array, terminated by a null character.
		('\0') signifies the end of the string (Invisible).

		ex) char text[] = "Hello"; (hidden: '\0' at the end)
	
	2. Data type: Pointer
		A variable, stores(= indicates) the address of another variable.

		Syntax
			(Data type)	* (Name of pointer) = &(another variable).

			ex)	int var = 10;
				int *ptr = &var;

			1. There is a variable 'ptr' of pointer data type.
			2. 'ptr' is the name.
			3. 'ptr' pointer can only point to a variable of (int) data type.
			4. 'ptr' pointer is currently pointing to
				the address of the (int)type variable, which is called 'var'.

	[ Definition ]
	print combination following Param(4): "len", which n_digit.

	[ Param ]
	Param(1): int pos
		starting index (= 0) and current position
		in Param(3): "generate_comb".
	Param(2): char next_digit
		Each digit for Param(3): "char *generate_comb".
	Param(3): char *generate_comb
		Point to combination array and update everytime in recursive.
	Param(4): int len
		length of digit, want to print out.

	[ Example ]
	ft_print_combn(2);
	char	generate_comb[9];

	print_combn(0, '0', generate_comb, 2);
	pos: 0, next_digit: '0', generate_comb, len:2
	-------------------------------
	| if (pos == len)			  |
	|	(pos = 0) != (len = 2)	  |
	|							  |
	| if (next_digit > '9')		  |
	|	(next_digit = '0') <= '9' |
	|							  |
	|-----------------------------|
	| generate_comb[0] = '0';	  |
	-------------------------------

	(1): print_combn(pos + 1, next_digit + 1, generate_comb, len);
	(2): print_combn(pos, next_digit + 1, generate_comb, len);

	---------------------------------------------------------------------
	
	(1) print_combn
	print_combn(1, '1', generate_comb, 2);	
	pos: 1, next_digit: '1', generate_comb, len:2
	-------------------------------
	| if (pos == len)			  |
	|	(pos = 1) != (len = 2)	  |
	|							  |
	| if (next_digit > '9')		  |
	|	(next_digit = '1') <= '9' |
	|-----------------------------|
	| generate_comb[1] = '1';	  |
	-------------------------------

	(1)-1: print_combn(pos + 1, next_digit + 1, generate_comb, len);
	(1)-2: print_combn(pos, next_digit + 1, generate_comb, len);

		(1)-1 print_combn
		print_comb(2, 2, generate_comb, 2);
		pos: 2, next_digit: '3', generate_comb, len:2
		-------------------------------
		| if (pos == len)			  |
		|	write(1, genertae_comb, 2)|
		|							  |
		| std = 10 - 2 + '0' // '8'	  |
		|							  |
		| generate_comb[0]: 0 < 8	  |
		| write(1, ", ", 2);		  |
		|							  |
		| return ;					  |
		-------------------------------

		print status: [01, ]

		(1)-2 print_combn
		print_comb(1, '2', generate_comb, 2);
		pos: 1, next_digit: '3', generate_comb, len:2
		-------------------------------
		| if (pos == len)			  |
		|	(pos = 1) != (len = 2)	  |
		|-----------------------------|
		| generate_comb[1] = '3';	  |
		-------------------------------

		print status: [01, 02, 03, ...]
	-------------------------------------------------------------------

	(2) print_combn
	print_combn(0, '1', generate_comb, 2);
	pos: 0, next_digit: '1', generate_comb, len:2

		print status: [12, 13, 14 ...]

	.
	.
	.
*/
void	print_combn(int pos, char next_digit, char *generate_comb, int len)
{
	char	*comsp;
	char	std;

	comsp = ", ";
	if (pos == len)
	{
		write(1, generate_comb, len);
		std = 10 - len + '0';
		if (generate_comb[0] < std)
			write(1, comsp, 2);
		return ;
	}
	if (next_digit > '9')
		return ;
	generate_comb[pos] = next_digit;
	print_combn(pos + 1, next_digit + 1, generate_comb, len);
	print_combn(pos, next_digit + 1, generate_comb, len);
}

/*	[F]
	Param(1): "len" // digit for output.
	
	len = 3;
	123 124 125 ...

	len = 5;
	12345 12346 12347 ...

	len = 10;
	0123456789
*/
void	ft_print_combn(int len)
{
	char	generate_comb[9];

	print_combn(0, '0', generate_comb, len);
}

/*	[ Testing ]
int	main(void)
{
	ft_print_combn(10);
	return (0);
}
*/