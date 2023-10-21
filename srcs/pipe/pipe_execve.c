/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:56:11 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/21 15:17:44 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/pipe.h"
#include "../../includes/error.h"

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
	if (!result)
		exit_malloc_error();
	env = env->next;
	index = 0;
	while (!env->head)
	{
		result[index++] = ft_strdup(env->variable);
		if (!result[index - 1])
			exit_malloc_error();
		env = env->next;
	}
	return (result);
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
	if (!result)
		exit_malloc_error();
	result[index++] = ft_strdup(parser->cmd);
	if (!result[index - 1])
		exit_malloc_error();
	if (parser->option)
		result[index++] = ft_strdup(parser->option);
	if (parser->option && !result[index - 1])
		exit_malloc_error();
	if (*file)
		result[index++] = ft_strdup(file);
	if (*file && !result[index - 1])
		exit_malloc_error();
	return (result);
}

int	execve_without_fork(t_data *data, t_parser *parser, char *file)
{
	char	**command;
	char	**env;
	char	*full_path;

	full_path = check_cmd_path(data->env, parser);
	if (!full_path)
		return (1);
	command = create_command(parser, file);
	env = struct_to_array(data->env);
	execve(full_path, command, env);
	return (1);
}
