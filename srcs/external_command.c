/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:24:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/15 20:14:39 by csakamot         ###   ########.fr       */
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

static char	**create_command(t_parser *parser, char **array)
{
	size_t	words;
	size_t	index;
	char	**result;

	words = 1;
	index = 0;
	if (parser->option)
		words += optionlen(parser->option);
	words += arraylen(array);
	result = (char **)ft_calloc(sizeof(char *), words + 1);
	result[index++] = ft_strdup(parser->cmd);
	if (parser->option)
		add_option_to_array(result, parser->option, &index);
	add_file_to_array(result, array, index, words);
	result[words] = NULL;
	return (result);
}

static void	do_child_process(char *full_path, char **command, char **env)
{
	execve(full_path, command, env);
	perror("minishell");
	exit(EXIT_SUCCESS);
	return ;
}

static void	fork_process(pid_t pid, char *full_path, char **command, char **env)
{
	if (pid < 0)
		exit(EXIT_FAILURE);
	else if (pid == 0)
		do_child_process(full_path, command, env);
	return ;
}

void	fork_and_execve(t_data *data, t_parser *parser, char **array)
{
	pid_t	pid;
	int		status;
	char	**command;
	char	**env;
	char	*full_path;

	status = 0;
	if (check_absolute_path(parser->cmd))
		full_path = set_absolute_path(parser->cmd);
	else
		full_path = check_cmd_path(data->env, parser);
	if (!full_path)
		return ;
	command = create_command(parser, array);
	env = struct_to_array(data->env);
	pid = fork();
	signal_minishell(data->signal, INTERACTIVE);
	fork_process(pid, full_path, command, env);
	if (pid > 0)
		waitpid(pid, &status, 0);
	data->env->status = status;
	exit_status_format(data->env, status);
	free(full_path);
	double_array_free(command);
	double_array_free(env);
}
