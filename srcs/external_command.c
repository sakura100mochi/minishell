/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:24:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/23 22:10:02 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	exe_ext_command(t_parser *parser, t_exe *exe, char **command)
{
	char		*exe;
	extern char	**environ;

	exe = ft_strjoin(BINARY, parser->cmd);
	exe->exe_flag = execve(exe, exe->command, environ);
	perror("execve");
	exit(EXIT_SUCCESS);
}

static int	check_cmd_access(t_parser *parser, char **path)
{
	size_t	index;
	char	*tmp;
	char	*full_path;

	index = 0;
	while (!path[index])
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
	char	**path;

	env_variable = env_variable->next;
	while (!env_variable->head)
	{
		len = ft_strlen(env_variable->variable);
		if (len < 5)
			return (1);
		else if (!ft_strncmp(env_variable->variable, "PATH=", 5))
		{
			path = ft_split(env_variable->variable, ':');
			break ;
		}
		env_variable = env_variable->next;
	}
	if (!check_cmd_access(parser, path))
		return(0);
	return (1);
}

void	external_command(t_init *state, t_exe *exe, t_parser *parser, char *file)
{
	int		status;

	if (check_cmd_path(state->env, parser))
	status = 0;
	exe->pid = fork();
	if (exe->pid < 0)
		exit(EXIT_FAILURE);
	else if (exe->pid == 0)
		exe_ext_command(parser, exe, file);
	else
		waitpid(exe->pid, &status, 0);
	double_array_free(exe->command);
	return ;
}
