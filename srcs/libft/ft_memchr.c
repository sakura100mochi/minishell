/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:38:38 by sakamoto          #+#    #+#             */
/*   Updated: 2023/09/13 03:16:42 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include/libft.h"

void	*ft_memchr(const void *buf, int c, size_t n)
{
	size_t				i;
	const unsigned char	*dest;
	unsigned char		cbuf;
	void				*result;

	i = 0;
	dest = (const unsigned char *) buf;
	cbuf = (unsigned char)c;
	while (i < n)
	{
		if (dest[i] == cbuf)
		{
			result = (void *)&dest[i];
			return (result);
		}
		i++;
	}
	return (NULL);
}
