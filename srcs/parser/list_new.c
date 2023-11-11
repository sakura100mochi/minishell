/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:53:36 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/11/10 17:02:55 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"
#include "../../includes/error.h"

t_parser	*ft_parsernew(char *all, char *cmd, char *option, t_file *redirect)
{
	t_parser	*node;

	node = (t_parser *)malloc(sizeof(t_parser));
	if (node == NULL)
		return (NULL);
	node->all = all;
	node->cmd = cmd;
	node->option = option;
	node->redirect = redirect;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static char	*set_file_name(char *one_phrase, t_parser *node)
{
	size_t	index;
	size_t	start;
	size_t	flag;
	char	*result;

	index = 0;
	start = 0;
	flag = 0;
	while (one_phrase[index] != '\0')
	{
		if (!flag && (one_phrase[index] != ' ' && one_phrase[index] != '	'))
		{
			flag = 1;
			start = index;
		}
		else if (flag && (one_phrase[index] == ' ' \
					|| one_phrase[index] == '	'))
			break ;
		index++;
	}
	result = ft_substr(one_phrase, start, index - 1);
	if (!result)
		char_malloc_error(node);
	return (result);
}

t_file	*ft_filenew(char **one_phrase, t_parser *node)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (file == NULL)
		return (NULL);
	file->type = file_type(one_phrase);
	if ((file->type == INPUT || file->type == OUTPUT) && one_phrase[1] != NULL)
		file->file_name = set_file_name(one_phrase[1], node);
	else if (one_phrase[1] != NULL && one_phrase[2] != NULL)
		file->file_name = set_file_name(one_phrase[2], node);
	else
		file->file_name = NULL;
	file->next = NULL;
	return (file);
}

int	quote_check(char *str)
{
	size_t	i;
	size_t	count_single;
	size_t	count_double;

	i = 0;
	count_single = 0;
	count_double = 0;
	if (str == NULL)
		return (NO);
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
			count_single++;
		else if (str[i] == '\"')
			count_double++;
		i++;
	}
	if ((count_double != 2 && count_double != 0)
		|| (count_single != 2 && count_single != 0))
		return (2);
	if (count_double == 2 || count_single == 2)
		return (YES);
	return (NO);
}

t_r_type	file_type(char **one_phrase)
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
		return (Q_H);
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
