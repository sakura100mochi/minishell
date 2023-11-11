/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:09:45 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/23 20:28:00 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"
#include "../../includes/parser.h"
#include "../../includes/built_in.h"
#include "../../includes/error.h"

int	redirect_main(t_data *data, t_parser *node)
{
	t_file	*file;

	while (node != NULL)
	{
		file = node->redirect;
		while (file != NULL)
		{
			if (file->type == UNKNOWN || file->file_name == NULL)
				return (syntax(data));
			else if (file->type == Q_H)
				quote_heredoc(data, file);
			else if (file->type == HEREDOC)
				heredoc(data, file, file->file_name);
			else if (file->type == INPUT && input(data, file) == NO)
				return (NO);
			else if (file->type == APPEND)
				append(data, file);
			else if (file->type == OUTPUT)
				output(data, file);
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
