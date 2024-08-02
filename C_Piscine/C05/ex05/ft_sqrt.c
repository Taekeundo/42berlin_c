/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:05:06 by tkwak             #+#    #+#             */
/*   Updated: 2023/03/01 12:52:27 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	long	index;
	long	l;

	l = nb;
	if (l <= 0)
		return (0);
	if (l == 1)
		return (1);
	index = 2;
	if (l >= 2)
	{
		while (index * index <= l)
		{
			if (index * index == l)
			{
				return (index);
			}
			index++;
		}
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(2));
	printf("%d\n", ft_sqrt(3));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(5));
	printf("%d\n", ft_sqrt(6));
	printf("%d\n", ft_sqrt(7));
	printf("%d\n", ft_sqrt(8));
	printf("%d\n", ft_sqrt(16));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147483647));
	return (0);
}
*/
