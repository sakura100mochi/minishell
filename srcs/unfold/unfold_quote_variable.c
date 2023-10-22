/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfold_quote_variable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:59:58 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/22 18:04:24 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/unfold.h"
#include "../../includes/error.h"

static char	*find_nbr_questoin(t_env *env, char *str, size_t len)
{
	char	*result;

	result = NULL;
	if (!ft_strncmp("?", str, len))
	{
		result = ft_itoa((int)g_status);
		if (!result)
			exit_malloc_error();
		return (result);
	}
	else if (!ft_strncmp("0", str, len))
	{
		result = ft_strdup("minishell");
		if (!result)
			exit_malloc_error();
		return (result);
	}
	(void)env;
	return (result);
}

static char	*find_env_variable(t_env *env, char *str)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(str) + 1;
	tmp = find_nbr_questoin(env, str, len);
	if (tmp)
		return (tmp);
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
