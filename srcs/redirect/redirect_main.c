/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:09:45 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/13 14:55:24 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"
#include "../../includes/parser.h"
#include "../../includes/built_in.h"
#include "../../includes/error.h"

int	redirect_main(t_data *data, t_parser *node)
{
	while (node != NULL)
	{
		while (node->redirect != NULL)
		{
			if (node->redirect->type == UNKNOWN)
				return (NO);
			if (node->redirect->file_name == NULL)
				return (syntax(NULL));
			else if (node->redirect->type == QUOTE_HEREDOC)
				return (quote_heredoc(data, node->redirect));
			else if (node->redirect->type == HEREDOC)
				return (heredoc(data, node->redirect,
						node->redirect->file_name));
			else if (node->redirect->type == INPUT)
				return (input(node->redirect));
			else if (node->redirect->type == APPEND)
				return (append(node->redirect));
			else if (node->redirect->type == OUTPUT)
				return (output(node->redirect));
			node->redirect = node->redirect->next;
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
