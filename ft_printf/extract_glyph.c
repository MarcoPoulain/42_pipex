/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_glyph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:30:36 by kassassi          #+#    #+#             */
/*   Updated: 2025/05/29 13:28:44 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	extract_glyph(const char *format, int *i)
{
	char	c;

	(*i)++;
	c = format[*i];
	if (
		c == 'c' || c == '%' || c == 'd' || c == 'i'
		|| c == 's' || c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return (c);
	return (0);
}
