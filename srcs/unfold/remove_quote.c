/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:55:26 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/17 23:31:03 by csakamot         ###   ########.fr       */
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
	*end -= 1;
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
	while (str[index++] != '\0')
	{
		result[index - 2] = str[index];
	}
	*end -= 1;
	free(str);
	result = unfold_quote_variable(result, env, start, end);
	return (result);
}

static void	judge_quote_nbr(size_t *single, size_t *twofold, \
										size_t *index, int flag)
{
	if (flag == 1)
		*single = *single + 1;
	else if (flag == 2)
		*twofold = *twofold + 1;
	*index = *index + 1;
	return ;
}

static	int	judge_str_doller(char *str, size_t index, \
							size_t single, size_t twofold)
{
	if (!(single % 2) && !(twofold % 2) && str[index] == '$' \
										&& str[index + 1] != '\0')
		return (YES);
	return (NO);
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
		if (judge_str_doller(str, index, single, twofold) && \
				(ft_isalnum(str[index + 1]) || str[index + 1] == '?'))
			str = unfold_str(str, env, &index);
		else if (!(single % 2) && !(twofold % 2) && str[index] == '\'')
			judge_quote_nbr(&single, &twofold, &index, 1);
		else if (!(single % 2) && !(twofold % 2) && str[index] == '"')
			judge_quote_nbr(&single, &twofold, &index, 2);
		else if (single % 2 && !(twofold % 2) && \
				str[index] == '\'' && single++)
			str = remove_single_quote(str, &index);
		else if (twofold % 2 && !(single % 2) && str[index] == '"' && twofold++)
			str = remove_twofold_quote(str, env, &index);
		else
			index++;
	}
	return (str);
}
