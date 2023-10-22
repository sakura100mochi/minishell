/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_in_redirect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:40:15 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/21 17:39:31 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/built_in.h"
#include "../includes/pipe.h"

int	check_redirect(t_parser *parser)
{
	if (parser->redirect)
		return (YES);
	return (NO);
}

static int	change_std_to_fd(int *stdin, int *stdout, int input, int output)
{
	if (output)
	{
		*stdout = dup(1);
		dup2(output, STDOUT_FILENO);
		close(output);
	}
	if (input)
	{
		*stdin = dup(0);
		dup2(input, STDIN_FILENO);
		close(input);
	}
	return (YES);
}

static int	change_fd_to_std(int *stdin, int *stdout, int input, int output)
{
	if (input)
	{
		dup2(*stdin, STDIN_FILENO);
		close(*stdin);
	}
	if (output)
	{
		dup2(*stdout, STDOUT_FILENO);
		close(*stdout);
	}
	return (YES);
}

int	dup_command(t_data *data, t_parser *parser, t_file *file, char *str)
{
	int	stdin;
	int	stdout;
	int	input;
	int	output;

	stdin = 0;
	stdout = 0;
	input = last_input_fd(file);
	output = last_output_fd(file);
	change_std_to_fd(&stdin, &stdout, input, output);
	if (!judge_built_in(data, parser, str))
		fork_and_execve(data, parser, str);
	change_fd_to_std(&stdin, &stdout, input, output);
	close_fd(file);
	return (YES);
}

int	without_fork_dup_command(t_data *data, t_parser *parser, \
										t_file *file, char *str)
{
	int	stdin;
	int	stdout;
	int	input;
	int	output;

	stdin = 0;
	stdout = 0;
	input = last_input_fd(file);
	output = last_output_fd(file);
	change_std_to_fd(&stdin, &stdout, input, output);
	if (!judge_built_in(data, parser, str))
		without_fork_dup_command(data, parser, file, str);
	change_fd_to_std(&stdin, &stdout, input, output);
	close_fd(file);
	return (YES);
}
