/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jason <jason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:10:08 by tkwak             #+#    #+#             */
/*   Updated: 2025/04/09 19:49:42 by jason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	Double array must free twice,
	once is for "arr[i][j]"", once is for "arr[i]".
*/
void	free_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free (arr);
}

/*
	for shorten under 25lines for main function.
*/
void	handle_error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

/*
	for shorten under 25lines for main function.
*/
void	print_usage_and_exit(void)
{
	ft_printf("Example: ./pipex infile cmd cmd outfile\n");
	exit(EXIT_FAILURE);
}

/*
	for shorten under 25lines for main function.
*/
void	ft_creat_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
		handle_error("pipe: ");
}

/*
	주어진 명령어(cmd)를 실행(execute)하는 역할

	1. cmd 문자열을 공백을 기준으로 분할하여 배열로 저장.(ft_split)
	2. 만약 cmd_div_space가 NULL을 반환하면,
		메모리 할당 오류가 발생한 것으로 간주하고 errno을 사용하여 프로그램 종료.
	3. 만약 cmd_div_space[0]이 NULL이면, 분할된 명령어가 없다는 것이므로
		오류로 간주하고 free_2d 함수를 사용하여 메모리를 해제한 후, 프로그램 종료.
	4. 주어진 환경 변수(envp)에서 명령어의 경로를 찾아서 반환.
		만약 해당 경로를 찾을 수 없는 경우에도 오류로 처리하고 프로그램 종료.
	5. execve 시스템 호출을 사용하여 주어진 경로의 명령어를 실행
		만약 실행에 실패하면 errno을 사용하여 프로그램 종료.
		execve가 성공적으로 반환되면 아래 코드는 실행되지 않아야 정상이다.
	6. 아래 코드가 실행됐다는건 오류가 발생했다는 의미다.
		메모리 해제를 위해 동적으로 할당된 자원을 해제한다.
		프로그램을 errno을 사용하여 종료한다.

	[Detail]
	1. Declare array "pip[2]"
		For file open and save result from file.
	
	2. Check argc
		Argc must be '5'
		(ex)./pipex		file1		cmd1		cmd2		file2
		 	 argv[0]	argv[1]		argv[2]		argv[3: argc - 2]		argv[4: argc - 1]
	
	3. Assign pipe
		pip[0]: open the argv[1](= file1) as Read-only and save(assign) the result in pip[0].
		pip[1]: open the argv[4](= file2) as RDWD-mode and save(assign) the result in pip[1].
				O_TRUNC // If there is already file, initialize file. (truncate: cut)
				O_CREAT // If there is no file, create file.
				O_RDWR	// Open file with (read & write mode)
				0000644 // Setting permission
						// User: 6: Read + write
						// Group: 4: Read
						// Others: 4: Read

	4. Error handling (pip[0], pip[1])
		pip[0] && pip[1] < 3:
			It must start from '3' // stdio(0), stdout(1), stderr(2)
		perror(""):	Print a system error message
					If there is no certain message inbetween "", it prints stardard error message.

	5. Error handling (cmd1, cmd2)
		Target: cmd1 = argv[2]
				cmd2 = argv[3 == argc - 2]

		envp: Standard to compare whether cmd1,2 is saved in OS system.
			  All commands are saved in path in OS system. If not, it's error.
			  We can find commands in (envp). Just put "env" in termianl, then we can check.

	6. Pipe(pip, argv[2], argv[3], envp)
		Check function detail.
*/
int	main(int ac, char **av, char **envp)
{
	int		kernel_pipe_fd[2];
	pid_t	pid;

	if (ac != 5)
		print_usage_and_exit();
	print_error_cmd(envp, av[2]);
	print_error_cmd(envp, av[3]);
	ft_creat_pipe(kernel_pipe_fd);
	pid = fork();
	if (pid < 0)
		handle_error("fork: ");
	else if (pid == 0)
		child_exe(av, kernel_pipe_fd, envp);
	else
	{
		waitpid(pid, NULL, WNOHANG);
		parent_exe(av, kernel_pipe_fd, envp);
	}
	return (0);
}
