/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:55:26 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/22 13:24:40 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/unfold.h"
#include "../../includes/error.h"

static char	*remove_single_quote(char *str, size_t *end)
{
	size_t	index;
	size_t	start;
	char	*result;

	index = 0;
	start = 0;
	result = (char *)ft_calloc(sizeof(char), ft_strlen(str) - 1);
	while (index < *end)
	{
		if (str[*end - index - 1] != '\'' && !start)
			result[*end - 2 - index] = str[*end - index - 1];
		else if (start)
			result[*end - 1 - index] = str[*end - index - 1];
		else
			start = *end - 1 - index;
		index++;
	}
	while (str[index++])
		result[index - 2] = str[index];
	*end -= 2;
	free(str);
	return (result);
}

static char	*remove_twofold_quote(char *str, t_env *env, size_t *end)
{
	size_t	index;
	size_t	start;
	char	*result;

	index = 0;
	start = 0;
	result = (char *)ft_calloc(sizeof(char), ft_strlen(str) - 1);
	while (index < *end)
	{
		if (str[*end - index - 1] != '"' && !start)
			result[*end - 2 - index] = str[*end - index - 1];
		else if (start)
			result[*end - 1 - index] = str[*end - index - 1];
		else
			start = *end - 1 - index;
		index++;
	}
	while (str[index++])
		result[index - 2] = str[index];
	free(str);
	*end -= 2;
	result = unfold_quote_variable(result, env, start, end);
	return (result);
}

char	*check_quote_in_str(char *str, t_env *env)
{
	size_t	index;
	size_t	single;
	size_t	twofold;

	index = 0;
	single = 0;
	twofold = 0;
	while (str[index] != '\0')
	{
		if (!(single % 2) && !(twofold % 2) && str[index] == '$' && \
				str[index + 1] != '\0' && (ft_isalnum(str[index + 1]) || \
				str[index + 1] == '?'))
			str = unfold_str(str, env, &index);
		else if (!(single % 2) && !(twofold % 2) && str[index] == '\'')
			single++;
		else if (!(single % 2) && !(twofold % 2) && str[index] == '"')
			twofold++;
		else if (single % 2 && str[index] == '\'' && single++)
			str = remove_single_quote(str, &index);
		else if (twofold % 2 && str[index] == '"' && twofold++)
			str = remove_twofold_quote(str, env, &index);
		index++;
	}
	return (str);
}
