/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read_stdin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:38:27 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/20 13:02:22 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd_dest;
	int		bytes;
	char	*buffer;

	buffer = malloc(sizeof(char) * 101);
	if (!buffer)
		return (1);
	fd_dest = open("dest_stdin.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_dest < 0)
	{
		perror("open failed");
		free(buffer);
		return (1);
	}
	bytes = read(0, buffer, 100);
	while (bytes > 0)
	{
		write(fd_dest, buffer, bytes);
		bytes = read(0, buffer, 100);
	}
	if (bytes < 0)
	{
		perror("read failed");
		free(buffer);
		return (1);
	}
	if (close(fd_dest) < 0)
	{
		perror("close failed");
		free(buffer);
		return (1);
	}
	free(buffer);
	return (0);
}
