/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:42:29 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/15 17:48:53 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	[F]
	[ Definition ]
	Copy the value from Param(2):"src" to Param(1): "dest",
	char by char as many as Param(3):"n" or until the end of "src".

	If (dstsize > srcsize)
	Param(3):"n" is greater than the length of Param(2):"src",
	fill the remaining Param(1):"dest"'s space with '\0'.
*/
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
