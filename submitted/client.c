/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:02:23 by dlu               #+#    #+#             */
/*   Updated: 2023/05/19 19:56:24 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"

#define SERVER_BUSY_MSG		"\033[31mServer is busy. Try again later.\n"
#define SERVER_ERROR_MSG	"\033[31mServer can't be reached. Check PID.\n"
#define PID_ERROR_MSG		"\033[31mPID consists of non-digit chars!\n"
#define ARGS_ERROR_MSG		"\033[31mWrong number of "
#define SUCCESS_MSG			"\033[34mMessage sent.\n"
#define DELAY_MILLISEC		100
#define TIMEOUT_LIMIT		10

static int	g_received = 0;

static void	signal_handler(int signal)
{
	usleep(DELAY_MILLISEC);
	if (signal == SIGUSR1)
		g_received = 1;
	if (signal == SIGUSR2)
	{
		write(1, SERVER_BUSY_MSG, 38);
		exit(1);
	}
}

static void	send_char(int pid, char c)
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
			usleep(DELAY_MILLISEC);
	}
	g_received = 0;
}

static int	pid_isvalid(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (0);
	return (1);
}

static int	establish_connection(int pid)
{
	int	i;

	i = -1;
	kill(pid, SIGUSR1);
	while (++i < TIMEOUT_LIMIT && !g_received)
		usleep(DELAY_MILLISEC);
	if (g_received)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3 && ft_printf("%s", ARGS_ERROR_MSG))
		return (1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	if (!pid_isvalid(av[1]) && ft_printf("%s", PID_ERROR_MSG))
		return (1);
	pid = (int) ft_atoi(av[1]);
	if (!establish_connection(pid) && ft_printf("%s", SERVER_ERROR_MSG))
		return (1);
	i = -1;
	while (av[2][++i])
		send_char(pid, av[2][i]);
	send_char(pid, '\n');
	send_char(pid, '\0');
	ft_printf("%s", SUCCESS_MSG);
	return (0);
}
