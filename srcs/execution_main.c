/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:08:20 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/22 12:45:47 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/parser.h"
#include "../includes/unfold.h"
#include "../includes/built_in.h"
#include "../includes/pipe.h"
#include "../includes/redirect.h"
#include "../includes/error.h"

static size_t	check_quote_in_command(char *str)
{
	size_t	index;
	size_t	single;
	size_t	twofold;

	index = 0;
	single = 0;
	twofold = 0;
	while (str != NULL && str[index] != '\0')
	{
		if (!(single % 2) && !(twofold % 2) && str[index] == '\'')
			single++;
		else if (!(single % 2) && !(twofold % 2) && str[index] == '"')
			twofold++;
		else if (single % 2 && str[index] == '\'')
			single++;
		else if (twofold % 2 && str[index] == '"')
			twofold++;
		else if (!(single % 2) && !(twofold % 2) && \
		(str[index] == ' ' || str[index] == '	'))
			return (index);
		index++;
	}
	return (index);
}

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

static void	no_pipe_exec(t_data *data, t_parser *parser)
{
	char	*file;

	file = format_command(data->env, data->parser);
	if (file == NULL)
	{
		if (parser->redirect)
			close_fd(parser->redirect);
		return ;
	}
	if (parser->redirect)
		dup_command(data, parser, parser->redirect, file);
	else
	{
		if (!judge_built_in(data, parser, file))
		{
			signal_minishell(data->signal, IGN);
			fork_and_execve(data, parser, file);
			signal_minishell(data->signal, NORMAL);
		}
	}
	free(file);
	return ;
}

char	*format_command(t_env *env, t_parser *parser)
{
	size_t	cmd_len;
	size_t	file_len;
	char	*tmp;
	char	*file;

	if (parser->cmd == NULL)
		return (NULL);
	cmd_len = check_quote_in_command(parser->cmd);
	file_len = ft_strlen(parser->cmd) - (cmd_len + 1);
	tmp = ft_substr(parser->cmd, 0, cmd_len);
	if (!tmp)
		exit_malloc_error();
	file = ft_substr(parser->cmd, cmd_len + 1, file_len);
	if (!file)
		exit_malloc_error();
	free(parser->cmd);
	parser->cmd = tmp;
	file = unfold_main(env, parser, file);
	return (file);
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
