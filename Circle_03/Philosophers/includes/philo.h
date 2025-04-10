/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:45:34 by tkwak             #+#    #+#             */
/*   Updated: 2024/04/22 09:11:10 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* HEADER FILE */
#ifndef PHILO_H
# define PHILO_H

/* MAXIMUM n_philo: 200 */
# ifndef PHILO_MAX
#  define PHILO_MAX 200
# endif

/* COLOR FOR PRINTING */
# define RS		"\033[0m"			// 	Reset
# define C      "\033[1;36m"		// 	Cyan	: Fork
# define G      "\033[1;32m"		// 	Green	: Eat
# define B      "\033[1;34m"		// 	Blue	: Sleep
# define P      "\033[1;35m"		// 	Purple	: Think
# define RED	"\033[1;31m"		// 	Red		: Die
# define W      "\033[1;37m"		// 	White	: Example
# define Y      "\033[1;33m"		// 	Yellow	: NOT USED
# define EMP	"\033[30;47;20m"	//	Memo	: Time

// Memo ANSI escape sequence
//	\033	ANSI starts					: must
//	[1;		Thinkness of the character	: bold
//	30		Color of the charactor		: black
//	47		Color of the background		: white
//	20		Thinkness of the character	: middle

/* HEADER FILES */
# include <stdio.h>      // printf
# include <limits.h>	 // INT_MAX
# include <sys/time.h>   // gettimeofday
# include <stdlib.h>     // malloc, free
# include <unistd.h>     // write, usleep
# include <stdbool.h>    // boolean type (true, false)
# include <errno.h>      // Macro for system error numbers
# include <pthread.h>    // pthread_create, pthread_detach, pthread_join
# include <string.h>     // memset, NOT USED.

/* ENUM */
// Status of philo during the scenario
// List, which enumerates about "PHILO's STATUS" micro.
typedef enum e_philo_status
{
	EAT,
	SLEEP,
	THINK,
	PICKUP_1ST_FORK,
	PICKUP_2ND_FORK,
	DIE,
}	t_philo_status;

// List, which enumerates about TIME micro.
typedef enum e_time
{
	SECONDS,
	MILLISECOND,
	MICROSECOND,
}	t_time;

// List, which enumerates about "MUTEX & THREAD's ACTION" micro.
typedef enum e_action
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_action;

/* STRUCTURE */
// For the recursive each other.
// 두 구조체가 서로를 참조하고 있는 상황
// 그래서 테이블 구조체를 별도로 한번 더 선언해준다.
typedef struct s_dining	t_dining;
typedef pthread_mutex_t	t_mtx;

/*
	[ Members ]
	fork		[f] initialize_all_struct
				+ [f] handle_mutex_safely
				= 각 포크(스레드)가 사용하는 뮤텍스

	fork_id		[f] initialize_all_struct
				+ [f] handle_mutex_safely
				= 각 포크의 식별을 위한 넘버
*/
typedef struct s_fork
{
	t_mtx		fork;
	int			fork_id;
}				t_fork;

/*
	[ Members ]
	philo_id;		// [f] initialize_philo
	is_full;		// [f] initialize_philo
	eaten_meals;	// [f] initialize_philo
	*context;		// [f] initialize_philo

	philo_mutex;	// [f] handle_mutex_safely

	*first_fork;	// [f] determine_fork_order
	*second_fork;	// [f] determine_fork_order

	last_eat_timestamp;		???: For monitor, eat, run_scenario
	philo_thread_id;		???: For philo execute "CREATE, JOIN"

	[ Memo ]
	1. first_fork, second_fork
		Each philo has their own order,
		which fork should pick first up.

	2. philo_thread_id
		각 철학자의 스레드를 구분하기 위한 식별자
		철학자라고 이름만 있지 이게 스레드인지 아닌지에 대해서는
		thread_id멤버를 사용하지 않고선 알 수 없다.
		t_philo구조체가 스레드라는걸 알 수 있게끔 구분해주는 멤버다.
*/
typedef struct s_philo
{
	int				philo_id;
	bool			is_full;
	long			eaten_meals;
	t_dining		*context;
	t_mtx			philo_mutex;
	t_fork			*first_fork;
	t_fork			*second_fork;
	long			last_eat_timestamp;
	pthread_t		philo_thread_id;
}	t_philo;

/*
	[ Members ]
	n_philo;				// [f] parse_argv_and_cpy_to_context: av[0]
	time_to_die;			// [f] parse_argv_and_cpy_to_context: av[1]
	time_to_eat;			// [f] parse_argv_and_cpy_to_context: av[2]
	time_to_sleep;			// [f] parse_argv_and_cpy_to_context: av[3]
	n_required_meals;		// [f] parse_argv_and_cpy_to_context: av[4]

	n_running_threads;		// [f] initialize_all_struct
	flag_scenario_end;		// [f] initialize_all_struct
	flag_all_threads_ready;	// [f] initialize_all_struct

	context_mutex;			// [f] handle_mutex_safely
	write_mutex;			// [f] handle_mutex_safely
	*forks;					// [f] handle_mutex_safely

	*philos;				// [f] initialize_philo

	thread_monitor;				???
	time_to_start_scenario;		???

	[ Memo ]
	1. context_mutex
		To Avoid races while threads reading.
		테이블에 앉아 있는 스레드들(즉, 철학자들)이
		작업을 수행하기 위해서 상호 배제(mutex)를
		획득해야 하는 동기화 객체.

	2. thread_monitor
		Thread to track if scenario works well or not.

	3. forks, philos
		array of every forks & philos.
*/
struct	s_dining
{
	long		n_philo;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		n_required_meals;
	long		n_running_threads;
	bool		flag_scenario_end;
	bool		flag_all_threads_ready;
	t_mtx		context_mutex;
	t_mtx		write_mutex;
	t_fork		*forks;
	t_philo		*philos;
	pthread_t	thread_monitor;
	long		time_to_start_scenario;
};

/* PROTOTYPES FOR 35 FUNCTIONS */
//	[f] atomic_mutex.c 
//	4EA
void	atomic_assign_bool(t_mtx *mutex, bool *dest, bool value);
bool	atomic_get_bool(t_mtx *mutex, bool *value);
void	atomic_assign_long(t_mtx *mutex, long *dest, long value);
long	atomic_get_long(t_mtx *mutex, long *value);

//	[f] dining.c
//	5EA
// static void	*one_philo(void *philosopher);
void	thinking(t_philo *philo, bool previous_scenario);
// static void	eating(t_philo *philo);
// static void	*run_scenario(void *philosopher);
void	run_dining(t_dining *context);

//	[f] handle_safely.c
//	5EA
void	*malloc_safely(size_t size_of_memory);
// const char	*get_mutex_error_message(int status, t_action action);
void	handle_mutex_safely(t_mtx *mutex, t_action action);
// const char	*get_thread_error_message(int status, t_action action);
void	handle_thread_safely(pthread_t *thread, void *(*f)(void *),
			void *data, t_action action);

//	[f] initializer.c
//	3EA
// static void	determine_fork_order(t_philo *philo, t_fork *forks,
// 		int philo_pos)
// static void	initialize_philo(t_dining *context);
void	initialize_all_struct(t_dining *context);

//	[f] scenario_checker.c
//	2EA
// static bool	check_philo_is_starved(t_philo *philo);
void	*monitor_scenario(void *context);

//	[f] utils_1.c
//	5EA
long	get_current_time(int type_of_time);
void	delay_accurately(long time_to_delay,
			t_dining *scenario_context);
void	release_all_resources(t_dining *context);
void	print_error_and_exit(const char *error_message);
bool	check_scenario_completed(t_dining *context);

//	[f] utils_2.c
//	5EA
void	block_until_all_threads_ready(t_dining *context);
void	increase_target_safely(t_mtx *mutex, long *target);
bool	check_every_thread_running(t_mtx *mutex, long *threads, long n_philo);
void	adjust_philos_concurrency(t_philo *philo);
void	print_status_of_philo(t_philo_status status, t_philo *philo);

//	[f] main.c
//	5EA
// static bool	is_space(char c);
// static bool	is_digit(char c);
// static long	ft_atol(const char *str);
// static void	parse_argv_and_cpy_to_context(t_dining *context, char **argv);
// int	main(int argc, char **argv);

#endif
