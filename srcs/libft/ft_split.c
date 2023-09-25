/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:28:36 by sakamoto          #+#    #+#             */
/*   Updated: 2023/09/25 14:45:21 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include/libft.h"

static size_t	ft_check_split(char str, char c)
{
	if (str == c)
		return (1);
	return (0);
}

static size_t	ft_word_cnt(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (ft_check_split(str[i], c))
		{
			i++;
			continue ;
		}
		count++;
		while (!ft_check_split(str[i], c) && str[i] != '\0')
			i++;
	}
	return (count);
}

static char	**ft_double_array_free(char **array, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static size_t	ft_letter_cnt(const char *str, char c, size_t i)
{
	size_t	letter_cnt;

	letter_cnt = 0;
	while (!ft_check_split(str[i], c) && str[i] != '\0')
	{
		letter_cnt++;
		i++;
	}
	return (letter_cnt);
}

char	**ft_split(const char *str, char c)
{
	size_t	i;
	size_t	words;
	size_t	lcnt;
	size_t	count;
	char	**result;

	i = 0;
	count = 0;
	words = ft_word_cnt(str, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (result == NULL)
		return (NULL);
	while (count < words)
	{
		while (ft_check_split(str[i], c))
			i++;
		lcnt = ft_letter_cnt(str, c, i);
		result[count++] = ft_substr(str, i, lcnt);
		if (result[count - 1] == NULL)
			return (ft_double_array_free(result, count));
		i += lcnt;
	}
	result[count] = NULL;
	return (result);
}
