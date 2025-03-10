/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:00:24 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/15 11:30:46 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	[F]
	[ Definition ]
	Convert Param:"str" to lowercase, when it has uppercase.
	Convert Param:"str" to uppercase, when it has lowercase.
	If meet with 'number', jump.
*/
char	*ft_strcapitalize(char *str)
{
	int	i;
	int	signal;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
			signal = 1;
		else if (str[i - 1] >= '0' && str[i - 1] <= '9')
			signal = 1;
		else if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			signal = 1;
		else
			signal = 0;
		if (str[i] >= 'A' && str[i] <= 'Z' && signal == 1)
			str[i] += 32;
		if (str[i] >= 'a' && str[i] <= 'z' && signal == 0)
			str[i] -= 32;
		i++;
	}
	return (str);
}
