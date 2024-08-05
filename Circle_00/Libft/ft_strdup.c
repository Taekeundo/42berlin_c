/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:09:38 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 16:31:42 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]	
	[ Definition ]
	Duplicate Param:str with deep copy (allocate memory).

	Duplicate cmd_line.
	Make the copy cmd_line of the given cmd_line
*/
char	*ft_strdup(const char *str)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (res == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*	[ Test ]
int	main(void)
{
	char	*src;
	char	*p;

	src = "abcedfg";
	p = ft_strdup(src);
	printf("%s\n", src);
	printf("%s\n", p);
	return (0);
}
*/
