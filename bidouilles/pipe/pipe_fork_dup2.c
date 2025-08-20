/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_fork_dup2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:05:29 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/20 16:49:22 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int	main(void)
{
	int		pipe[2];
	pid_t	pid;

	if (pipe(pipe) < 0)
	{
		perror("pipe failed");
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		close(pipe[0]);
		close(pipe[1]);
		return (1);
	}
	if (pid == 0)
	{
		close(pipe[1]);
		if (dup2(pipe[0], 0) < 0)
		{
			perror("dup failed");
			close(pipe[0]);
			return (1);
		}
		close(pipe[0]);
		if (execlp("wc", "wc", NULL) < 0)
		{
			perror("exec wc failed");
			return (1);
		}
		return (0);
	}
	close(pipe[0]);
	if (dup2(pipe[1], 1) < 0)
	{
		perror("dup failed");
		close(pipe[1]);
		return (1);
	}
	close(pipe[1]);
	if (execlp("ls", "ls", NULL) < 0)
	{
		perror("exec ls failed");
		return (1);
	}
	if (waitpid(pid, NULL, 0) < 0)
	{
		perror("waitpid failed");
		return (1);
	}
	return (0);
}
