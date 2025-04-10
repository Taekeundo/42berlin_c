/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:11:20 by tkwak             #+#    #+#             */
/*   Updated: 2024/04/25 17:25:26 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*  [F]
    [ Definition ]
    현재 시간을 측정하고
    사용자가 지정한 단위로 변환하여 반환하는 기능을 수행.

    [ Properties ]
    milli second * 1e3 (1000) = second.
    micro second * 1e3 (1000) = milli second.
    micro second * le6 (1000000) = second.

    delay_time: micro second.

    [ Reference ]
    Header file:
        #include <sys/time.h>

    STRUCT_TIMEVAL
    {
        __darwin_time_t         tv_sec;   // seconds
        __darwin_sdelay_timeonds_t    tv_delay_time;  // microseconds
    };

    (ex)
    int main(void)
    {
        struct timeval currentTime;
        gettimeofday(&currentTime, NULL);
        // 현재 시간 정보를 얻기 위해 gettimeofday 함수 호출

        printf("Current time: %ld seconds, %ld microseconds\n",
		currentTime.tv_sec, currentTime.tv_delay_time);
        // 현재 시간 정보 출력
        return 0;
    }
*/
long	get_current_time(int type_of_time)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		print_error_and_exit("Gettimeofday(time.h) failed");
	if (type_of_time == MILLISECOND)
		return (time.tv_sec * 1e3 + time.tv_usec / 1e3);
	else if (type_of_time == MICROSECOND)
		return (time.tv_sec * 1e6 + time.tv_usec);
	else if (type_of_time == SECONDS)
		return (time.tv_sec + time.tv_usec / 1e6);
	else
		print_error_and_exit("Wrong input to get_current_time");
	return (-1);
}

/*	[F]
	[ Definition ]
	정밀한 마이크로초(us) 단위의 사용자가 입력한 시간 만큼 지연시키는 함수.
	뮤텍스를 갖고 있는 시간이라고 이해하면 편하다.

    [ Goal ]
    정확한 지연(대기)을 하기위한 목적
    - 긴 대기 시간: usleep
    - 짧은 대기 시간: spinlock

    [ Example ]
    실제로 1초 동안 진행되야 하는 함수가 있는데 0.9초만 실행되고 끝났다.
    그럴때 이 함수를 사용해서 0.1초만큼 의도적으로 딜레이 시켜준다.
    remain_time, 남은 시간의 크기에 따라 usleep || spinlock 중 선태 사용한다.

    [ Background ]
    1. usleep
        System call로서 일정 시간 동안 프로세스를 대기 상태로 전환.
        일반적으로 usleep 함수를 사용할 때 대부분의 경우 0.01초(10,000 마이크로초) 단위를
        기준으로 사용하는 것이 일반적.
    2. spinlock
        무한 루프로서 CPU를 점유하며 대기하는 방법. (계속 문의: infinite ask)
    3. elapsed
        사전적 의미로 경과시간

    [ Param ]
    Param(1): delay_time // 지연시간

    [ How to proceed ]
    1. start_time
        함수를 호출한 시간을 가져와서 시작시간으로 설정.

    2. while loop
        현재 시간 - 시작시간 < delay_time == 루프 실행.

    3. if (scenario_finished)
        시나리오 완료되었을 경우 지연시킬 필요 없음. 루프 빠져나오기.

    4. elapsed_time = get_current_time(현재시간) - starttime(시작시간);
        remain_time = delay_time(지연시켜야 하는 시간) - elapsed_time(경과시간);
        경과시간 확인 & 남은시간 확인

    6. remain_time > 1e4 (0.)
        남은 시간이 0.01초를 초과할 경우 usleep사용.
        1초 == 1,000초 = 1,000,000초
        0.01초 == 10초 = 10,000초

    7. else
        남은 시간이 1e4 이하인 경우
        less than 1 second.
        지연시켜야 하는 시간이 1초보다 적게 남았을 경우 
        루프 돌리면서 대기시킨다. (spinlock)
    
        *return ;을 굳이 써준 이유
        = 명시적으로 해당 함수를 즉시 종료시키고
          호출한 곳으로 돌아가게 만들기 위해.
*/
void	delay_accurately(long time_to_delay, t_dining *scenario_context)
{
	long	time_start;
	long	time_since_start;
	long	time_remain;

	time_start = get_current_time(MICROSECOND);
	while (get_current_time(MICROSECOND) - time_start < time_to_delay)
	{
		if (check_scenario_completed(scenario_context))
			break ;
		time_since_start = get_current_time(MICROSECOND) - time_start;
		time_remain = time_to_delay - time_since_start;
		if (time_remain > 10000)
			usleep(time_remain / 2);
		else
			while (get_current_time(MICROSECOND) - time_start < time_to_delay)
				;
	}
}

/*  [F]
    Free the context to avoid memory leaks.

    [ How to proceed ]
    1. 각각의 철학자가 갖고 있는 뮤텍스(philo_mutex)를 제거한다.
    2. 테이블에서 철학자들이 공통으로 사용한
        뮤텍스(context_mutex, write_mutex)를 제거한다.
    3. 철학자와 fork에 할당되었던 메모리를 해제한다.
*/
void	release_all_resources(t_dining *context)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < context->n_philo)
	{
		philo = context->philos + i;
		handle_mutex_safely(&philo->philo_mutex, DESTROY);
		i++;
	}
	handle_mutex_safely(&context->write_mutex, DESTROY);
	handle_mutex_safely(&context->context_mutex, DESTROY);
	free(context->forks);
	free(context->philos);
}

/*  [F]
	[ Goal ]
    If error occurs,
	1. Print the current error message.
    2. Send the error code about "exit" and exit the function.
*/
void	print_error_and_exit(const char *error_message)
{
	printf("%s\n", error_message);
	exit(EXIT_FAILURE);
}

/*	[F]
    [ Definition ]
    시나리오 종료되었을때(끝났을때) 테이블 field(member)의
	flag_scenario_end(= bool type)채워준다.
*/
bool	check_scenario_completed(t_dining *context)
{
	return (atomic_get_bool(&context->context_mutex,
			&context->flag_scenario_end));
}
