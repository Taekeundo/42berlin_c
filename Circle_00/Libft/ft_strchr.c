/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:47:28 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 12:12:44 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Refer to first occurence of a character from a given string.
	= Search from first to last digit.

	[ Return ]
	Pointer to the char, which is first founded in string.
	No found -> NULL.

	[ Range of search ]
	From starting digit to at the end of the sting (= '\0').

	[ Memo ]
	Reason, using unsinged char:
	Certain environment of CPU-Architecture, unsigned char is default.
*/
char	*ft_strchr(const char *str, int search)
{
	while (*str != '\0')
	{
		if (*str == (unsigned char)search && (unsigned char)search != '\0')
			return ((char *)str);
		str++;
	}
	if ((unsigned char)search == '\0')
		return ((char *)str);
	return (0);
}

/* [ Test]
int	main(void)
{
	char	*str = "123456789";
	char *s1;

	s1 = ft_strchr(str, '5');
	if (s1)
		printf("%s\n", s1);
	else
		printf("There is no search in str.\n");
	return (0);
}
*/
