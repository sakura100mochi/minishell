/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:55:26 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/03 15:11:48 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/unfold.h"

static char	*remove_single_quote(char *str, int end)
{
	size_t	index;
	char	*result;

	index = 0;
	result = (char *)ft_calloc(sizeof(char), ft_strlen(str) - 1);
	while (str[end - index] != '\0')
	{
		if (str[end - index] != '\'')
			result[end - 2 - index] = str[end - index];
		index++;
	}
	while (str[end++])
		result[end - 2] = str[end];
	result[end - 2] == '\0';
	free(str);
	return (result);
}

static char	*remove_twofold_quote(char *str, int end)
{
	size_t	index;
	size_t	start;
	char	*result;

	index = 0;
	start = 0;
	result = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	while (str[end - index - 1] != '\0')
	{
		if (str[end - index - 1] != '"')
		{
			result[end - 2 - index] = str[end - index - 1];
			start = end - 2 - index;
		}
		index++;
	}
	index = end;
	while (str[index++])
		result[index - 2] = str[index];
	result[index - 2] = '\0';
	free(str);
	result = unfold_quote_variable(result, start, end - 1);
	return (result);
}

static int	check_quote_in_str(char *str)
{
	size_t	index;
	size_t	single;
	size_t	twofold;

	index = 0;
	single = 0;
	twofold = 0;
	while (str[index] != '\0')
	{
		if (!(single % 2) && !(twofold % 2) && str[index] == '$')
			unfold_str(str, index);
		if (!(single % 2) && !(twofold % 2) && str[index] == '\'')
			single++;
		else if (!(single % 2) && !(twofold % 2) && str[index] == '"')
			twofold++;
		else if (single && str[index] == '\'')
			str = remove_single_quote(str, index);
		else if (twofold && str[index] == '"')
			str = remove_twofold_quote(str, index);
		index++;
	}
	return (0);
}

int	remove_quote_in_command(t_parser *parser, char *str)
{
	check_quote_in_str(parser->cmd);
	if (str)
		check_quote_in_str(str);
	return (0);
}
