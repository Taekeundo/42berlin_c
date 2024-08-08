/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ntow3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:36:16 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/26 23:19:47 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NTOW2_H
# define NTOW2_H

char	*handle_hundreds(unsigned int digit, char *ans, char **twen);
char	*handle_twenty(unsigned int digit, char *ans, char **twen);
char	*handle_tens(unsigned int digit, char *ans, char **tens);
char	*handle_tt(unsigned int digit, char *ans, char **twen, char **tens);
char	*handle_multi(unsigned int t, char *ans, char **multi);

#endif
