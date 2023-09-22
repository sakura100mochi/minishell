/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:53:36 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/09/22 18:17:36 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_parser	*ft_parsernew(char *cmd, char *option, t_file *redirect)
{
	t_parser	*node;

	node = (t_parser *)malloc(sizeof(t_parser));
	if (node == NULL)
		return (parser_malloc_error());
	node->cmd = cmd;
	node->option = option;
	node->redirect = redirect;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_file	*ft_filenew(char **one_phrase)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (file == NULL)
		return (file_malloc_error());
	if (one_phrase[0][0] == '<' && one_phrase[1][0] == '<')
		file->type = HEREDOC;
	else if (one_phrase[0][0] == '<')
		file->type = INPUT;
	else if (one_phrase[0][0] == '>' && one_phrase[1][0] == '>')
		file->type = APPEND;
	else if (one_phrase[0][0] == '>')
		file->type = OUTPUT;
	else
		file->type = UNKNOWN;
	if (file->type == INPUT || file->type == OUTPUT)
		file->file_name = ft_strjoin_minis(NULL, one_phrase[1]);
	else
		file->file_name = ft_strjoin_minis(NULL, one_phrase[2]);
	file->next = NULL;
	return (file);
}
