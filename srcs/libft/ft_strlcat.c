/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:50:50 by yayoi             #+#    #+#             */
/*   Updated: 2023/08/09 12:17:52 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(src);
	if (dest == NULL && size == 0)
		return (size + s_len);
	d_len = ft_strlen(dest);
	if (size < d_len + 1)
		return (size + s_len);
	while (i < size - d_len - 1 && src[i] != '\0')
	{
		if (src[i] == '\0')
			break ;
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}
