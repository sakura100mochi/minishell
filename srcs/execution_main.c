/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:08:20 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/28 13:27:41 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/built_in.h"
#include "../includes/pipe.h"

static size_t	count_listlen(t_parser *list)
{
	size_t	len;

	len = 0;
	while (list != NULL)
	{
		list = list->next;
		len++;
	}
	return (len);
}

static char	*format_command(t_parser *parser)
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
	return (file);
}

void	execution_main(t_init *state)
{
	char	*file;
	size_t	len;

	printf("ok!\n");
	len = count_listlen(state->parser);
	if (len > 1)
	{
		pipe_main(state, state->parser, len);
		return ;
	}
	file = format_command(state->parser);
	printf("%s, %s, %s\n", state->parser->cmd, state->parser->option, file);
	if (!judge_built_in(state, state->parser, file))
		external_command(state, state->exe, state->parser, file);
	free(file);
}
