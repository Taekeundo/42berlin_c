/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:04:17 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/15 18:33:06 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	[F]
	[ Definition ]
	Copy the Param(2):src to the Param(1):dst as much as Param(3):size.

	[ Return ]
	Length of Param(2):src (= 'j')

	[ Memo ]
	Safer than strncpy.

	strlcpy:
		'\0' is always at the end of string.
		We can know how the length of the original string(src) is.

	strncpy:
		If (dstsize > srcsize), fill the remaining space to the NULL.
		It's wasting useless memory.
*/
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (size != 0)
	{
		while ((src[i] != '\0') && (i + 1 < size))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}
