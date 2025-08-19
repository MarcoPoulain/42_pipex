/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:44:50 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/19 16:01:06 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int	fd;

	fd = open("grimoire.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open failed");
		return (1);
	}
	if (write(fd, "Boule de feu\n", 13) < 0)
	{
		perror("write failed");
		return (1);
	}
	if (close(fd) < 0)
	{
		perror ("close failed");
		return (1);
	}
	return (0);
}
