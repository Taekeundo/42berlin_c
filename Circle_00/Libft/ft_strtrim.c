/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:03:29 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 17:49:03 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Find the first occurrence
	of the Param(2): "set" in the Param(1): "s1".
	-> trim starts.

	Find the last occurrence
	of the Param(2): "set" in the Param(1): "s1".
	-> trim ends.

	[ Logic ]
	1. 1st while loop
		Checking from the front.
		
		Jump to the pointer to where found 'set'.
		= Keep that point's index[i].

		(ex)
				s1			set
			he asd ass		" "
		i:	0123456789

		Stariing i: 0
		Current i: 2

	2. 2nd while looo
		Checking from the back.
		
		Jump to the pointer to where founc 'set'.
		= Keep that point's index[len].
	
				s1			set
			he asd ass		" "
		i:	0123456789
		
		starting len: 10 
		Current len: 6 

		!!!!!!!!!!!!!!!!!!!!!!!!!
		!!! i = 2 !!! len = 6 !!!
		!!!!!!!!!!!!!!!!!!!!!!!!!
	
	3. Allocate memory
		size: len - i + 1
				6 - 2 + 1
				= 5

	4. Cpy from index[2] as many as size '6'.

	5. Result
		| asd \0|
		 01234 5	size: 6.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*result;

	i = 0;
	len = ft_strlen(s1);
	if (!s1 || !set)
		return (0);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while ((i < len) && ft_strchr(set, s1[len - 1]))
		len--;
	result = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!result)
		return (0);
	ft_strlcpy(result, s1 + i, len - i + 1);
	return (result);
}
