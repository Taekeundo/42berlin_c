/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 03:34:41 by mcutura           #+#    #+#             */
/*   Updated: 2023/02/26 03:34:46 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i])
		++i;
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				diff;
	unsigned int	i;

	i = 0;
	diff = 0;
	while ((*s1 || *s2) && i++ < n && !diff)
	{
		diff = *s1++ - *s2++;
	}
	return (diff);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	this_big;

	this_big = ft_strlen(to_find);
	while (*str != '\0')
	{
		if (!ft_strncmp(str, to_find, this_big))
			return (str);
		str++;
	}
	return (0);
}
