/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:06:30 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/05 18:11:24 by csakamot         ###   ########.fr       */
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

static t_pipe	*close_pipe(t_pipe *pipelist)
{
	if (!pipelist->prev->head)
		close(pipelist->prev->pipe[0]);
	if (!pipelist->head)
		close(pipelist->pipe[1]);
	return (pipelist->next);
}

static int	pipe_fork_error(t_pipe *pipelist)
{
	perror("minishell");
	if (!pipelist->head)
		close(pipelist->pipe[0]);
	close_pipe(pipelist);
	return (YES);
}

int	pipe_main(t_data *data, t_parser *parser, size_t len)
{
	size_t	index;
	t_pipe	*head;
	t_pipe	*pipelist;

	index = 0;
	pipelist = init_pipe(data, len);
	head = pipelist;
	pipelist = pipelist->next;
	signal_minishell(data->signal, IGN);
	while (index <= len)
	{
		open_pipe(data, parser, pipelist);
		pipelist->pid = fork();
		if (pipelist->pid == -1 && pipe_fork_error(pipelist))
			break ;
		else if (pipelist->pid == 0)
			do_pipe_dup_exec(data, parser, pipelist);
		pipelist = close_pipe(pipelist);
		parser = parser->next;
		index++;
	}
	pipe_end_process(data, head);
	return (0);
}
