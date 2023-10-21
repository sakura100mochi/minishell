/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:46:35 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/21 05:26:13 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_include/get_next_line.h"

void	*ft_calloc_gnl(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (SIZE_MAX / size < count)
		return (NULL);
	ptr = malloc(size * count);
	if (ptr == NULL)
		return (NULL);
	while (i < size * count)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

// s１とs2を、 s２に'\n'または'\0'が来るまで連結させる
char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (s2 == NULL)
		return (NULL);
	len = ft_strlen_g(s1, s2);
	str = ft_calloc(sizeof(char), len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1 != NULL && *s1 != '\0')
		str[i++] = *s1++;
	while (*s2 != '\0' && *s2 != '\n')
		str[i++] = *s2++;
	if (*s2 == '\n')
		str[i] = '\n';
	return (str);
}

size_t	ft_strlen_g(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		i = 0;
	else
	{
		while (s1[i] != '\0')
			i++;
	}
	if (s2 == NULL)
		j = 0;
	else
	{
		while (s2[j] != '\n' && s2[j] != '\0')
			j++;
	}
	if (s2[j] == '\n')
		j++;
	return (i + j);
}

// 文字列 s 中に最初に文字'\n'が現れた位置へのポインターを返す
size_t	ft_strchr_g(const char *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			j++;
		i++;
	}
	return (j);
}
