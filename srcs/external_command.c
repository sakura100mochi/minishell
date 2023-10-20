/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:24:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/20 17:12:49 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/error.h"

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
		words += count_file_nbr(file);
	result = (char **)ft_calloc(sizeof(char *), words + 1);
	result[index++] = ft_strdup(parser->cmd);
	if (parser->option)
		result[index++] = ft_strdup(parser->option);
	if (*file)
		add_file_to_array(result, file, index, words);
	result[words] = NULL;
	return (result);
}

static void	do_child_process(char *full_path, char **command, char **env)
{
	execve(full_path, command, env);
	perror("minishell:");
	exit(EXIT_SUCCESS);
	return ;
}

void	fork_and_execve(t_data *data, t_parser *parser, char *file)
{
	pid_t	pid;
	int		status;
	char	**command;
	char	**env;
	char	*full_path;

	status = 0;
	full_path = check_cmd_path(data->env, parser);
	if (!full_path)
		return (command_not_found(data->env, parser->cmd));
	command = create_command(parser, file);
	env = struct_to_array(data->env);
	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	else if (pid == 0)
		do_child_process(full_path, command, env);
	else
		waitpid(pid, &status, 0);
	data->env->status = status;
	free(full_path);
	double_array_free(command);
	double_array_free(env);
}
