/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:20:11 by tkwak             #+#    #+#             */
/*   Updated: 2024/04/25 11:15:14 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*  [F]
    Meet with ' '(space) -> true.
*/
static bool	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	else
		return (false);
}

/*  [F]
    Meet with '123456789'(digit) -> true.
*/
static bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

/*  [F]
    [ Role ]
	Convert the type of the data from "ASCII" to "LONG"

	[ How to proceed ]
    Check 1. Negatives -> "ERROR"
    Check 2. Legit (legitimate: 적합한, 합법적인)
              O: "    +134%^&*#*"
              X: "    +&&24154az" -> "ERROR"
    Check 3. Not over "INT_MAX".
            If len(num) > 10, -> "ERROR"

    [ Return value ]
    Pointer, that points the starting point from the number.
            "    +134%^&*#*"
                  ↑
                  here
*/
static long	ft_atol(const char *str)
{
	long	res;

	res = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		print_error_and_exit(RED"Error: only positive number allowed"RS);
	if (!is_digit(*str))
		print_error_and_exit(RED"Error: only digit allowed"RS);
	while (is_digit(*str))
	{
		res = (res * 10) + (*str++ - '0');
		if (res > INT_MAX)
			print_error_and_exit(RED"Error: Only under INT_MAX allowed"RS);
	}
	return (res);
}

/*  [F]
	[ Goal ]
	1. Parsing all arguments from input
	2. parse_input_n_apply_to_context

    [ Example ]
                            ms          ms          ms
    ./philo     5           800         200         200         [5]
    argv[0]		argv[1]		argv[2]		argv[3]		argv[4]		argv[5]
    Name
                n_philo
                            argv2_time_die
                                        argv3_time_eat
                                                    argv4_time_sleep
                                                                n_required_meals

    Check 1. Actual numbers.
    Check 2. Not over "INT_MAX".
    Check 3. timestamps > 60ms (Guide to evaluation sheet)

    [ Background ]
    1,000 = 1 * 10^3 == 1e3
    60,000 = 6 * 10^4 == 6e4
	To convert from "milli-second" to "micro-second" for the "usleep" function.

	The standard of all time, that used in function, is "MICRO-SECOND".
*/
static void	parse_argv_and_cpy_to_context(t_dining *context, char **argv)
{
	context->n_philo = ft_atol(argv[1]);
	if (context->n_philo > PHILO_MAX)
		print_error_and_exit(RED"Error: Max of n_philo is 200"RS);
	context->time_to_die = ft_atol(argv[2]) * 1000;
	context->time_to_eat = ft_atol(argv[3]) * 1000;
	context->time_to_sleep = ft_atol(argv[4]) * 1000;
	if (context->time_to_die < 60000
		|| context->time_to_sleep < 60000
		|| context->time_to_eat < 60000)
		print_error_and_exit(RED"Error: Timestamp is too less\n"
			"       Minimum is 60ms"RS);
	if (argv[5])
		context->n_required_meals = ft_atol(argv[5]);
	else
		context->n_required_meals = -1;
}

/*  [F]
    [ Example ]
                            ms          ms          ms
    ./philo     4	        310         200         100         [5]
    av[0]       av[1]       av[2]       av[3]       av[4]       av[5]
    Name
                n_philo
                            time_to_die
                                        time_to_eat
                                                    time_to_sleep
                                                                n_required_meals

    [ How to proceed ]
    1. Input
        2. Check original av[i]'s value
        3. Check input's errors & filling data from "av" to the "dining struct".
        4. Creating the actual thing.
        5. Start simulating.
        6. Finish (release_all_resources)
    7. Incorrect input.

    [ For the test, put the below code ]
    int i = 0;
    while (i < 6)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
        i++;
    }
*/
int	main(int argc, char **argv)
{
	t_dining	context;

	if (argc == 5 || argc == 6)
	{
		parse_argv_and_cpy_to_context(&context, argv);
		initialize_all_struct(&context);
		run_dining(&context);
		release_all_resources(&context);
		return (0);
	}
	print_error_and_exit(RED"Error: Wrong input\n\n"RS
		G"Right example:\n"
		"./philo 4 310 200 100 3\n"
		" [0] [1] [2] [3] [4] [5]\n\n"RS
		W"argv[0]: file name\n"
		"argv[1]: n_philo\n"
		"argv[2]: time_to_die\n"
		"argv[3]: time_to_eat\n"
		"argv[4]: time_to_sleep\n"
		"argv[5]: n_required_meals"RS);
	return (0);
}

/*	[ Original ft_atol function from my LIBFT ]
static long	ft_atol(const char *str)
{
	int		i;
	long	num;
	int		flagNegative;
	
	i = 0;
	num = 0;
	flagNegative = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		flagNegative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * flagNegative);
}

[ Try other way ]
static const char	*validate_input(const char *str)
{
	int			len;
	const char	*res;

	len = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		print_error_and_exit(RED"Error: only positive allowed\n"RS);
	if (!is_digit(*str))
		print_error_and_exit(RED"Error: only digit allowed\n"RS);
	res = str;
	while (is_digit(*str++))
		++len;
	if (len > 10)
		print_error_and_exit(RED"Error: only under INT_MAX allowed\n"RS);
	return (res);
}

static long	ft_atol(const char *str)
{
	long	res;

	res = 0;
	str = validate_input(str);
	while (is_digit(*str))
		res = (res * 10) + (*str++ - '0');
	if (res > INT_MAX)
		print_error_and_exit(RED"Error: Only under INT_MAX allowed\n"RS);
	return (res);
}
*/
