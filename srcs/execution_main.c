/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:08:20 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/10 13:40:33 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/parser.h"
#include "../includes/unfold.h"
#include "../includes/built_in.h"
#include "../includes/pipe.h"
#include "../includes/redirect.h"
#include "../includes/error.h"

static int	check_redirect(t_parser *node)
{
	t_parser	*head;

	head = node;
	while (node != NULL)
	{
		if (node->redirect != NULL)
			return (YES);
		node = node->next;
	}
	node = head;
	return (NO);
}

static int	close_process(t_parser *parser, char *file)
{
	if (file == NULL)
	{
		if (parser->redirect)
			close_fd(parser->redirect);
		return (1);
	}
	return (0);
}

static void	no_pipe_exec(t_data *data, t_parser *parser)
{
	char	*file;
	char	**file_array;

	file = format_command(data->parser);
	parser->cmd = unfold_main(data->env, parser->cmd);
	file_array = file_to_array(data->env, file);
	file = unfold_main(data->env, file);
	if (close_process(parser, file))
		return ;
	if (parser->redirect)
		dup_command(data, parser, file, file_array);
	else
	{
		if (!judge_built_in(data, parser, file, file_array))
		{
			signal_minishell(data->signal, IGN);
			fork_and_execve(data, parser, file, file_array);
			signal_minishell(data->signal, NORMAL);
		}
	}
	double_array_free(file_array);
	free(file);
	return ;
}

void	execution_main(t_data *data)
{
	size_t	len;

	len = ft_parsersize(data->parser) - 1;
	if (check_redirect(data->parser) == YES)
	{
		if (redirect_main(data, data->parser) == NO)
			return ;
	}
	if (len != 0)
	{
		pipe_main(data, data->parser, len);
		return ;
	}
	no_pipe_exec(data, data->parser);
	return ;
}
