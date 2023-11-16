/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_main_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/17 08:22:24 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/built_in.h"
#include "../../includes/pipe.h"
#include "../../includes/error.h"

static void	wait_pipe(t_env *env, t_parser *parser, t_pipe *pipelist)
{
	int	status;

	status = 0;
	pipelist = pipelist->next;
	while (!pipelist->head)
	{
		waitpid(pipelist->pid, &status, 0);
		pipe_print_error(status, parser->cmd);
		pipelist = pipelist->next;
		parser = parser->next;
	}
	waitpid(pipelist->pid, &status, 0);
	pipe_print_error(status, parser->cmd);
	if (status == 512)
		status = 2;
	else if (status == 32512)
		status = 127;
	env->status = status;
	return ;
}

void	do_pipe_dup_exec(t_data *data, t_parser *parser, t_pipe *pipelist)
{
	if (!pipelist->head)
		close(pipelist->pipe[0]);
	if (!pipelist->prev->head)
		dup2(pipelist->prev->pipe[0], STDIN_FILENO);
	if (!pipelist->head)
		dup2(pipelist->pipe[1], STDOUT_FILENO);
	if (pipelist->file == NULL)
	{
		if (parser->redirect)
			close_fd(parser->redirect);
		return ;
	}
	if (parser->redirect)
		without_fork_dup_command(data, parser, \
				parser->redirect, pipelist);
	else
	{
		if (!judge_built_in(data, parser, pipelist->file, pipelist->array))
		{
			execve_without_fork(data, parser, pipelist);
			signal_minishell(data->signal, NORMAL);
		}
	}
	exit(data->env->status);
}

void	pipe_end_process(t_data *data, t_pipe *pipelist)
{
	wait_pipe(data->env, data->parser, pipelist);
	pipe_free(pipelist);
	signal_minishell(data->signal, NORMAL);
	return ;
}
