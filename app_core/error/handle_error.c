/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:48:31 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/29 14:29:49 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <unistd.h>

void	print_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	wrong_argc_number(char *str)
{
	write(2, "need: ", 6);
	write(2, str, ft_strlen(str));
	write(2, " file1 cmd1 cmd2 file2\n", 24);
	exit(EXIT_FAILURE);
}

void	cmd_not_found(char *cmd, char **arr_cmd)
{
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 21);
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
