/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:00:51 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/25 17:26:28 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*path;

	if (argc != 2)
	{
		ft_printf("NOPE\n");
		return (1);
	}
	path = find_path(argv[1], envp);
	if (!path)
		ft_printf("%s: command not found\n", argv[1]);
	else
	{
		ft_printf("Found: %s\n", path);
		free(path);
	}
	return (0);
}
