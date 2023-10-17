/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_in_redirect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:40:15 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/17 11:15:36 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/built_in.h"

// static int	do_dup_command(t_data *data, t_parser *parser,
// 									t_file *file, char *str)
// {
// 	int	stdout;
// 	int	stdin;
// 	int	input;
// 	int	output;

// 	stdout = 0;
// 	stdin = 0;
// 	input = last_input_fd(file);
// 	output = last_output_fd(file);
// 	if (output)
// 	{
// 		stdout = dup(1);
// 		dup2(output, STDOUT_FILENO);
// 		close(output);
// 	}
// 	if (input)
// 	{
// 		stdin = dup(0);
// 		dup2(input, STDIN_FILENO);
// 		close(input);
// 	}
// 	if (!judge_built_in(data, parser, str))
// 		fork_and_execve(data, data->exe, parser, str);
// 	if (input)
// 	{
// 		dup2(stdin, STDIN_FILENO);
// 		close(stdin);
// 	}
// 	if (output)
// 	{
// 		dup2(stdout, STDOUT_FILENO);
// 		close(stdout);
// 	}
// 	return (YES);
// }

void	close_fd(t_file *file)
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
	int	stdout;
	int	stdin;
	int	input;
	int	output;

	stdout = 0;
	stdin = 0;
	input = last_input_fd(file);
	output = last_output_fd(file);
	if (output)
	{
		stdout = dup(1);
		dup2(output, STDOUT_FILENO);
		close(output);
	}
	if (input)
	{
		stdin = dup(0);
		dup2(input, STDIN_FILENO);
		close(input);
	}
	if (!judge_built_in(data, parser, str))
		fork_and_execve(data, data->exe, parser, str);
	if (input)
	{
		dup2(stdin, STDIN_FILENO);
		close(stdin);
	}
	if (output)
	{
		dup2(stdout, STDOUT_FILENO);
		close(stdout);
	}
	close_fd(file);
	return (YES);
}
