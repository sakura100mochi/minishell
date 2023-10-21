/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:53:36 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/10/21 05:27:39 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"

t_parser	*ft_parsernew(char *cmd, char *option, t_file *redirect)
{
	t_parser	*node;

	node = (t_parser *)malloc(sizeof(t_parser));
	if (node == NULL)
		return (NULL);
	node->cmd = cmd;
	node->option = option;
	node->redirect = redirect;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_file	*ft_filenew(char **one_phrase, t_parser *node)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (file == NULL)
		return (NULL);
	file->type = file_type(one_phrase);
	if ((file->type == INPUT || file->type == OUTPUT) && one_phrase[1] != NULL)
		file->file_name = ft_strjoin_minis(NULL, one_phrase[1], node);
	else if (one_phrase[1] != NULL && one_phrase[2] != NULL)
		file->file_name = ft_strjoin_minis(NULL, one_phrase[2], node);
	else
		file->file_name = NULL;
	file->next = NULL;
	return (file);
}

static int	quote_check(char *str)
{
	size_t	i;
	size_t	count_single;
	size_t	count_double;

	i = 0;
	count_single = 0;
	count_double = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
			count_single++;
		else if (str[i] == '\"')
			count_double++;
		i++;
	}
	if (count_double == 2 || count_single == 2)
		return (YES);
	return (NO);
}

t_redirect_type	file_type(char **one_phrase)
{
	size_t	i;

	i = 0;
	while (one_phrase[i] != NULL && \
		(one_phrase[i][0] == '<' || one_phrase[i][0] == '>'))
		i++;
	if (i >= 3)
		return (UNKNOWN);
	else if (one_phrase[0] != NULL && one_phrase[0][0] == '<' &&
			one_phrase[1] != NULL && one_phrase[1][0] == '<' &&
			one_phrase[2] != NULL && quote_check(one_phrase[2]) == YES)
		return (QUOTE_HEREDOC);
	else if (one_phrase[0] != NULL && one_phrase[0][0] == '<' &&
				one_phrase[1] != NULL && one_phrase[1][0] == '<')
		return (HEREDOC);
	else if (one_phrase[0][0] == '<')
		return (INPUT);
	else if (one_phrase[0] != NULL && one_phrase[0][0] == '>' &&
				one_phrase[1] != NULL && one_phrase[1][0] == '>')
		return (APPEND);
	else if (one_phrase[0][0] == '>')
		return (OUTPUT);
	return (UNKNOWN);
}
