/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:48:31 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/27 16:02:29 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	print_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	cmd_not_found(char *cmd, char **arr_cmd)
{
	ft_printf("%s: command not found\n", cmd);
	if (arr_cmd)
		free_split(arr_cmd);
	exit(127);
}

void	execve_failed(char *path, char **arr_cmd)
{
	perror(path);
	free(path);
	free_split(arr_cmd);
	exit(126);
}
