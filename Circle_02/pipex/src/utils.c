/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jason <jason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:11:13 by tkwak             #+#    #+#             */
/*   Updated: 2025/04/09 19:52:03 by jason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	Param[1]: char *file
				Get information from file(= av[1])

	Param[2]: int in_or_out
				Flag for checking whether it's input or output.
				0: in && 1: out.

	open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777) // Order is this right.
			(1) O_WRONLY
			(2) O_CREAT // if there is no file, then create.
			(3) O_TRUNC // if there is already file, then truncated to zeror length.

	file open following the flag
	if (flag) is 0 -> open file READ-ONLY
	if (flag) is 1 -> OPEN file WRITE_ONLY and give Right // 644
*/
int	open_file(char *file, int in_or_out)
{
	int	res;

	res = 0;
	if (in_or_out == 0)
		res = open(file, O_RDONLY);
	else if (in_or_out == 1)
		res = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (res < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (res);
}

/*
	[Propose]
		1. Find "PATH=" string from env (= OS's environment)
		2. If find, save string after passing 5 characters("PATH=""), which is indiviually based on colon(:).
			ft_strlen("PATH="): starting pointer of ft_split is envp[i][5].
		
	[Detail]
		During "env" isn't over, If found string("PATH=") in env,
		return a pointer of string that is after ("PATH=")
		and should save all contents by the newline based on "colon(:)".
	
	[Example]
		PATH=  /user/bin:/bin:/user/local/bin
		
		PATH(1): /user/bin
		PATH(2): /bin
		PATH(3): /user/local/bin
*/
char	**save_all_env_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(&envp[i][ft_strlen("PATH=")], ':'));
		i++;
	}
	perror("save_all_env_paths: ");
	exit(EXIT_FAILURE);
}

/*
	[Propose]
		Construct command(doesn't start '/')'s path from relative path to absolute path.

	[Detail]
		1. 'touch'
			check path where is stored = /usr/bin
			path_array[4] = /usr/bin

		2. ft_strjoin
			path_array[4] = /usr/bin   +   '/'
			part_path = /usr/bin/

		3. ft_strjoin
			part_path = /usr/bin/    +    command = touch
			path: /usr/bin/touch
		
		4. free (part_path)
			no more need.

		= touch's path is changed from relative to absolute.
*/
char	*convert_command_absolute_path(char **path_array, int i, char *command)
{
	char	*part_path;
	char	*absolute_path;

	part_path = ft_strjoin(path_array[i], "/");
	if (part_path == NULL)
	{
		perror("ft_strjoin: ");
		return (NULL);
	}
	absolute_path = ft_strjoin(part_path, command);
	free(part_path);
	if (absolute_path == NULL)
	{
		perror("ft_strjoin: ");
		return (NULL);
	}
	return (absolute_path);
}

/*
	[Propose]
		check whether command is stored by OS's enviornment.

	[Detail]
		1. save_all_env_paths(env)
			Extract paths from environment variable and store them in path_array, split by ":".

			path_array[0]: /home/tkwak/bin
			path_array[1]: /usr/local/sbin
			path_array[2]: /usr/local/bin
			path_array[3]: /usr/sbin
			path_array[4]: /usr/bin
			path_array[5]: /sbin
			path_array[6]: /bin
			path_array[7]: /usr/games
			path_array[8]: /usr/local/games
			path_array[9]: /snap/bin

		2. while
			If (Relative path)
				Command doesn't start '/'
				(ex) touch, ls, mkdir ..

				= construct a full path for command by using the function (convert_command_absolute_path).

				2 - 1. convert_command_absolute_path(path_array, i, command)
					(ex) touch -> /usr/bin + / + touch -> /usr/bin/touch
				
			Else (Absolute path)
				Command starts with '/'
				(ex) ls /user/bin

				= use original path directly, cause it has already full path.
	
			3. access(path, F_OK) == 0 && access(paht, X_OK) == 0
				Check status of File, which is stored in the path.

				F_OK: The existence of the file. (Sucess: 0, Fail: -1)
				X_OK: Execute permission available. (Sucess: 0, Fail: -1)
		
				If (file exists & executable)
					no more need to use (path_array) -> free!!!
					& return (path).

			searching all path_array[0 - 9]

		4. & finally, free all path_array[0 - 9]
*/
char	*check_cmd_in_path(char **envp, char *command)
{
	char	**path_array;
	char	*path;
	int		i;

	path_array = save_all_env_paths(envp);
	i = 0;
	while (path_array[i] != NULL)
	{
		if (command[0] != '/')
			path = convert_command_absolute_path(path_array, i, command);
		else
			path = ft_strdup(command);
		if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
		{
			free_2d(path_array);
			return (path);
		}
		free(path);
		i++;
	}
	free_2d(path_array);
	return (NULL);
}

/*
	[Propose]
		check the 'cmd' with env and if 'cmd' isn't saved in env then print "errer message".

	[Detail]
		1. ft_split
			Save commands seperately one by one based on the ' ' (one space)

			ex) commands: ls -la
				buf_command[0]: av[2][0]: "ls"
				buf_command[1]: av[2][1]: "-la"
			
			if (!buf_command[0]): If (ft_split) function fails to load -> free.
	
		2. check_cmd_in_path(env, buf_command[0])
			Check whether cmd is saved among of env's some paths.
			
			if (relative command)
				(ex) touch
					= convert it from relative paht to absolute path.
					  touch -> /usr/bin/touch

			else (absolute command)
				(ex) /bin/ls
					= use original absolute path.

			2 - 1. Save the "file's absoulte path" to the variable "paht_buf".

			2 - 2. if(!path_buf)
				If (check_cmd_in_path) function fails to load -> print error message.

		3. No more need to use "buf_command".
		4. If there is no error in command, free and finish function.
*/
void	print_error_cmd(char **envp, char *command)
{
	char	*path_buf;
	char	**buf_command;

	buf_command = ft_split(command, ' ');
	if (!buf_command[0])
	{
		free_2d(buf_command);
		return ;
	}
	path_buf = check_cmd_in_path(envp, buf_command[0]);
	if (!path_buf)
	{
		if (errno == 2)
			ft_printf("%s: command not found\n", buf_command[0]);
		else
			perror("buf_command[0]: ");
	}
	free_2d(buf_command);
	free(path_buf);
	return ;
}
