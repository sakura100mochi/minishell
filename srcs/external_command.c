/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:24:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/24 18:53:44 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	exe_ext_command(char *full_path, t_exe *exe, char **command)
{
	extern char	**environ;

	exe->exe_flag = execve(full_path, command, environ);
	perror("execve");
	exit(EXIT_SUCCESS);
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

void	external_command(t_init *state, t_exe *exe,
						t_parser *parser, char *file)
{
	int		status;
	char	**command;
	char	*full_path;

	full_path = check_cmd_path(state->env, parser);
	if (!full_path)
		return ;
	command = create_command(parser, file);
	status = 0;
	exe->pid = fork();
	if (exe->pid < 0)
		exit(EXIT_FAILURE);
	else if (exe->pid == 0)
		exe_ext_command(full_path, exe, command);
	else
		waitpid(exe->pid, &status, 0);
	free(full_path);
	double_array_free(command);
	return ;
}
