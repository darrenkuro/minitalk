/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:44:46 by dlu               #+#    #+#             */
/*   Updated: 2023/05/19 19:55:53 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

#define START_MSG "\033[34mServer is now running. PID: %d\033[0m\n"

static int	g_client_pid = 0;

static void	write_char(int *c, int *bit)
{
	if (*c)
		write(1, c, 1);
	*bit = 0;
	if (!*c)
		g_client_pid = 0;
	*c = 0;
}

static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	c;

	(void) context;
	if (g_client_pid == 0)
	{
		g_client_pid = info->si_pid;
		kill(info->si_pid, SIGUSR1);
		return ;
	}
	if (g_client_pid == info->si_pid)
	{
		if (signum == SIGUSR1)
			c |= 1 << bit;
		++bit;
		if (bit == 8)
			write_char(&c, &bit);
		kill(info->si_pid, SIGUSR1);
	}
	else
		kill(info->si_pid, SIGUSR2);
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
	return (0);
}
