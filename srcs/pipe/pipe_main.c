/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:06:30 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/21 17:07:26 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/built_in.h"
#include "../../includes/pipe.h"

static void	pipe_exec(t_data *data, t_parser *parser, t_pipe *pipelist)
{
	if (pipelist->file == NULL)
	{
		if (parser->redirect)
			close_fd(parser->redirect);
		return ;
	}
	if (data->parser->redirect)
		dup_command(data, parser, parser->redirect, pipelist->file);
	else
	{
		if (!judge_built_in(data, parser, pipelist->file))
			execve_without_fork(data, parser, pipelist->file);
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
	pipelist->file = format_command(data->env, parser);
	return ;
}

int	pipe_main(t_data *data, t_parser *parser, size_t len)
{
	t_pipe	pipelist;

	pipelist.index = 0;
	pipelist.status = 0;
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
			exit(EXIT_FAILURE);
		}
		close_pipe(&pipelist, len);
		waitpid(pipelist.pid, &(pipelist.status), 0);
		pipelist.index++;
		free(pipelist.file);
		parser = parser->next;
	}
	signal_minishell(data->signal, NORMAL);
	return (0);
}
