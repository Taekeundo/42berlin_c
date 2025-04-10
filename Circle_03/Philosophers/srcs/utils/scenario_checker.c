/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenario_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:09:29 by tkwak             #+#    #+#             */
/*   Updated: 2024/04/23 19:32:05 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	[F]
	[ Definition ]
	특정 철학자가 죽었는지 여부를 확인하는 함수
	= 죽은 경우 시나리오 종료

    [ How to proceed ]
	현재시간에서 마지막으로 먹었던 시간을 빼고
	만일 그게 못먹으면 죽는 시간보다 길 경우 철학자는 죽은거다.
	그러므로 true를 리턴한다.

    1. Check if the philo is is_full,
        = Already finished to eat == is_full
        = Then don't nee to died.
        = return: "false"

    2. Cpy the value of t_elapsed & t_die
        철학자의 경과된 시간(현재시간 - 마지막 식사시간)
        & 안먹으면 죽는 시간을 각각 안전하게 복사해온다.
        av2_time_die 인풋값을 받을때 micro로 parsing파트에서
        이미 변경해줬다. 그래서 단위를 맞춰주기 위해 1000로 나눠줘야 한다.

    3. if (t_elapsed > t_die)
        compare boths. 
        두 값을 비교해서 경과시간이 죽는시간을 이미 초과한 경우
        철학자가 죽었기에 "true"를 리턴한다.

    4. 안죽었으면 무조건 "false" 리턴한다.
*/
static bool	check_philo_is_starved(t_philo *philo)
{
	long	time_since_last_eat;
	long	time_to_die_milli;

	if (atomic_get_bool(&philo->philo_mutex, &philo->is_full))
		return (false);
	time_since_last_eat = get_current_time(MILLISECOND)
		- atomic_get_long(&philo->philo_mutex,
			&philo->last_eat_timestamp);
	time_to_die_milli = philo->context->time_to_die / 1000;
	if (time_since_last_eat > time_to_die_milli)
		return (true);
	return (false);
}

/*  [F]
    [ Background ]
    !! Referee (심판) !!
    각각의 스레드를 돌아다니면서 상태를 체크하는 심판 역할.

    [ Definition ]
    다중 스레드로 실행되는 식사 시나리오 checking하는 기능을 구현.
    
    [ How to proceed ]
    1. 모든 스레드의 실행상태 확인
        while (!check_active_thread_count)
        "n_philo"개수만큼의 (모든)스레드가 실행중인지 checking

        Monitor(Referee) waits until all threads are running.
        = n_philo만큼의 스레드가 실행 중이 아닌 경우에는
          무한 루프를 사용하여 대기.
        = 스핀락(spinlock)의 일종

    2. 식사 시나리오 checking
        while (!scenario_finished)
        모든 철학자가 주어진 조건만큼의 식사를 완료할 때까지 계속해서 식사 상태를 checking

    3. 철학자 상태 확인 및 종료 처리
        while loop 중간중간 각 철학자가 죽었는지 확인.

        if) 철학자가 죽은 경우
            1. 해당 철학자 상태 'DIED'로 변경
            2. scenario_end을 true로 설정
            = 시나리오 종료
*/
void	*monitor_scenario(void *context)
{
	int			i;
	t_dining	*cpy_context;

	cpy_context = (t_dining *)context;
	while (!check_every_thread_running(&cpy_context->context_mutex,
			&cpy_context->n_running_threads, cpy_context->n_philo))
		;
	while (check_scenario_completed(cpy_context) == false)
	{
		i = -1;
		while (++i < cpy_context->n_philo
			&& check_scenario_completed(cpy_context) == false)
		{
			if (check_philo_is_starved(cpy_context->philos + i))
			{
				atomic_assign_bool(&cpy_context->context_mutex,
					&cpy_context->flag_scenario_end, true);
				print_status_of_philo(DIE, cpy_context->philos + i);
			}
		}
	}
	return (NULL);
}
