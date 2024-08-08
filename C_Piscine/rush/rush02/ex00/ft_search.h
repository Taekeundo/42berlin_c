/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:20:17 by mcutura           #+#    #+#             */
/*   Updated: 2023/02/26 21:23:28 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SEARCH_H
# define FT_SEARCH_H

char	*find_by_key(char *key, char ***dict, size_t dict_size);
char	*find_by_val(char *val, char ***dict, size_t dict_size);
char	**get_twenties(char ***dict, size_t size);
char	**get_tens(char ***dict, size_t size);
char	**get_multipliers(char ***dict, size_t size);

#endif
