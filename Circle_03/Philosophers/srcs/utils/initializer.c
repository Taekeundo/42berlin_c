/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:09:29 by tkwak             #+#    #+#             */
/*   Updated: 2024/04/22 20:09:45 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	[F]
    [ Definition & Goal ]
	1. Determines in which order each philosopher will hold the fork.
	2. To assign the order to each forks,
    	accoring to the relative order of the philosopher.
    = 철학자의 상대적 순서에 따라 각 fork에 순서를 할당하는 함수.

    [ How to proceed ]
    1. Odd-numbered philo grabs the left first.
        홀수번째 철학자는 왼쪽을 먼저 잡는다.
        first take (left) ->  second take (right)

    2. Even-numbered philo grabs the right first.
        짝수번째 철학자는 오른쪽을 먼저 잡는다.
        first take (right) -> second take (left)

    [ Example 1 ]
    If n_philo is "5".

    philo_pos: 0            philo_pos: 1
    philo_id: 1             philo_id: 2
            /   \                   /   \
        first    second         first    second
          1         0             1        2

    philo_pos: 2            philo_pos: 3
    philo_id: 3             philo_id: 4
            /   \                   /   \
        first    second         first    second
          3         2             3        4

    philo_pos: 4
    philo_id: 5
            /   \
        first    second
          0        4

	[ Example 2 ]
	n_philo: 4
	philo_pos	philo_id	1st_fork		2nd_fork
		0			1		forks[1]		forks[0]
		1			2		forks[1]		forks[2]	// else
		2			3		forks[3]		forks[2]
		3			4		forks[3]		forks[0]	// else

					pos: 0
				!1st!	 !222!
			fork[1]			fork[0]
		!1st!					 !222!
	pos: 1							pos: 3
		!222!					 !1st!
			fork[2]			fork[3]
				!222!	 !1st!
					pos: 2

	Confilt in "fork[1], fork[3]", when n_philo: even number.

    [ Problem ]
    A data race(competition) condition occurs,
    when two philosophers try to access one fork at the same time.
    = 철학자가 동시에 하나의 fork에 접근하려고 하는 Data Race상태가 발생한다.
*/
static void	determine_fork_order(t_philo *philo, t_fork *forks,
		int philo_pos)
{
	int	local_n_philo;

	local_n_philo = philo->context->n_philo;
	if (philo->philo_id % 2 != 0)
	{
		philo->first_fork = &forks[(philo_pos + 1) % local_n_philo];
		philo->second_fork = &forks[philo_pos];
	}
	else
	{
		philo->first_fork = &forks[philo_pos];
		philo->second_fork = &forks[(philo_pos + 1) % local_n_philo];
	}
}

/*	[F]
	[ Goal ]
	Initialize all the datas in "t_philo struct".
*/
static void	initialize_philo(t_dining *context)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < context->n_philo)
	{
		philo = context->philos + i;
		philo->philo_id = i + 1;
		philo->is_full = false;
		philo->eaten_meals = 0;
		philo->context = context;
		handle_mutex_safely(&philo->philo_mutex, INIT);
		determine_fork_order(philo, context->forks, i);
		i++;
	}
}

/*	[F]
    [ Goal ]
    Initialize the data from the three fields in "t_dining struct".
*/
void	initialize_all_struct(t_dining *context)
{
	int	i;

	i = 0;
	context->n_running_threads = 0;
	context->flag_scenario_end = false;
	context->flag_all_threads_ready = false;
	context->philos = malloc_safely(context->n_philo * sizeof(t_philo));
	context->forks = malloc_safely(context->n_philo * sizeof(t_fork));
	handle_mutex_safely(&context->context_mutex, INIT);
	handle_mutex_safely(&context->write_mutex, INIT);
	while (i < context->n_philo)
	{
		handle_mutex_safely(&context->forks[i].fork, INIT);
		context->forks[i].fork_id = i;
		i++;
	}
	initialize_philo(context);
}
