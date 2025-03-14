/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:00:51 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 14:56:34 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Connect two string (s1, s2) // s1 + s2.

	[ Logic ]
	1. Check both length from s1, s2 for final connecting string.
	2. Allocate memory for final connecting string.
	3. Copy s1 to final.
	4. Copy s2 to final.

*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, len1);
	ft_memcpy(result + len1, s2, len2);
	result[len1 + len2] = '\0';
	return (result);
}

/*	[ Test ]
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*res;

	if (s1 && s2)
	{
		len1 = strlen(s1);
		len2 = strlen(s2);
		res = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
		if (res == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			res[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			res[len1] = s2[i];
			len1++;
		}
		res[len1] = '\0';
		return (res);
	}
	return (NULL);
}
*/
