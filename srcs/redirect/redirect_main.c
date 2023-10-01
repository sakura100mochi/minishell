/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:09:45 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/01 16:15:32 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"
#include "../../includes/parser.h"
#include "../../includes/built_in.h"

void	redirect_main(t_parser *node)
{
	t_file	*file;

	while (node != NULL)
	{
		file = node->redirect;
		while (file != NULL)
		{
			if (file->type == UNKNOWN)
				return ;
			if (file->file_name == NULL)
				return (syntax(NULL));
			else if (file->type == QUOTE_HEREDOC)
				quote_heredoc(file);
			else if (file->type == HEREDOC)
				heredoc(file, file->file_name);
			else if (file->type == INPUT)
				input(file);
			else if (file->type == APPEND)
				append(file);
			else if (file->type == OUTPUT)
				output(file);
			file = file->next;
		}
		node = node->next;
	}
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
