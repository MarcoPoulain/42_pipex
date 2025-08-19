/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:26:01 by kassassi          #+#    #+#             */
/*   Updated: 2025/05/27 18:02:05 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

int	cast_char(char c);
int	cast_int(int n);
int	cast_string(char *str);
int	cast_uint(unsigned int n);
int	cast_hex(unsigned int n);
int	cast_uphex(unsigned int n);
int	cast_ptr(void *ptr);

#endif
