/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:01:31 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/25 17:34:15 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	path_line(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static char	*try_folder(char *folder, char *cmd)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(folder, "/");
	if (!tmp)
		return (NULL);
	full_path = ft_strjoin(tmp, cmd);
	free(tmp);
	if (!full_path)
		return (NULL);
	if (access(full_path, X_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	**folders;
	char	*full_path;
	int		here_path;
	int		i;

	here_path = path_line(envp);
	if (here_path == -1)
		return (NULL);
	folders = ft_split(envp[here_path] + 5, ':');
	if (!folders)
		return (NULL);
	i = 0;
	while (folders[i])
	{
		full_path = try_folder(folders[i], cmd);
		if (full_path)
		{
			free_split(folders);
			return (full_path);
		}
		i++;
	}
	free_split(folders);
	return (NULL);
}
