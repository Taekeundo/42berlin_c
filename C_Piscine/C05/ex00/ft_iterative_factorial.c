/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:37:28 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/28 14:54:49 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	i = 1;
	while (nb > 1)
	{
		i *= nb;
		nb--;
	}
	return (i);
}

/*
#include <stdio.h>

int	main(void)
{
	int	j = 1;

	while (j < 10)
	{
		printf("%d\n", ft_iterative_factorial(j));
		j++;
	}
	return (0);
}
*/
