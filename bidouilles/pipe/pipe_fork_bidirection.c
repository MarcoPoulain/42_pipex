/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_fork_bidirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:21:40 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/20 15:49:27 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(void)
{
	int		pipe1[2];
	int		pipe2[2];
	pid_t	pid;
	char	buffer[1024];
	char	*msg_dad;
	char	*msg_son;
	int		ret;

	msg_dad = "Where are you BOI?\n";
	msg_son = "I'm here !\n";
	if (pipe(pipe1) < 0 || pipe(pipe2) < 0)
	{
		perror("pipe failed");
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		close(pipe1[0]);
		close(pipe1[1]);
		close(pipe2[0]);
		close(pipe2[1]);
		return (1);
	}
	if (pid == 0)
	{
		close(pipe1[1]);
		close(pipe2[0]);
		ret = read(pipe1[0], buffer, 1023);
		if (ret < 0)
		{
			perror("read failed");
			close(pipe1[0]);
			return (1);
		}
		buffer[ret] = '\0';
		printf("Fils a lu : %s", buffer);
		close(pipe1[0]);
		ret = write(pipe2[1], msg_son, 11);
		if (ret < 0)
		{
			perror("write failed");
			close(pipe2[1]);
			return (1);
		}
		close(pipe2[1]);
		return (0);
	}
	close(pipe1[0]);
	close(pipe2[1]);
	ret = write(pipe1[1], msg_dad, 19);
	if (ret < 0)
	{
		perror("write failed");
		close(pipe1[1]);
		return (1);
	}
	close(pipe1[1]);
	ret = read(pipe2[0], buffer, 1023);
	if (ret < 0)
	{
		perror("read failed");
		close(pipe2[0]);
		return (1);
	}
	buffer[ret] = '\0';
	printf("Pere a lu : %s", buffer);
	close(pipe2[0]);
	if (waitpid(pid, NULL, 0) < 0)
	{
		perror("waitpid failed");
		return (1);
	}
	return (0);
}
