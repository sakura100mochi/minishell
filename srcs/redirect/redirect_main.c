/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:09:45 by yhirai            #+#    #+#             */
/*   Updated: 2023/11/17 23:19:54 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"
#include "../../includes/parser.h"
#include "../../includes/built_in.h"
#include "../../includes/error.h"

static int	devide(t_data *data, t_file *file)
{
	if (file->type == Q_H && quote_heredoc(data, file) == NO)
		return (NO);
	else if (file->type == HEREDOC
		&& heredoc(data, file, file->file_name) == NO)
		return (NO);
	else if (file->type == INPUT && input(data, file) == NO)
		return (NO);
	else if (file->type == APPEND && append(data, file) == NO)
		return (NO);
	else if (file->type == OUTPUT && output(data, file) == NO)
		return (NO);
	return (YES);
}

static int	syntax_check_redirect(t_data *data, t_parser *node)
{
	t_file	*file;

	while (node != NULL)
	{
		file = node->redirect;
		while (file != NULL)
		{
			if (file->type == UNKNOWN || file->file_name == NULL
				|| file->file_name[0] == '<' || file->file_name[0] == '>')
				return (syntax(data));
			file = file->next;
		}
		node = node->next;
	}
	return (YES);
}

int	redirect_main(t_data *data, t_parser *node)
{
	t_file	*file;

	if (syntax_check_redirect(data, node) == NO)
		return (NO);
	while (node != NULL)
	{
		file = node->redirect;
		while (file != NULL)
		{
			if (devide(data, file) == NO)
				return (NO);
			file = file->next;
		}
		node = node->next;
	}
	return (YES);
}

// static char	**ft_free(char **result, t_parser *node)
// {
// 	size_t		i;
// 	t_parser	*tmp_node;
// 	t_file		*file;
// 	t_file		*tmp_file;

// 	i = 0;
// 	while (result[i] != NULL)
// 	{
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	while (node != NULL)
// 	{
// 		file = node->redirect;
// 		while (file != NULL)
// 		{
// 			tmp_file = file->next;
// 			free(file->file_name);
// 			free(file);
// 			file = tmp_file;
// 		}
// 		tmp_node = node->next;
// 		free(node->cmd);
// 		free(node->option);
// 		free(node);
// 		node = tmp_node;
// 	}
// 	return (NULL);
// }

// int	main(void)
// {
// 	t_parser	*node;
// 	t_parser	*head;
// 	char		**result;
// 	char		*str = "cat << a << \"b\" > a > b";

// 	result = lexer_main(str);
// 	node = parser_main(lexer_main(str));
// 	head = node;
// 	redirect_main(node);
// 	ft_free(result, head);
// 	return (0);
// }
