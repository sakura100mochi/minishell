/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_split_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/28 14:56:56 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"
#include "../../includes/unfold.h"
#include "../../includes/error.h"

static char	*file_input_array(char *str, size_t *index)
{
	char	*result;
	size_t	start;
	size_t	single;
	size_t	twofold;

	result = NULL;
	start = *index;
	single = 0;
	twofold = 0;
	while ((single % 2 || twofold % 2) || ((str[*index] != '\0' && \
				str[*index] != ' ' && str[*index] != '	')))
	{
		if (!(twofold % 2) && str[*index] == '\'')
			single++;
		else if (!(single % 2) && str[*index] == '"')
			twofold++;
		*index = *index + 1;
	}
	result = ft_substr(str, start, *index - start);
	if (!result)
		exit_malloc_error();
	return (result);
}

static void	judge_file(char *str, size_t *index, char **result, size_t *count)
{
	if (str[*index] == '\'')
	{
		result[*count] = file_input_array(str, index);
		*count = *count + 1;
	}
	else if (str[*index] == '"')
	{
		result[*count] = file_input_array(str, index);
		*count = *count + 1;
	}
	else if (str[*index] != ' ' || str[*index] != '	')
	{
		result[*count] = file_input_array(str, index);
		*count = *count + 1;
	}
	return ;
}

static char	**unfold_file_to_array(t_env *env, char **result)
{
	size_t	index;

	index = 0;
	while (result[index] != NULL)
	{
		result[index] = unfold_main(env, result[index]);
		index++;
	}
	return (result);
}

char	**file_to_array(t_env *env, char *str)
{
	size_t	index;
	size_t	count;
	char	**result;

	index = 0;
	count = 0;
	result = (char **)ft_calloc(sizeof(char *), count_file_nbrs(str) + 1);
	if (!result)
		exit_malloc_error();
	while (str[index] != '\0')
	{
		judge_file(str, &index, result, &count);
		if (str[index] == '\0')
			break ;
		index++;
	}
	result[count] = NULL;
	result = unfold_file_to_array(env, result);
	return (result);
}
