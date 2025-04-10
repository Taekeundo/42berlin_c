/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:10:11 by tkwak             #+#    #+#             */
/*   Updated: 2024/04/23 19:33:16 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	[F]
    [ Definition]
	철학자가 1명만 존재할 경우를 위한 함수

    [ How to proceed ]
    1. await_all_threads_ready
        (동기화 목적) 모든 스레드가 종료될 때까지 대기
    2. atomic_assign_long
        철학자의 마지막 식사 시간 갱신.
        현재시간을 철학자의 마지막 밥먹은 시간 필드에 넣어준다.
    3. increase_nbr_philos
        현재 실행 중인 철학자(스레드)의 수를 증가 (업데이트)
    4. print_status_of_philo
        철학자가 첫 번째 fork 집는 동안의 상태를 출력한다.
        (= 과제에 쓰여있음.)
    5. while (!scenario_finished)
        시나리오 종료 여부 확인, 아직 스레드가 종료 되지않았을 경우
        delay_time() 함수를 사용하여 200마이크로초 동안 대기.
*/
static void	*one_philo(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	block_until_all_threads_ready(philo->context);
	atomic_assign_long(&philo->philo_mutex,
		&philo->last_eat_timestamp, get_current_time(MILLISECOND));
	increase_target_safely(&philo->context->context_mutex,
		&philo->context->n_running_threads);
	print_status_of_philo(PICKUP_1ST_FORK, philo);
	while (!check_scenario_completed(philo->context))
		delay_accurately(300, philo->context);
	return (NULL);
}

/*	[F]
    [ Background ]
    if (nbr_philos) == even number (ex) 2, 4, 6 ..
    Don't need to "think" process
	-> just take turns t0 eat and to sleep.
    = This function works only in tha case,
	  that nbr_philos is odd number.

    [ Properties ]
    If available, make "think" status after "sleep".

    Case(1): philo_odd && t_eat == t_sleep == t_think
    Case(2): philo_odd && t_eat > t_sleep + t_think
    Case(3): philo_odd && t_eat > t_sleep + t_think

    In all cases, t_think = t_eat * 2 - t_sleep;
*/
void	thinking(t_philo *philo, bool previous_scenario)
{
	long	cpy_time_to_eat;
	long	cpy_time_to_sleep;
	long	time_to_think;

	if (!previous_scenario)
		print_status_of_philo(THINK, philo);
	if (philo->context->n_philo % 2 == 0)
		return ;
	cpy_time_to_eat = philo->context->time_to_eat;
	cpy_time_to_sleep = philo->context->time_to_sleep;
	time_to_think = (cpy_time_to_eat * 2) - cpy_time_to_sleep;
	if (time_to_think < 0)
		time_to_think = 0;
	delay_accurately(time_to_think * 0.42, philo->context);
}

/*  [F]
    [ Background ]
    No philosopher can eat two times in a row without think.

    [ How to proceed ]
    1. Grab the forks
        "안전하게 두개의 forks 가져온다, each fork's 상태 변경해준다."
        - first_fork
            print_status_of_philo(eat)
        - second_fork
            print_status_of_philo(eat)
        * Doesn't care about the direction (left & right).

    2. Eat
        "fork 두개가 확보되었기때문에 먹는다."
        - update "last_meal_time"
            atomic_assign_long: Cpy the value for
            ("last_meal_time") to the field of struct.
            "측정한 현재 시간을 기준으로 구조체 필드를 업데이트해준다"
        - update meals_eaten++;
        - print_status_of_philo(eat)
        - delay_time
            식사하는데 걸리는 시간(av3_time_eat)만큼 스레드를 지연시켜준다.
        - if
            만약 철학자가 먹을 수 있는
	    	최대 식사 횟수에 도달하면(required_meals),
            철학자의 상태를 is_full 설정

    3. Release the forks 
        "다 먹고 난 뒤 fork 내려놔야 다른 철학자들이 사용 할 수 있다."
        - If philo doesn't need to use forks anymore,
            UNLOCK both forks.
*/
static void	eating(t_philo *philo)
{
	handle_mutex_safely(&philo->first_fork->fork, LOCK);
	print_status_of_philo(PICKUP_1ST_FORK, philo);
	handle_mutex_safely(&philo->second_fork->fork, LOCK);
	print_status_of_philo(PICKUP_2ND_FORK, philo);
	atomic_assign_long(&philo->philo_mutex,
		&philo->last_eat_timestamp, get_current_time(MILLISECOND));
	philo->eaten_meals++;
	print_status_of_philo(EAT, philo);
	delay_accurately(philo->context->time_to_eat, philo->context);
	if (philo->context->n_required_meals > 0
		&& philo->eaten_meals == philo->context->n_required_meals)
		atomic_assign_bool(&philo->philo_mutex, &philo->is_full, true);
	handle_mutex_safely(&philo->first_fork->fork, UNLOCK);
	handle_mutex_safely(&philo->second_fork->fork, UNLOCK);
}

/*  [F]
    [ How to proceed ]
    1. block_until_all_threads_ready
        Before starts, all philosophers wait. (= "spinlock")
        Until (context->all_threads_ready == true),
		execture while loop.

    2. atomic_assign_long
        Set(cpy) the "current time(base on mili-second)"
		to the "last_meal_time".

    3. increase_target_safely
        update(rise) the number of "n_running_threads",
		field in context struct.
        Goal: For the monitor thread.

    4. adjust_philos_concurrency
        시나리오 시작되기 전 철학자의 수에 따라 홀,짝
		철학자들간의 시간차이를 만들어주는 함수.
        시간의 차이를 통해 충돌을 방지시킨다.

    5. while (시나리오 시작)
        Infinit loop, until the dining is finished.
            is_full	-> "철학자가 포화상태인지 확인" -> 포화(is_full): break;
            eat     -> "아직 배고프면 먹는다."
            sleep   -> "먹었으니 잔다."
                        "av4_time_sleep"에 저장된 값 만큼 잔다.
            think   -> ""
*/
static void	*run_scenario(void *philosopher)
{
	t_philo		*philo;

	philo = (t_philo *)philosopher;
	block_until_all_threads_ready(philo->context);
	atomic_assign_long(&philo->philo_mutex, &philo->last_eat_timestamp,
		get_current_time(MILLISECOND));
	increase_target_safely(&philo->context->context_mutex,
		&philo->context->n_running_threads);
	adjust_philos_concurrency(philo);
	while (check_scenario_completed(philo->context) == false)
	{
		if (atomic_get_bool(&philo->philo_mutex, &philo->is_full))
			break ;
		eating(philo);
		print_status_of_philo(SLEEP, philo);
		delay_accurately(philo->context->time_to_sleep,
			philo->context);
		thinking(philo, false);
	}
	return (NULL);
}

/*  [F]
    [Input]
    ./philo 4 800 200 200 [4]

    [ memo ]
    1. Start of the scenario
    2. Now all threads are ready.
    3. Wait for everyone
    4. All philos are full

    [ How to proceed ]
    1. Check the condition
        a. no meals		->	Return (0).
        b. one philo	->	Call [f] one_phil.
        c. else			->	Call [f] run_scenario.
							= Create all threads safely.

    2. Call [f] monitor_scenario
        Create a "monitor" thread and watching carefully the status.

    3. Synchronize the beggining of the scenario
        pthread_create // philo starts.
        every philo start simultaneously.

    4. Join every threads
        recollect all threads together for the ending. must join.
		(exceiptional case)
		If use "detach" for thread.
*/
void	run_dining(t_dining *context)
{
	int	i;

	i = -1;
	if (context->n_required_meals == 0)
		return ;
	else if (context->n_philo == 1)
		handle_thread_safely(&context->philos[0].philo_thread_id, one_philo,
			&context->philos[0], CREATE);
	else
		while (++i < context->n_philo)
			handle_thread_safely(&context->philos[i].philo_thread_id,
				run_scenario, &context->philos[i], CREATE);
	handle_thread_safely(&context->thread_monitor,
		monitor_scenario, context, CREATE);
	context->time_to_start_scenario = get_current_time(MILLISECOND);
	atomic_assign_bool(&context->context_mutex,
		&context->flag_all_threads_ready, true);
	i = -1;
	while (++i < context->n_philo)
		handle_thread_safely(&context->philos[i].philo_thread_id,
			NULL, NULL, JOIN);
	atomic_assign_bool(&context->context_mutex,
		&context->flag_scenario_end, true);
	handle_thread_safely(&context->thread_monitor, NULL, NULL, JOIN);
}
