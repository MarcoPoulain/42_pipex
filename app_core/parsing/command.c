/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:36:03 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/26 15:39:08 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_command(char *cmd)
{
	char	**arr_cmd;

	arr_cmd = ft_split(cmd, ' ');
	if (!arr_cmd)
		return (NULL);
	return (arr_cmd);
}
