/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:06:30 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/01 18:12:14 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/built_in.h"
#include "../../includes/pipe.h"
#include "../../includes/unfold.h"
#include "../../includes/error.h"

static void	open_pipe(t_data *data, t_parser *parser, \
							t_pipe *pipelist)
{
	if (!pipelist->head)
		pipe(pipelist->pipe);
	pipelist->file = format_command(parser);
	parser->cmd = unfold_main(data->env, parser->cmd);
	pipelist->array = file_to_array(data->env, pipelist->file);
	pipelist->file = unfold_main(data->env, pipelist->file);
	return ;
}

static void	close_pipe(t_pipe *pipelist)
{
	if (!pipelist->prev->head)
		close(pipelist->prev->pipe[0]);
	if (!pipelist->head)
		close(pipelist->pipe[1]);
	return ;
}

static void	wait_pipe(t_pipe *pipelist)
{
	int	status;

	status = 0;
	pipelist = pipelist->next;
	while (!pipelist->head)
	{
		waitpid(pipelist->pid, &status, 0);
		pipelist = pipelist->next;
	}
	waitpid(pipelist->pid, &status, 0);
	return ;
}

int	pipe_main(t_data *data, t_parser *parser, size_t len)
{
	size_t	index;
	t_pipe	*head;
	t_pipe	*pipelist;
	int		fd;

	(void)parser;
	index = 0;
	pipelist = init_pipe(data, len);
	head = pipelist;
	pipelist = pipelist->next;
	while (index <= len)
	{
		fd = dup(1);
		close(fd);
		open_pipe(data, parser, pipelist);
		pipelist->pid = fork();
		if (pipelist->pid == -1)
		{
			printf("error\n");
			break ;
		}
		else if (pipelist->pid == 0)
		{
			if (!pipelist->head)
				close(pipelist->pipe[0]);
			if (!pipelist->prev->head)
				dup2(pipelist->prev->pipe[0], STDIN_FILENO);
			if (!pipelist->head)
				dup2(pipelist->pipe[1], STDOUT_FILENO);
			if (!judge_built_in(data, parser, pipelist->file, pipelist->array))
				execve_without_fork(data, parser, pipelist, pipelist->file);
			exit(data->env->status);
		}
		else if (pipelist->pid > 0)
		{
			close_pipe(pipelist);
			parser = parser->next;
			pipelist = pipelist->next;
			index++;
		}
	}
	wait_pipe(head);
	pipe_free(head);
	return (0);
}
