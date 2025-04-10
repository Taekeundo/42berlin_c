/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jason <jason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:57:54 by tkwak             #+#    #+#             */
/*   Updated: 2025/04/09 19:50:23 by jason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# include <stdlib.h>        // [f] malloc, free, exit
# include <unistd.h>        // [f] fork, exec, pipe, dup2, access, sleep, write, read
# include <fcntl.h>         // [f] open, close
# include <errno.h>         // [f] errno, perror
# include <sys/wait.h>      // [f] waitpid
# include <sys/types.h>     // [f] pid_t, size_t
/*
# include <stdio.h>         // [f] pritnf, scanf, fopen, fclose
# include <sys/stat.h>      // [f] chmod()
*/

// main.c
void	free_2d(char **arr);
void	handle_error(const char *msg);
void	print_usage_and_exit(void);
void	ft_creat_pipe(int pipe_fd[2]);
// execute.c
void	free2d_n_exit(char **str);
void	handle_error_dup2(int *kernel_pipe_fd);
void	exec(char *cmd, char **envp);
void	child_exe(char **av, int *kernel_pipe_fd, char **envp);
void	parent_exe(char **av, int *kernel_pipe_fd, char **envp);
// utils.c
void	print_error_cmd(char **envp, char *command);
char	**save_all_env_paths(char **envp);
char	*convert_command_absolute_path(char **path_array, int i, char *command);
char	*check_cmd_in_path(char **envp, char *command);
int		open_file(char *file, int in_or_out);

#endif