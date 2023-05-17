/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:02:23 by dlu               #+#    #+#             */
/*   Updated: 2023/05/17 21:10:33 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return (1);
	pid_t serverPID = atoi(av[1]);
	kill(serverPID, (SIGUSR1 << 4) + av[ac][0]);
	return (0);
}
