/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jason <jason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:24:25 by tkwak             #+#    #+#             */
/*   Updated: 2025/04/09 19:49:45 by jason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	for shorten under 25lines for main function.
*/
void	free2d_n_exit(char **str)
{
	free_2d(str);
	exit(EXIT_FAILURE);
}

/*
	for shorten under 25lines for main function.
*/
void	handle_error_dup2(int *kernel_pipe_fd)
{
	perror("dup2: ");
	close(kernel_pipe_fd[0]);
	close(kernel_pipe_fd[1]);
	exit(EXIT_FAILURE);
}

/*
	[Propose]
		1. do execution function.

	[Detail]
		1. ft_split(cmd, ' ')
			Divide all cmd by ' ': make sentences to each word.
			Save each string(word) to the variable "command".

		2. if (!cp_command)
			[f] ft_split fails // malloc fails -> exit(errno);

		3. if (!cp_command[0])
			[f] command starts == '0' // no letter in str(cmd)
*/
void	exec(char *cmd, char **envp)
{
	char	**cmd_div_space;
	char	*path;

	cmd_div_space = ft_split(cmd, ' ');
	if (!cmd_div_space)
		handle_error("ft_split: ");
	if (!cmd_div_space[0])
		free2d_n_exit(cmd_div_space);
	path = check_cmd_in_path(envp, cmd_div_space[0]);
	if (!path)
		free2d_n_exit(cmd_div_space);
	execve(path, cmd_div_space, envp);
	perror("execve: ");
	if (path)
		free(path);
	free_2d(cmd_div_space);
	exit (EXIT_FAILURE);
}

/*
	child process
	[ Setting the FD in child process to change the direction
	of data stream from the original one(= stdio, stdout) to new ]

			before             after
	fd 0 :   STDIN     ->    child_fd (av[1])
	= From now on getting input from ("input_fd").

	fd 1 :   STDOUT    ->    kernel_pipe_fd[1]
	= From now on sending output to ("kernel_pipe_fd[1]").

 	close(kernel_pipe_fd[0])
	= In this function don't need to use kernel_pipe_fd[0].
 
	To prevent memeory leak, close not used fd.

	[Propose]
		1. Using "pipe" connect between cmd1 & cmd2.
		2. Execute child process (cmd1) first and parent process (cmd2) second.

	[Parameter]
		1. int	*argv_pip
			from pipex -> from main

			argv_pip[0]: input (FD for read)
				open the argv[1](= file1) as Read-only and assign the result in pip[0].
			argv_pip[1]: output (FD for write)
				open the argv[4](= file2) as RDWD-mode and assign the result in pip[1].

		2. int	*pipefd
			from [f] pipex

			pipefd[0]: points the end of pipe for "read".
			pipefd[1]: points the end of pipe for "write".

		3. char	*cmd // cmd1 // argv[2]

		4. char **envp // enviornment variable from OS.

	[Detail]
		1. int	first_fd[2]
			fd for child process.

			dup2(int oldfd, int newfd)
				cpy pointer points by oldfd(from parent) to newfd(to child)

			2 - 1. fd[0] = dup2(pip[0], 0)
					dup2를 통해 이제부터 FD[0]은 pip[0]이 가리키는걸 가리킨다.
						현재 pip[0]은 argv[1](= file1), open read-only,를 가리키고 있다.
					= 이제부터 자식프로세스에서 fd[0]은 pip[0]을 가리킨다. (복사)
			
			2 - 2. fd[1] = dup2(pipefd[1], 1);
					dup2를 통해 이제부터 FD[1]은 pipefd[1]이 가리키는걸 가리킨다.
						현재 pip[0]은 argv[1](= file1), read-only,를 가리키고 있다.
					= 이제부터 자식프로세스에서 fd[0]은 pip[0]을 가리킨다. (복사)

			child prcess [FD]		 		     now
					0			-> 	pip[0]: argv[1](= file1)
					1			->	pipefd[1]: end of write side(end) of pipe.

			[File1] to [Child process] to [Pipe's write side] to [Pipe's read side] to [File2]

			3. if (fd[0] == -1 || fd[1] == -1)
				error // close boths fd[0] and fd[1].
					  // close every pipe, that don't need.

			4. if not // success to dup2 (both)
				close (argv_pip[0] && pipefd[1]), already cpy, don't need it anymore.

			5. exec
				execute child process
				when exec success, then not going to exit(2).

			6. exit(2)
				When exec has some error, 
*/
void	child_exe(char **av, int *kernel_pipe_fd, char **envp)
{
	int	input_fd;

	input_fd = open_file(av[1], 0);
	if (input_fd == -1)
		handle_error("open_file: ");
	if (dup2(input_fd, STDIN_FILENO) == -1)
	{
		close(input_fd);
		handle_error_dup2(kernel_pipe_fd);
	}
	close(input_fd);
	if (dup2(kernel_pipe_fd[1], STDOUT_FILENO) == -1)
		handle_error_dup2(kernel_pipe_fd);
	close(kernel_pipe_fd[0]);
	exec(av[2], envp);
	handle_error("exec: ");
	return ;
}

/*
	[ Definition ]
	표준 입력을 kernel_pipe_fd[0]로 표준 출력을 output_fd로 리디렉션하고 프로그램을 실행한다.

	[Question]
	waitpid(pid, NULL, WNOHANG);
	부모 프로세스가 다른 작업을 수행하면서 자식 프로세스의 종료를 주기적으로 확인할 수 있도록 한다..
	따라서 부모 프로세스는 자식 프로세스의 종료 여부에 관계없이 계속해서 실행된다.

	쉽게생각하면 부모프로세스에서 딱히 실행되야할게 없으면 "WNOHANG"를 써도 괜찮다.
	그러나 부모프로세스의 인풋이 자식프로세스가 실행되고 난 뒤에야 얻을 수 있다면 그땐 기다리는게 맞다.
	부모프로세스에서 실행되야할게 있는게 그 인풋값이 파이프를 통해 자식프로세스로부터 넘겨 받아 실행되야 할 경우에는 기다리는게 맞다.

	waitpid(pid, NULL, 0);
	부모 프로세스가 자식 프로세스의 종료를 기다리는 것
	자식 프로세스가 모두 종료될 때까지 부모 프로세스가 차단되어 대기하는 것에는 큰 문제가 없을 수 있다.
	실제로 많은 경우에는 이것이 더 간단하고 안전한 방법일 수 있다.
	그러나 시스템에서 여러 작업을 수행해야 하는 경우에는 차단되지 않고 계속해서 다른 작업을 수행하는 것이 효율적일 수 있다.

	same method with child process.
*/
void	parent_exe(char **av, int *kernel_pipe_fd, char **envp)
{
	int	output_fd;

	output_fd = open_file(av[4], 1);
	if (output_fd == -1)
		handle_error("open_file: ");
	if (dup2(output_fd, STDOUT_FILENO) == -1)
	{
		close(output_fd);
		handle_error_dup2(kernel_pipe_fd);
	}
	close(output_fd);
	if (dup2(kernel_pipe_fd[0], STDIN_FILENO) == -1)
		handle_error_dup2(kernel_pipe_fd);
	close(kernel_pipe_fd[1]);
	exec(av[3], envp);
	handle_error("exec: ");
	return ;
}
