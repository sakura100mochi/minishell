/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:08:07 by sakamoto          #+#    #+#             */
/*   Updated: 2023/08/09 12:20:53 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include/libft.h"

char	*ft_strchr(const char *str, int c)
{
	int					i;
	int					flag;
	unsigned char		cbuf;
	const unsigned char	*result;

	i = 0;
	flag = 0;
	result = (const unsigned char *)str;
	cbuf = (unsigned char)c;
	if (cbuf == '\0')
		flag++;
	while (result[i] != '\0')
	{
		if (result[i] == cbuf)
			return ((char *)&result[i]);
		i++;
	}
	if (flag)
		return ((char *)&result[i]);
	return (NULL);
}
