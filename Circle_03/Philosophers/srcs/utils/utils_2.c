/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:12:43 by tkwak             #+#    #+#             */
/*   Updated: 2024/04/23 19:31:48 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	[F]
    [ Definition ]
    테이블 구조체의 member "flag_all_threads_ready(type: bool)"를 가져오는 함수.

    [ Goal ]
    공유자원의 boolean값을 안전하게(To syncronize) 가져오기 위해 사용되는 함수.

    [ Example ]
    어느 스레드가 boolean값을 수정중인데, 다른 스레드가 boolean값을 사용하기 위해 가져올 경우 충돌한다.
    그럴 경우를 막기 위해 뮤텍스를 갖고있는 스레드만 불리안값을 가져올 수 있도록 위 함수를 만들어줬다.
*/
void	block_until_all_threads_ready(t_dining *context)
{
	while (!atomic_get_bool(&context->context_mutex,
			&context->flag_all_threads_ready))
		;
}

/*  [F]
    [ Definition ]
    Rise the number of the running threads,
    to synchronize with the monitor thread.
*/
void	increase_target_safely(t_mtx *mutex, long *target)
{
	handle_mutex_safely(mutex, LOCK);
	(*target)++;
	handle_mutex_safely(mutex, UNLOCK);
}

/*	[F]
    [ Definition ]
    주어진 스레드 수만큼의 스레드가 실행 중인지 확인하는 함수.

    [ Background ]
    때때로 (스레드 생성 실패, 시스템 부하 등등의 이유로)
    일부 스레드가 실행되지 않을 경우가 존재한다.

    [ Goal ]
    모든 스레드가 잘 생성되었고, 스레드 개수만큼
    모두 실행되고 있는지를 확인하는게 첫번째 순서다.

    [ Param ]
    Param(1) mutex
        = For mutual exclusion.
    Param(2) *threads
        = "&context->n_running_threads"
        = 현재 실행중인 스레드 개수
    
    [ Return ]
    모든 스레드가 실행 중이면 true를 반환
*/
bool	check_every_thread_running(t_mtx *mutex, long *threads,
		long n_philo)
{
	bool	res;

	res = false;
	handle_mutex_safely(mutex, LOCK);
	if (*threads == n_philo)
		res = true;
	handle_mutex_safely(mutex, UNLOCK);
	return (res);
}

/*	[F]
    [ Definition ]
    철학자 개수 짝수: 고의 지연
    철학자 개수 홀수: think실행

    [ Background ]
    스레드 개수가 짝수일 때 think 과정이 없이
    두 분류의 스레드들은 eat과 sleep를 번갈아가면서 사용한다.
    문제는 eat에서 sleep으로 넘어가는 컨텍스트 스위칭 과정에서
    사람에게는 체감되지 않을 정도의 아주 적은 시간이 써지고 있다.
    그래서 그것들이 쌓이다보면 결국 에러를 발생시킨다.
    이러한 문제를 방지하기 위해 스레드 개수가 짝수일 경우
    "30ms"만큼씩 계속해서 실행시간을 지연시켜준다.
    지연된 시간 동안 컨텍스트 스위칭을 하라고 고의로 지연시켜주는 함수다.
    
    [ Goal ]
    스레드의 수에 따라 동시성을 조정하는 데 사용.
    스레드간의 조정, 충돌을 방지.

    [ How to proceed ]
    1. Check the number of philosophers,
		whether it is odd or even.
        철학자의 총 수가 짝수인지 홀수인지 확인

    2. If even nbr
        테이블에 앉은 철학자의 수가 (짝수: even)
        If 현재 철학자가 짝수번째일 경우
            " 30ms 대기 "
            -> 3e4: 30,000  micro-second
                    30      milli-second // "30ms"
                    0.03    second

    3. else odd nbr
        테이블에 앉은 철학자의 수가 (홀수: odd)
        If 현재 철학자가 홀수번째일 경우
            -> 홀수 번호를 가진 철학자
            -> start the function "think"
*/
void	adjust_philos_concurrency(t_philo *philo)
{
	if (philo->context->n_philo % 2 == 0)
	{
		if (philo->philo_id % 2 == 0)
			delay_accurately(3e4, philo->context);
	}
	else
	{
		if (philo->philo_id % 2)
			thinking(philo, true);
	}
}

/*  [F]
    [ Definition ]
    철학자가 자신의 현재상태를 변경하고 출력한다.

    [ Properties ]
    1. %-6ld
     %: format specifier
     -: Arrange the line based on the left.
     6: 문자열의 최소 길이 6
     ld: value type is "long".
     = 최소 6자리를 가진 long 타입 변수를 왼쪽 정렬하여 출력하라는 의미
*/
void	print_status_of_philo(t_philo_status status, t_philo *philo)
{
	long	t_since_scenario;

	t_since_scenario = get_current_time(MILLISECOND)
		- philo->context->time_to_start_scenario;
	if (atomic_get_bool(&philo->philo_mutex, &philo->is_full))
		return ;
	handle_mutex_safely(&philo->context->write_mutex, LOCK);
	if ((status == PICKUP_1ST_FORK || status == PICKUP_2ND_FORK)
		&& !check_scenario_completed(philo->context))
		printf(""EMP"%-5ld"RS" %d has taken a "C"fork"RS"\n",
			t_since_scenario, philo->philo_id);
	else if (status == EAT && !check_scenario_completed(philo->context))
		printf(""EMP"%-5ld"RS" %d is "G"eating"RS"\n",
			t_since_scenario, philo->philo_id);
	else if (status == SLEEP && !check_scenario_completed(philo->context))
		printf(""EMP"%-5ld"RS" %d is "B"sleeping"RS"\n",
			t_since_scenario, philo->philo_id);
	else if (status == THINK && !check_scenario_completed(philo->context))
		printf(""EMP"%-5ld"RS" %d is "P"thinking"RS"\n",
			t_since_scenario, philo->philo_id);
	else if (status == DIE)
		printf(""EMP"%-5ld"RS" %d "RED"died"RS"\n",
			t_since_scenario, philo->philo_id);
	handle_mutex_safely(&philo->context->write_mutex, UNLOCK);
}
