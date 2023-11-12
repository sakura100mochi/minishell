/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfold_quote_variable_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/12 14:00:37 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/unfold.h"

static char	*input_env_variable(char *str, size_t *start, \
									size_t index, size_t *flag)
{
	char	*result;

	result = ft_substr(str, *start, index - *start);
	if (!*flag)
		*flag = 1;
	else
		*flag = 0;
	*start = index;
	return (result);
}

char	**split_env_variable(char *tmp, size_t len)
{
	size_t	index;
	size_t	start;
	size_t	flag;
	char	**tmp_array;
	char	**result;

	index = 0;
	start = 0;
	flag = 0;
	result = (char **)ft_calloc(sizeof(char *), len + 1);
	tmp_array = result;
	while (index < ft_strlen(tmp) + 1)
	{
		if (check_dollar_charactor(tmp, index))
			*tmp_array++ = input_env_variable(tmp, &start, index, &flag);
		else if (flag && (tmp[index] == '\'' || tmp[index] == ' ' || \
		tmp[index] == '	' || tmp[index] == '\0'))
			*tmp_array++ = input_env_variable(tmp, &start, index, &flag);
		index++;
	}
	*tmp_array++ = ft_substr(tmp, start, index - start);
	*tmp_array = NULL;
	return (result);
}
