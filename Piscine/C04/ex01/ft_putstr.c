/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:34:27 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/21 11:16:10 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*	[F]
	[ Definition ]
	Print out the string, Param:"str", one char by one char.
*/
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

/*	[ Testing ]
int	main(void)
{
	char str[] = "abbbbb";
	ft_putstr(str);
	return (0);
}
*/
