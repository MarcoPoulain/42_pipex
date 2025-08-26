/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:00:51 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/26 17:07:22 by kassassi         ###   ########.fr       */
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
		exit(1);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(infile);
	arr_cmd = parse_command(argv[2]);
	path = find_path(arr_cmd[0], envp);
	if (!path)
	{
		ft_printf("%s: command not found\n", arr_cmd[0]);
		free_split(arr_cmd);
		exit(127);
	}
	execve(path, arr_cmd, envp);
	perror("execve");
	free(path);
	free_split(arr_cmd);
	exit(126);
}

static void	child_two(int *fd, char **argv, char **envp)
{
	int		outfile;
	char	*path;
	char	**arr_cmd;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		exit(1);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	close(outfile);
	arr_cmd = parse_command(argv[3]);
	path = find_path(arr_cmd[0], envp);
	if (!path)
	{
		ft_printf("%s: command not found\n", arr_cmd[0]);
		free_split(arr_cmd);
		exit(127);
	}
	execve(path, arr_cmd, envp);
	perror("execve");
	free(path);
	free_split(arr_cmd);
	exit(126);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (1);
	if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 == 0)
		child_one(fd, argv, envp);
	pid2 = fork();
	if (pid2 == 0)
		child_two(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
