/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:02:15 by yhirai            #+#    #+#             */
/*   Updated: 2023/11/16 09:01:46 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"

static size_t	single_quo(char *str, size_t *j)
{
	size_t	i;
	size_t	count;

	i = 1;
	count = 0;
	while (str[i] == '\'' && str[i + 1] != '\0')
	{
		count++;
		i++;
	}
	while (str[i] != '\'' && str[i] != '\0')
		i++;
	while (count != 0)
	{
		if (str[i] != '\'')
			return (NO);
		i++;
		count--;
	}
	*j += i;
	if (str[i] == '\'')
		return (YES);
	return (NO);
}

static size_t	double_quo(char *str, size_t *j)
{
	size_t	i;
	size_t	count;

	i = 1;
	count = 0;
	while (str[i] == '\"' && str[i + 1] != '\0')
	{
		count++;
		i++;
	}
	while (str[i] != '\"' && str[i] != '\0')
		i++;
	while (count != 0)
	{
		if (str[i] != '\"')
			return (NO);
		i++;
		count--;
	}
	*j += i;
	if (str[i] == '\"')
		return (YES);
	return (NO);
}

static size_t	quotation(char *str, size_t *i)
{
	if (str[0] == '\'')
		return (single_quo(str, i));
	else if (str[0] == '\"')
		return (double_quo(str, i));
	return (0);
}

static size_t	count_char(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '|' || str[i] == '<' || str[i] == '>')
		return (1);
	while (str[i] != ' ' && str[i] != '|' && str[i] != '<'
		&& str[i] != '>' && str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (quotation(&str[i], &i) == 0)
				return (NO);
		}
		i++;
	}
	return (i);
}

char	*split_word(char **str)
{
	char	*result;
	char	*tmp;
	size_t	len;
	size_t	i;

	tmp = *str;
	i = 0;
	while ((tmp[i] == ' ' && tmp[i] != '\0')
		|| (tmp[i] == '	' && tmp[i] != '\0'))
		i++;
	len = count_char(&tmp[i]);
	if (len == NO)
		return (NULL);
	result = ft_substr(&tmp[i], 0, len);
	if (result == NULL)
		return (NULL);
	while ((tmp[len + i] == ' ' && tmp[len + i] != '\0')
		|| (tmp[len + i] == '	' && tmp[len + i] != '\0'))
		len++;
	*str += len + i;
	return (result);
}
