/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:14:37 by kassassi          #+#    #+#             */
/*   Updated: 2025/05/29 14:44:20 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printers.h"
#include "../ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	x;
	int	y;
	int	z;
	int	*ptr;

	x = 42;
	ptr = &x;
	printf("===========================\n");
	printf("Test comparatif printf et ft_printf\n");
	printf("===========================\n\n");
	printf("check des char, pour 'b' et 'w':\n\n");
	printf("Fonction standard: %c et %c\n", 'b', 'w');
	ft_printf("Fonction 42: %c et %c\n\n", 'b', 'w');
	printf("===========================\n\n");
	ft_printf("check des str *, pour \"abcdef\":\n\n");
	printf("Fonction standard: %s\n", "abcdef");
	ft_printf("Fonction 42: %s\n\n", "abcdef");
	printf("===========================\n\n");
	printf("check des int avec 'd', 'i' et 'u'\n");
	printf("d: -42, i: 42, u: 304235645:\n\n");
	printf("Fonction Standard: %d, %i, %u\n", -42, 42, 304235645);
	ft_printf("Fonction 42: %d, %i, %u\n\n", -42, 42, 304235645);
	printf("===========================\n\n");
	printf("Check des hexadecimaux pour '666':\n\n");
	printf("Fonction standard: %x, %X\n", 666, 666);
	ft_printf("Fonction 42: %x, %X\n\n", 666, 666);
	printf("===========================\n\n");
	printf("Check des pointeurs:\n\n");
	printf("Fonction standard: %p\n", ptr);
	ft_printf("Fonction 42: %p\n\n", ptr);
	printf("===========================\n\n");
	printf("Check multi arguments:\n\n");
	printf("Fonction standard: %%, %c, %X, %p\n", 'w', 1789, ptr);
	ft_printf("Fonction 42: %%, %c, %X, %p\n\n", 'w', 1789, ptr);
	printf("===========================\n\n");
	printf("Check de l'int que retourne printf pour 'abcdef'\n");
	y = printf("abcdef\n");
	z = ft_printf("abcdef\n");
	ft_printf("Standard: %d, Fonction 42: %d\n\n", y, z);
	printf("===========================\n\n");
	printf("Check des (char *)NULL\n\n");
	printf("Fonction standard: %s\n", (char *)NULL);
	ft_printf("Fonction 42: %s\n\n", (char *)NULL);
	printf("===========================\n\n");
	printf("Check de printf(NULL)\n\n");
	y = printf(NULL);
	z = ft_printf(NULL);
	printf("Fonction standard: %d\n", y);
	ft_printf("Fonction 42: %d\n\n", z);
	printf("===========================\n\n");
	printf("Check des pointeurs NULL\n\n");
	printf("Fonction standard: %p\n", (void *)NULL);
	ft_printf("Fonction 42: %p\n\n", (void *)NULL);
	printf("===========================\n\n");
	//ft_printf("ddsfdsfd %");
	return (0);
}
