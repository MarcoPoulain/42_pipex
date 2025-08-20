/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:29:17 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/20 13:43:52 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd[2];
	int		bytes;
	char	*buffer;

	if (pipe(fd) < 0)
	{
		perror("pipe failed");
		return (1);
	}
	write(fd[1], "TEST UN DEUX UN DEUX", 20);
	buffer = malloc(sizeof(char) * 101);
	if (!buffer)
		return (1);
	bytes = read(fd[0], buffer, 100);
	if (bytes < 0)
	{
		perror("read failed");
		free(buffer);
		return (1);
	}
	buffer[bytes] = '\0';
	printf("%s\n", buffer);
	if (close(fd[1]) < 0 || close(fd[0]) < 0)
	{
		perror("close failed");
		free(buffer);
		return (1);
	}
	free(buffer);
	return (0);
}
