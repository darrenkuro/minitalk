/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:44:46 by dlu               #+#    #+#             */
/*   Updated: 2023/05/22 09:55:27 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	write_char(int *c, int *bit, int *client_pid)
{
	if (*c)
		write(1, c, 1);
	*bit = 0;
	if (!*c)
		*client_pid = 0;
	*c = 0;
}

static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	client_pid = 0;
	static int	bit = 0;
	static int	c;

	(void) context;
	if (client_pid == 0)
	{
		client_pid = info->si_pid;
		kill(info->si_pid, SIGUSR1);
		return ;
	}
	if (client_pid == info->si_pid)
	{
		if (signum == SIGUSR1)
			c |= 1 << bit;
		if (++bit == 8)
			write_char(&c, &bit, &client_pid);
		kill(info->si_pid, SIGUSR1);
	}
	else
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf(SERVER_START_MSG, getpid());
	while (TRUE)
		pause();
	return (SUCCESS);
}
