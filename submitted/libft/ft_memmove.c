/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@42berlin.de>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:31:19 by dlu               #+#    #+#             */
/*   Updated: 2023/04/26 01:55:04 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (src < dst)
		while (len--)
			((t_uc *) dst)[len] = ((t_uc *) src)[len];
	else
		while (++i <= len)
			((t_uc *) dst)[i - 1] = ((t_uc *) src)[i - 1];
	return (dst);
}
