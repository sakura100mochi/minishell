/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_main_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/05 19:28:55 by csakamot         ###   ########.fr       */
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

char	*format_command(t_parser *parser)
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
	return (file);
}
