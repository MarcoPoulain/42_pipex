/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:27:58 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/19 15:20:39 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	char	*str;
	int		len;

	str = "Hello World\n";
	len = ft_strlen(str);
	write(1, str, len);
	if (write(-42, "boom\n", 5) == -1)
		perror("Write failed");
	if (write(42, "boom\n", 5) == -1)
		perror("Write failed");
	if (write(0, "boom\n", 5) == -1)
		perror("Write failed");
	return (0);
}
*/
