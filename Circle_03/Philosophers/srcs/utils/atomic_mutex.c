/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atomic_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:44:03 by tkwak             #+#    #+#             */
/*   Updated: 2024/04/21 19:10:23 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*  [F]
    [ Goal ]
	To use the mutex (LOCK, UNLOCK)
	for safely setting the value, which is "bool" type.
	= 뮤텍스를 사용하여 안전하게 bool 변수에 값을 설정하는 기능

    [ How to proceed ]
    1. Lock the mutex
        뮤텍스를 잠그고(lock)

    2. Assign the value to the *dest
        dest변수에 (bool type)value값을 할당한 후

    3. Unlock the mutex
        뮤텍스를 해제(unlock)

    [ Core ]
    1. atomic_assign_bool & atomic_assign_long
        변수값을 수정할때 사용하는 함수
        현재 스레드가 수정중일때 다른 스레드들이 동시에 수정하거나,
        아직 최종적으로 수정되지 않은 값인데 읽어가는 일이 발생하지 않도록
        mutex lock을 걸어 다른 스레드들의 접근을 막는다.
        
    2. atomic_get_bool & atomic_get_long
        변수값을 가져올때(읽을때) 사용하는 함수
        읽는동안 다른 스레드가 수정할수 없게끔 mutex lock을 걸어 다른 스레드들의 접근을 막는다.
*/
void	atomic_assign_bool(t_mtx	*mutex, bool *dest, bool value)
{
	handle_mutex_safely(mutex, LOCK);
	*dest = value;
	handle_mutex_safely(mutex, UNLOCK);
}

/*  [F]
    [ How to proceed ]
    1. Lock the mutex
        뮤텍스를 잠그고(lock)

    2. Assign the value to the [res]
        res변수에 (bool type)value값을 할당한 후

    3. Unlock the mutex
        뮤텍스를 해제(unlock)
    
    4. Return (res)
        복사된 결과값을 출력한다.
*/
bool	atomic_get_bool(t_mtx *mutex, bool *value)
{
	bool	res;

	handle_mutex_safely(mutex, LOCK);
	res = *value;
	handle_mutex_safely(mutex, UNLOCK);
	return (res);
}

/*  [F]
    [ How to proceed ]
    1. Lock the mutex
        뮤텍스를 잠그고(lock)

    2. Assign the value to the *dest
        dest변수에 (long type)value값을 할당한 후

    3. Unlock the mutex
        뮤텍스를 해제(unlock)
*/
void	atomic_assign_long(t_mtx *mutex, long *dest, long value)
{
	handle_mutex_safely(mutex, LOCK);
	*dest = value;
	handle_mutex_safely(mutex, UNLOCK);
}

/*  [F]
    [ How to proceed ]
    1. Lock the mutex
        뮤텍스를 잠그고(lock)

    2. Assign the value to the [res]
        res변수에 (long type)value값을 할당한 후

    3. Unlock the mutex
        뮤텍스를 해제(unlock)
    
    4. Return (res)
        복사된 결과값을 출력한다.
*/
long	atomic_get_long(t_mtx *mutex, long *value)
{
	long	res;

	handle_mutex_safely(mutex, LOCK);
	res = *value;
	handle_mutex_safely(mutex, UNLOCK);
	return (res);
}
