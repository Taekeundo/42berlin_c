/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 03:58:17 by mcutura           #+#    #+#             */
/*   Updated: 2023/02/26 04:02:45 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H

char	*ft_strndup(char *str, int n);
char	*ft_strdup(char *str);
int		count_words(char *str, char *charset);
char	**ft_split(char *str, char *charset);
#endif
