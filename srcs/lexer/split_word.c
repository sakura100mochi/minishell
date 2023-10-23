/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:02:15 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/23 17:43:58 by yhirai           ###   ########.fr       */
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
			return (i + 1);
	}
	else if (str[0] == '\"')
	{
		while (str[i] != '\"' && str[i] != '\0')
			i++;
		if (str[i] == '\"')
			return (i + 1);
	}
	return (0);
}

static size_t	count_char(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '|' || str[i] == '<' || str[i] == '>')
		return (1);
	if (str[i] == '\'' || str[i] == '\"')
		return (quotation(str));
	while (str[i] != ' ' && str[i] != '|' && str[i] != '<'
		&& str[i] != '>' && str[i] != '\0' && str[i] != '\''
		&& str[i] != '\"')
		i++;
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
	if (len == 0)
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
