/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:24:20 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/19 15:44:38 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	int		bytes;
	char	*buffer;

	buffer = malloc(sizeof(char) * 101);
	if (!buffer)
		return (1);
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Open failed");
		free(buffer);
		return (1);
	}
	bytes = read(fd, buffer, 100);
	if (bytes < 0)
		perror("bytes failed");
	else
		buffer[bytes] = '\0';
	write(1, buffer, bytes);
	if (close(fd) < 0)
		perror("close failed");
	free(buffer);
	return (0);
}
