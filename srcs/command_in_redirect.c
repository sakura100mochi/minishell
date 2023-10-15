/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_in_redirect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:40:15 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/15 15:32:54 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/built_in.h"

static int	do_dup_command(t_data *data, t_parser *parser,
									t_file *file, char *str)
{
	int	stdout;
	int	stdin;

	stdout = 0;
	stdin = 0;
	while (file != NULL)
	{
		if (file->type == OUTPUT || file->type == APPEND)
		{
			stdout = dup(1);
			dup2(file->fd, STDOUT_FILENO);
			if (!judge_built_in(data, parser, str))
				fork_and_execve(data, data->exe, parser, str);
			close(file->fd);
			dup2(stdout, STDOUT_FILENO);
			close(stdout);
		}
		else if (file->type == INPUT)
		{
			stdin = dup(0);
			dup2(file->fd, STDIN_FILENO);
			if (!judge_built_in(data, parser, str))
				fork_and_execve(data, data->exe, parser, str);
			close(file->fd);
			dup2(stdin, STDIN_FILENO);
			close(stdin);
		}
		else if (file->type == HEREDOC || file->type == QUOTE_HEREDOC)
		{
			printf("ok!%d, type:%d\n", file->fd, file->type);
			stdin = dup(0);
			dup2(file->fd, STDIN_FILENO);
			if (!judge_built_in(data, parser, str))
				fork_and_execve(data, data->exe, parser, str);
			close(file->fd);
			dup2(stdin, STDIN_FILENO);
			close(stdin);
		}
		file = file->next;
	}
	return (YES);
}

// static t_file	*check_fd(t_file *file, char *str)
// {
// 	if (str == NULL)
// 		return (NULL);
// 	while (file->next != NULL)
// 		file = file->next;
// 	return (file);
// }

static void	close_fd(t_file *file)
{
	while (file != NULL)
	{
		if (file->type == HEREDOC || file->type == QUOTE_HEREDOC)
			unlink("/tmp/tmp");
		if (file->fd)
			close(file->fd);
		file = file->next;
	}
	return ;
}

int	check_redirect(t_parser *parser)
{
	if (parser->redirect)
		return (YES);
	return (NO);
}

int	dup_command(t_data *data, t_parser *parser, t_file *file, char *str)
{
	// t_file	*head;
	// t_file	*tmp_file;

	// head = file;
	// tmp_file = check_fd(file, str);
	do_dup_command(data, parser, file, str);
	close_fd(file);
	return (YES);
}
