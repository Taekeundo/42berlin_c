/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:10:28 by tkwak             #+#    #+#             */
/*   Updated: 2023/03/01 14:58:06 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*	[F]
	[ Definition ]
	Check the [f]ft_strlcpy.
	Almost same, the only difference is cat || copy.
*/
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dlen;
	unsigned int	slen;

	i = 0;
	j = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (size == 0 || size <= dlen)
		return (slen + size);
	j = dlen;
	while (src[i] && i < size - dlen -1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dlen + slen);
}

/*	[ Testing ]
#include <stdio.h>
#include <string.h>

int main(void)
{
	char dest[] = "helloworld";
	char src[] = "applee";
	unsigned int n = 13;
	
	printf("%u\n", ft_strlcat(dest, src, n));
	printf("%s\n", dest);
	
	char dest1[] = "helloworld";
	char src1[] = "applee";
	unsigned int k = 10;
	
	printf("%u\n", ft_strlcat(dest1, src1, k));
	printf("%s\n", dest);
	
	char dest2[] = "helloworld";
	char src2[] = "applee";
	unsigned int j = 8;
	
	printf("%u\n", ft_strlcat(dest2, src2, j));
	printf("%s\n", dest);	
}
*/
