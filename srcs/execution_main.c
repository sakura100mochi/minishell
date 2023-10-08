/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:08:20 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/08 19:37:13 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/parser.h"
#include "../includes/unfold.h"
#include "../includes/built_in.h"
#include "../includes/pipe.h"
#include "../includes/redirect.h"

static size_t	check_quote_in_command(char *str)
{
	size_t	index;
	size_t	single;
	size_t	twofold;

	index = 0;
	single = 0;
	twofold = 0;
	while (str[index] != '\0')
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

char	*format_command(t_env *env, t_parser *parser)
{
	size_t	cmd_len;
	size_t	file_len;
	char	*tmp;
	char	*file;

	cmd_len = check_quote_in_command(parser->cmd);
	file_len = ft_strlen(parser->cmd) - (cmd_len + 1);
	tmp = ft_substr(parser->cmd, 0, cmd_len);
	file = ft_substr(parser->cmd, cmd_len + 1, file_len);
	free(parser->cmd);
	parser->cmd = tmp;
	file = unfold_main(env, parser, file);
	return (file);
}

void	execution_main(t_data *data)
{
	char	*file;
	size_t	len;

	len = ft_parsersize(data->parser) - 1;
	if (len != 0)
	{
		data = init_pipe(data, len);
		pipe_main(data, data->parser, data->pipe->next, len);
		return ;
	}
	if (data->parser->redirect)
		redirect_main(data, data->parser);
	file = format_command(data->env, data->parser);
	if (!judge_built_in(data, data->parser, file))
		fork_and_execve(data, data->exe, data->parser, file);
	free(file);
}

	// printf("%s, %s, %s\n", data->parser->cmd, data->parser->option, file);