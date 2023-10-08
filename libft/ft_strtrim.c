/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:03:00 by csakamot          #+#    #+#             */
/*   Updated: 2023/08/09 12:21:23 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include/libft.h"

static int	ft_check_trim(const char s1, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_setlen(const char *s1, const char *set, size_t len_s1)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	while (s1[i] != '\0')
	{
		if (ft_check_trim(s1[i], set))
			len++;
		else
			break ;
		i++;
	}
	if (len == len_s1)
		return (len);
	i = len_s1;
	while (i > 0)
	{
		if (ft_check_trim(s1[i - 1], set))
			len++;
		else
			break ;
		i--;
	}
	return (len);
}

static char	*fti(char *result, const char *s1, const char *set, size_t len)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (ft_check_trim(s1[i], set) && s1[i] != '\0')
		i++;
	while (j < len)
	{
		result[j] = s1[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_setlen(s1, set, len_s1);
	result = (char *)malloc(sizeof(char) * (len_s1 - len_s2 + 1));
	if (result == NULL)
		return (NULL);
	fti(result, s1, set, len_s1 - len_s2);
	return (result);
}
