/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:23:16 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/27 15:41:45 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	print_error(char *msg);
void	cmd_not_found(char *cmd, char **arr_cmd);
void	execve_failed(char *path, char **arr_cmd);

#endif
