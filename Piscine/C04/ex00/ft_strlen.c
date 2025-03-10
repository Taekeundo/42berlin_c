/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:34:11 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/22 14:37:37 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	[F]
	[ Definition ]
	Check the length of the string, Param(1):"str".
*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*	[ Testing ]
#include <stdio.h>
int	main(void)
{
	char	str[] = "abcde";
	printf("%d", ft_strlen(str));
}
*/
