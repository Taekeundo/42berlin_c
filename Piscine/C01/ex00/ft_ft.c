/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:11:08 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/12 15:46:35 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	[F]
	[ What i've learned ]
	1. Asterisk
		Assign a value to the target of pointer by using asterisk.

		*: Asterisk
		Derefencing operator.
		It allows to access the value stored at the memory address,
		that the pointer is pointing to.

	2. int *********nbr = 42;

		9th									   1st
		. -> . -> . -> . -> . -> . -> . -> . -> . -> 42
		(nbr)
	
		9th pointer, points 8th pointer's address
		8th pointer, points 7th pointer's address
		7th pointer, points 6th pointer's address
		6th pointer, points 5th pointer's address
		5th pointer, points 4th pointer's address
		4th pointer, points 3rd pointer's address
		3rd pointer, points 2nd pointer's address
		2nd pointer, points 1st pointer's address
		1st poinetr, points target's address.

	[ Definition ]
	Assign the value to the Param: "nbr",
	which is the target of the pointer.

	value: 42 is assgined to the memory location,
	that "nbr" points to.
*/
void	ft_ft(int *nbr)
{
	*nbr = 42;
}
