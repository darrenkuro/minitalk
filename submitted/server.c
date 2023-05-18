/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:44:46 by dlu               #+#    #+#             */
/*   Updated: 2023/05/18 15:20:41 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	signal_handler(int signal)
{
	static int bit;
	static int c;
	
	if (signal == SIGUSR1)
		c |= 1 << bit;
	++bit;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	printf("Server Running. PID is: %d\n", getpid());
	while (1)
		pause();
}
