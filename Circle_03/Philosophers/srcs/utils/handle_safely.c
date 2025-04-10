/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_safely.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:58:03 by tkwak             #+#    #+#             */
/*   Updated: 2024/04/18 11:37:18 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*  [F]
    [ Definition ]
    동적 메모리 할당을 할 때, 아주 가끔 발생하는 할당 실패를 처리하는 함수.

    [ Goal ]
    malloc함수를 사용할때마다 매번 적어줘야하는 error case handling의 수고로움이 줄어든다.

    [ Parameter ]
    size_t size_of_memory // 어떤 유형의 타입도 sizeof()연산자를 사용해 바이트 단위로 받는다.

    [ Example ]
    1. int   *arr = (int *)malloc_safely(sizeof(int) * n);
    2. char  *str = (char *)malloc_safely(sizeof(char) * (length + 1));
*/
void	*malloc_safely(size_t size_of_memory)
{
	void	*res;

	res = malloc(size_of_memory);
	if (res == NULL)
		print_error_and_exit(RED"Error: malloc fails"RS);
	return (res);
}

/*  [F]
    [ Description ]
    There are error codes that are output when each thread function fails.
    각각의 mutex함수마다 실패했을 경우 출력되는 에러코드(message)들이 존재한다.
    ex) pthread_mutex_lock함수가 호출에 실패할 경우
    	return으로 EINVAL를 반환한다.
        해당 에러코드에 맞는
	"The value specified by mutex is invalid"를 터미널에 출력한다.
    
    [Goal]
    When functions, related with MUTEX, fail,
    this function prints out the fittable error message to the terminal.
    = Mutex함수들이 실패했을때 그에 맞는 에러메시지 출력을 위해 만들어진 함수.

    [ Reference ]
    (In terminal) man pthread_mutex_lock
    (In terminal) man pthread_mutex_unlock
    (In terminal) man pthread_mutex_init
    (In terminal) man pthread_mutex_destroy
*/
const char	*get_mutex_error_message(int status, t_action action)
{
	const char	*error_message;

	error_message = "Unknown error";
	if (status == EINVAL)
	{
		if (action == LOCK || action == UNLOCK)
			error_message = "Invalid mutex value";
		else if (action == INIT)
			error_message = "Invalid attr value";
	}
	else if (status == EDEADLK)
		error_message = "Deadlock would occur";
	else if (status == EPERM)
		error_message = "No permission to access mutex";
	else if (status == ENOMEM)
		error_message = "Insufficient memory to create mutex";
	else if (status == EBUSY)
		error_message = "Mutex is already locked";
	return (error_message);
}

/*  [F]
    [ Definition ]
    Mutex관련 함수들의 실패 상황을 핸들링하는 함수.

	[ Background ]
	pthread_mutex_000함수들은 성공할 경우 0을 리턴한다.

    [ Goal ]
    어떤 Mutex함수가 실패했는지 구분 하기 위해.
*/
void	handle_mutex_safely(t_mtx *mutex, t_action action)
{
	int			status;
	const char	*error_message;

	status = 0;
	if (action == LOCK)
		status = pthread_mutex_lock(mutex);
	else if (action == UNLOCK)
		status = pthread_mutex_unlock(mutex);
	else if (action == INIT)
		status = pthread_mutex_init(mutex, NULL);
	else if (action == DESTROY)
		status = pthread_mutex_destroy(mutex);
	else
	{
		print_error_and_exit("Invalid action: "
			"only available be [LOCK] [UNLOCK] [INIT] [DESTROY]");
		return ;
	}
	if (status != 0)
	{
		error_message = get_mutex_error_message(status, action);
		print_error_and_exit(error_message);
	}
}

/*  [F]
    [ Description ]
    각각의 스레드함수마다 실패했을 경우 출력되는 에러코드들이 존재한다.

    [ Goal ]
    Thread함수들이 실패했을때 그에 맞는 에러메시지 출력을 위해 만들어진 함수.
*/
const char	*get_thread_error_message(int status, t_action action)
{
	const char	*error_message;

	error_message = "Unknown error";
	if (status == EAGAIN)
		error_message = "No resources to create another thread";
	else if (status == EPERM)
		error_message = "The caller does not have appropriate permission\n";
	else if (status == EINVAL)
	{
		if (action == CREATE)
			error_message = "The value specified by attr is invalid.";
		else if (action == JOIN || action == DETACH)
			error_message = "The value specified bt thread is not joinable\n";
	}
	else if (status == ESRCH)
		error_message = "No thread could be found corresponding "
			"to the specified tread ID";
	else if (status == EDEADLK)
		error_message = "A deadlock was detected or the value of "
			"thread specifies the calling thread.";
	return (error_message);
}

/*  [F]
    [ Definition ]
    Thread관련 함수들의 실패 상황을 핸들링하는 함수.

    [ Goal ]
    어떤 Thread함수가 실패했는지 구분 하기 위해.
*/
void	handle_thread_safely(pthread_t *thread, void *(*f)(void *),
		void *data, t_action action)
{
	int			status;
	const char	*error_message;

	status = 0;
	if (action == CREATE)
		status = pthread_create(thread, NULL, f, data);
	else if (action == JOIN)
		status = pthread_join(*thread, NULL);
	else if (action == DETACH)
		status = pthread_detach(*thread);
	else
	{
		print_error_and_exit("Invalid action: "
			"only available be [CREATE] [JOIN] [DETACH]");
		return ;
	}
	if (status != 0)
	{
		error_message = get_thread_error_message(status, action);
		print_error_and_exit(error_message);
	}
}
