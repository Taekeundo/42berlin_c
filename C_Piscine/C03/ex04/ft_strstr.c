/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:10:17 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/20 15:07:49 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	[F]
	[ Definition ]
	Searches for the substring, Param(2):"to_find" within the Param(1):"str".
	If Param(2):"to_find" substring is found, returns the part of str starting
	from the first occurrence of Param(2):"to_find".
	
	[ Parameters ]
	Param(1): The string to be searched.
	Param(2): The substring to search for.

	[ Return ]
	If found // A pointer to the first occurence of Param(2):"to_find".
	IF not	 // NULL
*/
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j])
			{
				j++;
				if (to_find[j] == '\0')
					return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}
