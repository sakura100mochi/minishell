/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfold_quote_variable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:59:58 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/03 17:08:34 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/unfold.h"

static int	check_env_variable(char *str, size_t start, size_t end)
{
	size_t	index;

	index = start;
	while (index < end)
	{
		if (str[index] == '$')
			return (0);
		index++;
	}
	return (1);
}

static char	**split_env_variable(char *tmp, size_t len)
{
	size_t	index;
	size_t	start;
	size_t	cnt;
	char	**result;

	index = 0;
	start = 0;
	cnt = 0;
	result = (char **)ft_calloc(sizeof(char *), len + 1);
	while (tmp[index] != '\0')
	{
		if (tmp[index] == '\'' || tmp[index] == ' ' || \
				tmp[index] == '	' || tmp[index] == '$')
		{
			result[cnt++] = ft_substr(tmp, start, index);
			start = index + 1;
		}
		index++;
	}
	result[cnt] = NULL;
	return (result);
}

static char	*find_env_variable(t_env *env, char *str)
{
	size_t	len;
	char	*result;

	len = ft_strlen(str);
	while (!env->head)
	{
		if (!ft_strncmp(env->variable, str, len))
			return (env->variable);
		env = env->next;
	}
	return ("\0");
}

static int	unfold_split_words(char **strage, t_env *env)
{
	size_t	index;
	char	*tmp;

	index = 0;
	while (strage[index] != NULL)
	{
		if (strage[index][0] == '$')
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

char	*unfold_quote_variable(char *str, t_env *env, size_t start, size_t end)
{
	size_t	len;
	size_t	index;
	char	*tmp;
	char	*result;
	char	**strage;

	index = 0;
	if (check_env_variable(str, start, end))
	return (str);
	tmp = ft_substr(str, start, end);
	len = cnt_env_variable(tmp);
	strage = split_env_variable(tmp, len);
	unfold_split_words(strage, env);
	while (strage[index] != NULL)
	{
		result = ft_strjoin_gnl(result, strage[index]);
		index++;
	}
	free(tmp);
	double_array_free(strage);
	return (result);
}
