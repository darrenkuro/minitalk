/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:44:46 by dlu               #+#    #+#             */
/*   Updated: 2023/05/19 17:27:31 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

#define START_MSG "Server is now running. PID: %d\n"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	clientPID = 0;
	static int	bit = 0;
	static int	c;

	(void) context;
	if (clientPID == 0)
		clientPID = info->si_pid;
	if (clientPID == info->si_pid)
	{
		if (signum == SIGUSR1)
			c |= 1 << bit;
		++bit;
		kill(clientPID, SIGUSR1);
		if (bit == 8)
		{
			if (c == 0)
				clientPID = 0;
			if (c)
				write(1, &c, 1);
			bit = 0;
			c = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf(START_MSG, getpid());
	while (1)
		pause();
}
