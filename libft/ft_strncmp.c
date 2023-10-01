/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:51:07 by yayoi             #+#    #+#             */
/*   Updated: 2023/09/16 18:15:05 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*c1;
	const unsigned char	*c2;

	i = 0;
	c1 = (const unsigned char *)s1;
	c2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && c1[i] != '\0' && c2[i] != '\0')
	{
		if (c1[i] != c2[i])
			break ;
		i++;
	}
	return (c1[i] - c2[i]);
}
