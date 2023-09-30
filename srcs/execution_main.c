/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:08:20 by csakamot          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/09/30 17:54:03 by csakamot         ###   ########.fr       */
=======
/*   Updated: 2023/09/30 17:59:00 by yhirai           ###   ########.fr       */
>>>>>>> 8b77250ee73b5fc47e5efb8c0a0a213b4585f7ca
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/unfold.h"
#include "../includes/built_in.h"
#include "../includes/pipe.h"
#include "../includes/redirect.h"

static int	check_headoc(t_file *redirect)
{
	if (!redirect)
		return (1);
	while (redirect != NULL)
	{
		if (redirect->type == HEREDOC)
			return (0);
		redirect = redirect->next;
	}
	return (1);
}

static size_t	count_listlen(t_parser *list)
{
	size_t	len;

	len = 0;
	while (list != NULL)
	{
		list = list->next;
		len++;
	}
	return (len - 1);
}

char	*format_command(t_parser *parser)
{
	size_t	cmd_len;
	size_t	file_len;
	char	*tmp;
	char	*file;

	cmd_len = 0;
	while (parser->cmd[cmd_len] != ' ' && parser->cmd[cmd_len] != '\0')
		cmd_len++;
	file_len = ft_strlen(parser->cmd) - (cmd_len + 1);
	tmp = ft_substr(parser->cmd, 0, cmd_len);
	file = ft_substr(parser->cmd, cmd_len + 1, file_len);
	free(parser->cmd);
	parser->cmd = tmp;
	unfold_main(parser, file);
	printf("%s, %s", parser->cmd, file);
	return (file);
}

void	execution_main(t_data *data)
{
	char	*file;
	size_t	len;

	len = count_listlen(data->parser);
	if (len)
	{
		data = init_pipe(data, len);
		pipe_main(data, data->parser, data->pipe->next, len);
		return ;
	}
	if (!check_headoc(data->parser->redirect))
	{
		redirect_main(data, data->parser);
		return ;
	}
	file = format_command(state->parser);
	unfold_main(state->parser, file);
	if (!judge_built_in(state, state->parser, file))
		fork_and_execve(state, state->exe, state->parser, file);
	free(file);
}

	// printf("%s, %s, %s\n", data->parser->cmd, data->parser->option, file);