/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 06:14:33 by dlu               #+#    #+#             */
/*   Updated: 2023/05/07 15:53:41 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Return the length to be printed for a given string. */
int	ft_strlenf(char *s, t_format format)
{
	int	i;

	if (!s || (format.type == 's' && format.dot && format.precision == 0))
		return (0);
	i = -1;
	while (s[++i])
		if (format.type == 's' && format.dot && i >= format.precision)
			return (i);
	return (i);
}

/* Malloc and initialing all values to 0. */
void	*ft_callocn(size_t n)
{
	void	*ret;
	size_t	i;

	ret = malloc(n);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < n)
		((char *) ret)[i++] = 0;
	return (ret);
}

/* Print the padding and return the length of the padding printed. */
int	print_padding(char c, int len)
{
	int	i;

	if (len <= 0)
		return (0);
	i = -1;
	while (++i < len)
		write(1, &c, 1);
	return (len);
}
