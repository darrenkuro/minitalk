/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:02:23 by dlu               #+#    #+#             */
/*   Updated: 2023/05/19 18:00:29 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"

#define SERVER_ERROR "Server is busy. Try again later.\n"

static int	g_received = 0;

void	signal_handler(int signal)
{
	usleep(50);
	if (signal == SIGUSR1)
		g_received = 1;
	if (signal == SIGUSR2)
	{
		write(1, SERVER_ERROR, 33);
		exit(1);
	}
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_received = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		++bit;
		while (!g_received)
			usleep(10);
	}
	g_received = 0;
}

int	main(int ac, char **av)
{
	int	i;

	if (ac != 3)
		return (1);
	i = -1;
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (av[2][++i])
		send_char(ft_atoi(av[1]), av[2][i]);
	send_char(ft_atoi(av[1]), '\n');
	send_char(ft_atoi(av[1]), '\0');
	return (0);
}
