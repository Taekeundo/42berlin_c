/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:24:50 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/15 17:53:52 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	[F]
	[ Definition ]
	Check the Param:"str", whether it consist of only Alphabet.
	Yes -> return (1);
	No	-> return (0);
*/
int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			i++;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			i++;
		else
			return (0);
	}
	return (1);
}

/*	[ Testing ]
#include <stdio.h>
int main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("av[1]: %s\n", av[1]);
		if (ft_str_is_alpha(av[1]) == 0)
			printf("Error: include none alphabet\n");
		else
			printf("Good: every char is alphabet\n");
	}
	else
		printf("Invalid user input\n");
	return (0);
}
*/
