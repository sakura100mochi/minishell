/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:24:04 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/18 12:10:51 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	length;
	char	*result;

	if (!s)
		return (NULL);
	i = 0;
	length = ft_strlen(s);
	if (len < length)
		result = (char *)ft_calloc(len + 1, sizeof(char));
	else
		result = (char *)ft_calloc(length + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	if (start < length)
	{
		while (i < len && s[start] != '\0')
		{
			result[i] = s[start];
			start++;
			i++;
		}
	}
	result[i] = '\0';
	return (result);
}
