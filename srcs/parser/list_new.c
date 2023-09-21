/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsernew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:53:36 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/09/21 14:31:29 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_parser	*ft_parsernew(char *cmd, char *option, char *str, t_file *redirect)
{
	t_parser	*node;

	node = (t_parser *)malloc(sizeof(t_parser));
	if (node == NULL)
		return (NULL);
	node->cmd = cmd;
	node->option = option;
	node->str = str;
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
		return (NULL);
	if (one_phrase[0][0] == '<' && one_phrase[1][0] == '\0')
		file->type = UNKNOWN;
	else if (one_phrase[0][0] == '<' && one_phrase[1][0] == '<')
		file->type = APPEND;
	else if (one_phrase[0][0] == '>')
		file->type = INPUT;
	file->file_name = one_phrase[1];
	file->next = NULL;
	return (file);
}
