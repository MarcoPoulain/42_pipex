/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:36:55 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/19 16:52:53 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int		fd_src;
	int		fd_dest;
	int		bytes;
	char	*buffer;

	buffer = malloc(sizeof(char) * 101);
	if (!buffer)
		return (1);
	fd_src = open("test.txt", O_RDONLY);
	fd_dest = open("dest.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_src < 0 || fd_dest < 0)
	{
		perror("open failed");
		free(buffer);
		return (1);	
	}

	while((bytes = read(fd_src, buffer, 100)) > 0)
		write(fd_dest, buffer, bytes);
	if (bytes < 0)
		{
			perror("read failed");
			free(buffer);
			return (1);
		}
	if (close(fd_src) < 0 || close(fd_dest) < 0)
	{
		perror("close failed");
		free(buffer);
		return (1);
	}
	free(buffer);
	return (0);
}
