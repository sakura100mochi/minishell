/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_main_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/10 15:13:43 by csakamot         ###   ########.fr       */
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

static char	*only_option(t_parser *parser, char *tmp)
{
	if (tmp && !*tmp && parser->option)
	{
		free(tmp);
		tmp = ft_strdup(parser->option);
	}
	if (!tmp)
		exit_malloc_error();
	return (tmp);
}

static char	*judge_blank_space(char *cmd)
{
	size_t	index;
	char	*result;

	index = 0;
	while (cmd[index] != '\0' && (cmd[index] == ' ' || cmd[index] == '	'))
		index++;
	result = ft_substr(cmd, index, ft_strlen(cmd));
	free(cmd);
	if (!result)
		exit_malloc_error();
	return (result);
}

char	*format_command(t_parser *parser)
{
	size_t	cmd_len;
	size_t	file_len;
	char	*tmp;
	char	*file;

	if (parser->cmd == NULL)
		return (NULL);
	parser->cmd = judge_blank_space(parser->cmd);
	cmd_len = check_quote_in_command(parser->cmd);
	file_len = ft_strlen(parser->cmd) - (cmd_len + 1);
	tmp = ft_substr(parser->cmd, 0, cmd_len);
	tmp = only_option(parser, tmp);
	while (parser->cmd[cmd_len] == ' ' || parser->cmd[cmd_len] == '	')
		cmd_len++;
	file = ft_substr(parser->cmd, cmd_len, file_len);
	if (!file)
		exit_malloc_error();
	free(parser->cmd);
	parser->cmd = tmp;
	return (file);
}
