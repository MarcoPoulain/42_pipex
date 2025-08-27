/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:00:51 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/27 16:40:37 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "pipex.h"

static void	child_one(int *fd, char **argv, char **envp)
{
	int		infile;
	char	*path;
	char	**arr_cmd;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		print_error(argv[1]);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(infile);
	arr_cmd = parse_command(argv[2]);
	if (!arr_cmd || !arr_cmd[0])
		cmd_not_found(argv[2], arr_cmd);
	path = find_path(arr_cmd[0], envp);
	if (!path)
		cmd_not_found(arr_cmd[0], arr_cmd);
	execve(path, arr_cmd, envp);
	execve_failed(path, arr_cmd);
}

static void	child_two(int *fd, char **argv, char **envp)
{
	int		outfile;
	char	*path;
	char	**arr_cmd;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		print_error(argv[4]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	close(outfile);
	arr_cmd = parse_command(argv[3]);
	if (!arr_cmd || !arr_cmd[0])
		cmd_not_found(argv[3], arr_cmd);
	path = find_path(arr_cmd[0], envp);
	if (!path)
		cmd_not_found(arr_cmd[0], arr_cmd);
	execve(path, arr_cmd, envp);
	execve_failed(path, arr_cmd);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		wrong_argc_number(argv[0]);
	if (pipe(fd) == -1)
		print_error("pipe");
	pid1 = fork();
	if (pid1 == 0)
		child_one(fd, argv, envp);
	pid2 = fork();
	if (pid2 == 0)
		child_two(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
