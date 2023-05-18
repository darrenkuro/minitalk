/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:02:23 by dlu               #+#    #+#             */
/*   Updated: 2023/05/18 15:38:43 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	send_char(int pid, char c)
{
	int bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		//usleep(0);
		++bit;
	}
}
int	main(int ac, char **av)
{
	int i;

	if (ac != 3)
		return (1);
	pid_t serverPID = atoi(av[1]);
	i = -1;
	while (av[2][++i])
		send_char(serverPID, av[2][i]);
	send_char(serverPID, '\n');
	return (0);
}
