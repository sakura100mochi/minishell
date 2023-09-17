/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:39:35 by sakamoto          #+#    #+#             */
/*   Updated: 2023/08/09 12:20:06 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*result;
	unsigned char	*origin;

	if (size == 0)
		return (dest);
	if ((!dest && !src) && size > 0)
		return (NULL);
	result = (unsigned char *) dest;
	origin = (unsigned char *) src;
	if (dest <= src)
	{
		while (size--)
			*result++ = *origin++;
	}
	else
	{
		result += size;
		origin += size;
		while (size--)
			*--result = *--origin;
	}
	return (dest);
}
