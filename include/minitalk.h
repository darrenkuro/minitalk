/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 07:41:44 by dlu               #+#    #+#             */
/*   Updated: 2023/05/22 10:26:48 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft.h"

# define SERVER_START_MSG	"\033[32mServer is now running. PID: %d\033[0m\n"
# define SERVER_BUSY_MSG	"\033[31mServer is busy. Try again later.\n"
# define SERVER_ERROR_MSG	"\033[31mServer can't be reached. Check PID.\n"
# define PID_ERROR_MSG		"\033[31mPID consists of non-digit chars!\n"
# define ARGS_ERROR_MSG		"\033[31mWrong number of arguments.\n"
# define SUCCESS_MSG		"\033[32mMessage sent.\n"
# define DELAY_MICROSEC		150
# define TIMEOUT_LIMIT		10

# define TRUE		1
# define FALSE		0
# define FAILURE	1
# define SUCCESS	0

#endif
