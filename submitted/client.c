/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:02:23 by dlu               #+#    #+#             */
/*   Updated: 2023/05/22 10:32:46 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile int	g_received = FALSE;

static void	signal_handler(int signal)
{
	usleep(DELAY_MICROSEC);
	if (signal == SIGUSR2)
	{
		write(1, SERVER_BUSY_MSG, 38);
		exit(FAILURE);
	}
	else
		g_received = TRUE;
}

static void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_received = FALSE;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		++bit;
		while (!g_received)
			usleep(DELAY_MICROSEC);
	}
	g_received = FALSE;
}

static int	pid_isvalid(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (FALSE);
	return (TRUE);
}

static int	establish_connection(int pid)
{
	int	i;

	i = -1;
	kill(pid, SIGUSR1);
	while (++i < TIMEOUT_LIMIT && !g_received)
		usleep(DELAY_MICROSEC);
	if (g_received)
		return (TRUE);
	return (FALSE);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3 && ft_printf("%s", ARGS_ERROR_MSG))
		return (FAILURE);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	if (!pid_isvalid(av[1]) && ft_printf("%s", PID_ERROR_MSG))
		return (FAILURE);
	pid = (int) ft_atoi(av[1]);
	if (!establish_connection(pid) && ft_printf("%s", SERVER_ERROR_MSG))
		return (FAILURE);
	i = -1;
	while (av[2][++i])
		send_char(pid, av[2][i]);
	send_char(pid, '\n');
	send_char(pid, '\0');
	ft_printf("%s", SUCCESS_MSG);
	return (SUCCESS);
}
