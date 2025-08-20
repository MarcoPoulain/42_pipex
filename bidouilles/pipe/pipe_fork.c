/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:49:57 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/20 15:07:30 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int	main(void)
{
	int		fd[2];
	pid_t	pid;
	char	buffer[1024];
	char	*msg;
	int		ret;

	msg = "Coucou du père\n";
	if (pipe(fd) < 0)
	{
		perror("pipe failed");
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		close(fd[0]);
		close(fd[1]);
		return (1);
	}
	if (pid == 0)
	{
		close(fd[1]);
		ret = read(fd[0], buffer, 1023);
		if (ret < 0)
		{
			perror("read failed");
			close(fd[0]);
			return (1);
		}
		buffer[ret] = '\0';
		printf("Fils a lu : %s", buffer);
		close(fd[0]);
		return (0);
	}
	close(fd[0]);
	ret = write(fd[1], msg, 16);
	if (ret < 0)
	{
		perror("write failed");
		close(fd[1]);
		return (1);
	}
	close(fd[1]);
	if (waitpid(pid, NULL, 0) < 0)
	{
		perror("waitpid failed");
		return (1);
	}
	return (0);
}

