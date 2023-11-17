/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:56:11 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/17 14:25:51 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/pipe.h"
#include "../../includes/error.h"

void	execve_without_fork(t_data *data, t_parser *parser, t_pipe *pipelist)
{
	extern int	errno;
	char		**command;
	char		**env;
	char		*full_path;

	if (check_absolute_path(parser->cmd))
		full_path = set_absolute_path(parser->cmd);
	else
		full_path = check_cmd_path(data->env, parser);
	if (!full_path)
		return ;
	command = create_command(parser, pipelist->array);
	env = struct_to_array(data->env);
	signal_minishell(data->signal, INTERACTIVE);
	if (execve(full_path, command, env) == -1)
		data->env->status = -1;
	perror("minishell");
	free(full_path);
	double_array_free(command);
	double_array_free(env);
	return ;
}
