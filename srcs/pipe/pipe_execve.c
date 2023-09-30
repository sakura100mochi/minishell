/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:56:11 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/30 15:01:59 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe.h"

static char	**struct_to_array(t_env *env)
{
	size_t	index;
	char	**result;

	index = 0;
	env = env->next;
	while (!env->head)
	{
		index++;
		env = env->next;
	}
	result = (char **)ft_calloc(sizeof(char *), index + 1);
	env = env->next;
	index = 0;
	while (!env->head)
	{
		result[index++] = ft_strdup(env->variable);
		env = env->next;
	}
	return (result);
}

static char	*check_cmd_access(t_parser *parser, char **path)
{
	size_t	index;
	char	*tmp;
	char	*full_path;

	index = 0;
	while (path[index] != NULL)
	{
		tmp = ft_strjoin(path[index], "/");
		full_path = ft_strjoin(tmp, parser->cmd);
		if (!access(full_path, X_OK))
		{
			double_array_free(path);
			free(tmp);
			return (full_path);
		}
		free(tmp);
		free(full_path);
		index++;
	}
	double_array_free(path);
	full_path = ft_strjoin("/", parser->cmd);
	if (!access(full_path, X_OK))
		return (full_path);
	free(full_path);
	return (NULL);
}

static char	*check_cmd_path(t_env *env_variable, t_parser *parser)
{
	size_t	len;
	char	*tmp;
	char	**path;
	char	*full_path;

	path = NULL;
	env_variable = env_variable->next;
	while (!env_variable->head)
	{
		len = ft_strlen(env_variable->variable);
		if (len < 5)
			return (NULL);
		else if (!ft_strncmp(env_variable->variable, "PATH=", 5))
		{
			tmp = ft_substr(env_variable->variable, 5, len);
			path = ft_split(tmp, ':');
			free(tmp);
			break ;
		}
		env_variable = env_variable->next;
	}
	full_path = check_cmd_access(parser, path);
	if (!env_variable->head && full_path)
		return (full_path);
	return (NULL);
}

static char	**create_command(t_parser *parser, char *file)
{
	size_t	words;
	size_t	index;
	char	**result;

	words = 1;
	index = 0;
	if (parser->option)
		words++;
	if (file)
		words++;
	result = (char **)ft_calloc(sizeof(char *), words + 1);
	result[index++] = ft_strdup(parser->cmd);
	if (parser->option)
		result[index++] = ft_strdup(parser->option);
	if (*file)
		result[index++] = ft_strdup(file);
	return (result);
}

int	execve_without_fork(t_init *state, t_parser *parser, char *file)
{
	char	**command;
	char	**env;
	char	*full_path;

	full_path = check_cmd_path(state->env, parser);
	if (!full_path)
		return (1);
	command = create_command(parser, file);
	env = struct_to_array(state->env);
	execve(full_path, command, env);
	return (1);
}
