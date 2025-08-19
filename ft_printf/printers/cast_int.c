/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:47:20 by kassassi          #+#    #+#             */
/*   Updated: 2025/05/27 12:53:20 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printers.h"
#include <stdlib.h>

int	cast_int(int n)
{
	char	*itoa;
	int		count;

	itoa = ft_itoa(n);
	ft_putstr(itoa);
	count = ft_strlen(itoa);
	free(itoa);
	return (count);
}
