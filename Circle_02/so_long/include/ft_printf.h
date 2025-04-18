/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:35:24 by tkwak             #+#    #+#             */
/*   Updated: 2023/10/31 18:38:06 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* library */
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# include "libft.h"

/* bool */
typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

/* charset */
# define CHARSET_DEC "0123456789"
# define CHARSET_LHEX "0123456789abcdef"
# define CHARSET_UHEX "0123456789ABCDEF"

int				ft_printf(const char *format, ...);
int				ft_printf_arg(const char *fmt, int i, va_list ap);
int				ft_put_char(char c);
int				ft_put_str(char *str);
int				ft_put_int(int nbr);
int				ft_put_ptr(unsigned long ptr);
char			*ft_utoa(unsigned int nbr);
char			*ft_put_n_char(int n, char c);
unsigned int	ft_put_uint(unsigned int nbr);
unsigned int	ft_put_hex_up(unsigned int nbr, char *charset);
unsigned int	ft_put_hex_low(unsigned int nbr, char *charset);
unsigned int	ft_get_nbr(char *buf, unsigned int nbr, \
					char *charset, int len_base);

#endif
