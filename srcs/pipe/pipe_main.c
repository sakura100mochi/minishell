/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:06:30 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/19 13:54:28 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/built_in.h"
#include "../../includes/pipe.h"

static int	do_pipe_dup(int *pipe1, int *pipe2,
									size_t index, size_t len)
{
	if (index != len)
	{
		if (!(index % 2))
			close(pipe1[0]);
		else
			close(pipe2[0]);
	}
	if (index > 0)
	{
		if (!(index % 2))
			dup2(pipe2[0], STDIN_FILENO);
		else
			dup2(pipe1[0], STDIN_FILENO);
	}
	if (index != len)
	{
		if (!(index % 2))
			dup2(pipe1[1], STDOUT_FILENO);
		else
			dup2(pipe2[1], STDOUT_FILENO);
	}
	return (0);
}

int	pipe_main(t_data *data, t_parser *parser, size_t len, size_t index)
{
	pid_t	pid;
	int		pipe1[2];
	int		pipe2[2];
	int		status;
	char	*file;

	status = 0;
	while (index <= len)
	{
		if (!(index % 2) && index != len)
			pipe(pipe1);
		if (index % 2 && len != 1 && index != len)
			pipe(pipe2);
		file = format_command(data->env, parser);
		pid = fork();
		if (pid == -1)
			break ;
		if (pid == 0)
		{
			do_pipe_dup(pipe1, pipe2, index, len);
			if (!judge_built_in(data, parser, file))
				execve_without_fork(data, parser, file);
			exit(EXIT_FAILURE);
		}
		if (index > 0)
		{
			if (!(index % 2))
				close(pipe2[0]);
			else
				close(pipe1[0]);
		}
		if (index != len)
		{
			if (!(index % 2))
				close(pipe1[1]);
			else
				close(pipe2[1]);
		}
		waitpid(pid, &status, 0);
		free(file);
		parser = parser->next;
		index++;
	}
	return (0);
}

// int	pipe_main(t_data *data, t_parser *parser, t_pipe *pipelist, size_t len)
// {
// 	size_t	index;
// 	// int		pipe1[2];
// 	// int		pipe2[2];
// 	int		status;
// 	char	*file;

// 	index = 0;
// 	status = 0;
// 	while (index <= len)
// 	{
// 	// 	if (!(index % 2) && index != len)
// 	// 		pipe(pipe1);
// 	// 	if (index % 2 && len != 1 && index != len)
// 	// 		pipe(pipe2);
// 		file = format_command(data->env, parser);
// 		pipelist->pid = fork();
// 		if (pipelist->pid == -1)
// 			exit(EXIT_FAILURE);
// 		if (pipelist->pid == 0)
// 		{
// 			if (!pipelist->head)
// 				close(pipelist->pipe_fd[0]);
// 			if (!pipelist->prev->head)
// 				dup2(pipelist->prev->pipe_fd[0], STDIN_FILENO);
// 			if (!pipelist->head)
// 				dup2(pipelist->pipe_fd[1], STDOUT_FILENO);
// 			if (!judge_built_in(data, parser, file))
// 				execve_without_fork(data, parser, file);
// 			exit(EXIT_FAILURE);
// 		}
// 		if (!pipelist->prev->head)
// 			close(pipelist->prev->pipe_fd[0]);
// 		if (!pipelist->head)
// 			close(pipelist->pipe_fd[1]);
// 		waitpid(pipelist->pid, &status, 0);
// 		free(file);
// 		parser = parser->next;
// 		pipelist = pipelist->next;
// 		index++;
// 	}
// 	return (0);
// }

// printf("%zu, %s, %s, %s\n", pipelist->head,arser->cmd, parser->option, file);