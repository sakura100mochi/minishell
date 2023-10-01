/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:14:22 by sakamoto          #+#    #+#             */
/*   Updated: 2023/08/09 12:19:57 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	size_t				i;
	const unsigned char	*c1;
	const unsigned char	*c2;

	i = 0;
	c1 = (const unsigned char *)s1;
	c2 = (const unsigned char *)s2;
	if (size == 0)
		return (0);
	while (i < size - 1)
	{
		if (c1[i] != c2[i])
			break ;
		i++;
	}
	return (c1[i] - c2[i]);
}
