/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:06:30 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/28 17:14:00 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/built_in.h"
#include "../../includes/pipe.h"
#include "../../includes/unfold.h"
#include "../../includes/error.h"

static void	pipe_exec(t_data *data, t_parser *parser, t_pipe *pipelist)
{
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
			execve_without_fork(data, parser, pipelist, pipelist->file);
			signal_minishell(data->signal, NORMAL);
		}
	}
	return ;
}

static int	do_pipe_dup_exec(t_data *data, t_parser *parser, \
								t_pipe *pipelist, size_t len)
{
	if (pipelist->index != len)
	{
		if (!(pipelist->index % 2))
			close(pipelist->pipe1[0]);
		else
			close(pipelist->pipe2[0]);
	}
	if (pipelist->index > 0)
	{
		if (!(pipelist->index % 2))
			dup2(pipelist->pipe2[0], STDIN_FILENO);
		else
			dup2(pipelist->pipe1[0], STDIN_FILENO);
	}
	if (pipelist->index != len)
	{
		if (!(pipelist->index % 2))
			dup2(pipelist->pipe1[1], STDOUT_FILENO);
		else
			dup2(pipelist->pipe2[1], STDOUT_FILENO);
	}
	pipe_exec(data, parser, pipelist);
	return (0);
}

static void	close_pipe(t_pipe *pipelist, size_t len)
{
	if (pipelist->index > 0)
	{
		if (!(pipelist->index % 2))
			close(pipelist->pipe2[0]);
		else
			close(pipelist->pipe1[0]);
	}
	if (pipelist->index != len)
	{
		if (!(pipelist->index % 2))
			close(pipelist->pipe1[1]);
		else
			close(pipelist->pipe2[1]);
	}
}

static void	open_pipe(t_data *data, t_parser *parser, \
							t_pipe *pipelist, size_t len)
{
	if (!(pipelist->index % 2) && pipelist->index != len)
		pipe(pipelist->pipe1);
	if (pipelist->index % 2 && len != 1 && pipelist->index != len)
		pipe(pipelist->pipe2);
	pipelist->file = format_command(parser);
	parser->cmd = unfold_main(data->env, parser->cmd);
	pipelist->array = file_to_array(data->env, pipelist->file);
	pipelist->file = unfold_main(data->env, pipelist->file);
	return ;
}

int	pipe_main(t_data *data, t_parser *parser, size_t len)
{
	t_pipe	pipelist;

	ft_bzero(&pipelist, sizeof(pipelist) * 1);
	signal_minishell(data->signal, IGN);
	while (pipelist.index <= len)
	{
		open_pipe(data, parser, &pipelist, len);
		pipelist.pid = fork();
		if (pipelist.pid == -1)
			break ;
		if (pipelist.pid == 0)
		{
			do_pipe_dup_exec(data, parser, &pipelist, len);
			exit(data->env->status);
		}
		close_pipe(&pipelist, len);
		waitpid(pipelist.pid, &(pipelist.status), 0);
		pipe_execve_error(parser, pipelist.status);
		pipelist.index++;
		pipe_free(&pipelist);
		parser = parser->next;
	}
	signal_minishell(data->signal, NORMAL);
	exit_status_format(data->env, pipelist.status);
	return (0);
}
