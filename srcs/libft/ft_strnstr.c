/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:54:58 by yayoi             #+#    #+#             */
/*   Updated: 2023/08/09 12:21:14 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	nbr;

	i = 0;
	nbr = 0;
	if (*needle == '\0')
		return ((char *)&haystack[i]);
	while (nbr < len && haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i] == needle[j] && needle[j] != '\0' && nbr < len)
		{
			nbr++;
			i++;
			j++;
		}
		i -= j;
		nbr -= j;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		nbr++;
		i++;
	}
	return (NULL);
}
