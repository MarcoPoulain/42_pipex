/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:14:51 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/20 17:15:17 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(void)
{
    pid_t pid1;
    pid_t pid2;

    pid1 = fork();
    pid2 = fork();

    printf("Je suis %d, mon père est %d (pid1=%d, pid2=%d)\n",
        getpid(), getppid(), pid1, pid2);
    return (0);
}
