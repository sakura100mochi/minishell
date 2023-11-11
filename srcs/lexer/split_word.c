/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:02:15 by yhirai            #+#    #+#             */
/*   Updated: 2023/11/10 13:37:44 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"

static size_t	quotation(char *str)
{
	size_t	i;

	i = 1;
	if (str[0] == '\'')
	{
		while (str[i] != '\'' && str[i] != '\0')
			i++;
		if (str[i] == '\'')
			return (i);
	}
	else if (str[0] == '\"')
	{
		while (str[i] != '\"' && str[i] != '\0')
			i++;
		if (str[i] == '\"')
			return (i);
	}
	return (0);
}

static size_t	count_char(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '|' || str[i] == '<' || str[i] == '>')
		return (1);
	if (str[i] == '-')
	{
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '	')
			i++;
		return (i);
	}
	while (str[i] != '|' && str[i] != '<'
		&& str[i] != '>' && str[i] != '-' && str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
			i += quotation(&str[i]);
		i++;
	}
	return (i);
}

char	*split_word(char **str)
{
	char	*result;
	char	*tmp;
	size_t	len;

	tmp = *str;
	len = count_char(tmp);
	if (len == 0)
		return (NULL);
	result = ft_substr(tmp, 0, len);
	if (result == NULL)
		return (NULL);
	*str += len;
	return (result);
}
