/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfold_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:24:31 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/05 12:00:11 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/unfold.h"

static size_t	strlen_mini(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

static char	*in_strjoin_mini(char *result, const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			result[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[j] != '\0')
		{
			result[i] = s2[j];
			i++;
			j++;
		}
	}
	result[i] = '\0';
	return (result);
}

char	*strjoin_mini(const char *s1, const char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL)
		s1_len = 0;
	else
		s1_len = strlen_mini(s1);
	if (s2 == NULL)
		s2_len = 0;
	else
		s2_len = strlen_mini(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
	{
		free((void *)s1);
		return (NULL);
	}
	result = in_strjoin_mini(result, s1, s2);
	if (s1 != NULL)
		free((void *)s1);
	return (result);
}
