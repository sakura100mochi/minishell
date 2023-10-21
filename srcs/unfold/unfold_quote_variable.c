/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfold_quote_variable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:59:58 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/20 16:48:00 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/unfold.h"

static char	*input_env_variable(char *str, size_t *start, \
									size_t index, size_t *flag)
{
	char	*result;

	result = ft_substr(str, *start, index - *start);
	if (!flag)
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

static char	*find_env_variable(t_env *env, char *str)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(str) + 1;
	if (ft_strncmp("$?", str, len - 1))
	{
		tmp = ft_itoa((int)env->status);
		return (tmp);
	}
	env = env->next;
	while (!env->head)
	{
		if (ft_strncmp(env->variable, str, len) == '=')
		{
			tmp = ft_substr(env->variable, len, ft_strlen(env->variable));
			return (tmp);
		}
		env = env->next;
	}
	tmp = ft_calloc(sizeof(char), 0);
	return (tmp);
}

int	unfold_split_words(char **strage, t_env *env)
{
	size_t	index;
	char	*tmp;

	index = 0;
	while (strage[index] != NULL)
	{
		if (strage[index][0] == '$' && strage[index][1] != '\0' && \
				(ft_isalnum(strage[index][1]) || strage[index][1] == '?'))
		{
			tmp = ft_substr(strage[index], 1, ft_strlen(strage[index]));
			free(strage[index]);
			strage[index] = find_env_variable(env, tmp);
			free(tmp);
		}
		index++;
	}
	return (0);
}

char	*unfold_quote_variable(char *str, t_env *env, size_t start, size_t *end)
{
	size_t	len;
	size_t	index;
	char	*tmp;
	char	*result;
	char	**strage;

	index = 0;
	result = NULL;
	if (check_env_variable(str, start, *end))
		return (str);
	tmp = ft_substr(str, start, *end + 1 - start);
	len = cnt_env_variable(tmp);
	strage = split_env_variable(tmp, len);
	unfold_split_words(strage, env);
	while (strage[index] != NULL)
	{
		result = strjoin_mini(result, strage[index]);
		index++;
	}
	*end = *end + 1;
	result = str_connection(result, str, &start, end);
	free(str);
	double_array_free(strage);
	free(tmp);
	return (result);
}
