/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:02:23 by dlu               #+#    #+#             */
/*   Updated: 2023/05/19 17:22:39 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"

static int received = 0;

void	signal_handler(int signal)
{
	usleep(10);
	if (signal == SIGUSR1)
	{
		received = 1;
		//write(1, "r\n", 2);
	}
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		received = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		++bit;
		while (!received)
			usleep(50);
	}
	received = 0;
}

int	main(int ac, char **av)
{
	int	i;

	if (ac != 3)
		return (1);
	i = -1;
	//ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	while (av[2][++i])
		send_char(ft_atoi(av[1]), av[2][i]);
	send_char(ft_atoi(av[1]), '\n');
	send_char(ft_atoi(av[1]), '\0');
	return (0);
}
