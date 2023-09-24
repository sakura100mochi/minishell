/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:24:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/24 17:22:16 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	exe_ext_command(t_parser *parser, t_exe *exe, char **command)
{
	char		*full_path;
	extern char	**environ;

	full_path = ft_strjoin(BINARY, parser->cmd);
	exe->exe_flag = execve(full_path, command, environ);
	perror("execve");
	exit(EXIT_SUCCESS);
}

static int	check_cmd_access(t_parser *parser, char **path)
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
			free(tmp);
			free(full_path);
			return (0);
		}
		free(tmp);
		free(full_path);
		index++;
	}
	double_array_free(path);
	full_path = ft_strjoin("/", parser->cmd);
	if (!access(full_path, X_OK))
	{
		free(full_path);
		return (0);
	}
	return (1);
}

static int	check_cmd_path(t_env *env_variable, t_parser *parser)
{
	size_t	len;
	char	*tmp;
	char	**path;

	env_variable = env_variable->next;
	while (!env_variable->head)
	{
		len = ft_strlen(env_variable->variable);
		if (len < 5)
			return (1);
		else if (!ft_strncmp(env_variable->variable, "PATH=", 5))
		{
			tmp = ft_substr(env_variable->variable, 5, \
						ft_strlen(env_variable->variable));
			path = ft_split(tmp, ':');
			free(tmp);
			break ;
		}
		env_variable = env_variable->next;
	}
	if (!env_variable->head && !check_cmd_access(parser, path))
		return (0);
	return (1);
}

static char	**create_command(t_parser *parser, char *file)
{
	// size_t	index;
	char	**result;

	(void)file;
	result = (char **)ft_calloc(sizeof(char *), 2);
	result[0] = ft_strdup(parser->cmd);
	result[1] = NULL;
	// index = 0;
	// while (result[index] != NULL)
	// {
	// 	printf("%s\n", result[index]);
	// 	index++;
	// }
	return (result);
}

void	external_command(t_init *state, t_exe *exe, t_parser *parser, char *file)
{
	int		status;
	char	**command;

	if (check_cmd_path(state->env, parser))
		return ;
	command = create_command(parser, file);
	status = 0;
	exe->pid = fork();
	if (exe->pid < 0)
		exit(EXIT_FAILURE);
	else if (exe->pid == 0)
		exe_ext_command(parser, exe, command);
	else
		waitpid(exe->pid, &status, 0);
	double_array_free(command);
	return ;
}
