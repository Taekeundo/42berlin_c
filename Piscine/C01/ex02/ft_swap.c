/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:50:43 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/12 15:55:03 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	[F]
	[ What i've learned ]
	Difference (value copy) vs (address copy)

	void	ft_swap(int *a, int *b)
	{
		int tmp;

		tmp = *a;
		*a = *b;
		*b = tmp;
	}
	
	a: A pointer,
		points to the memory address of a specific location.

	b: Another pointer,
		points to the memory address of a different specific location.

	*a: value of the target, that 'a' pointer points.

	*b: value of the target, that 'b' pointer points.

	[ Definition ]
	Swap the value of the target, that 'a' pointer points,
	with the value of the target, that 'b' pointer points,
	by using the tmp.
*/
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
