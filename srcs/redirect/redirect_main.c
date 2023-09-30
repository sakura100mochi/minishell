/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:09:45 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/30 14:31:05 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	redirect_main(t_parser *node)
{
	t_file	*file;

	file = node->redirect;
	if (file == NULL || file->type == UNKNOWN)
		return ;
	if (file->file_name == NULL)
		syntax();
	else if (file->type == QUOTE_HEREDOC)
		quote_heredoc(node, file);
	else if (file->type == HEREDOC)
		heredoc(node, file);
	else if (file->type == INPUT)
		input(node, file);
	else if (file->type == APPEND)
		append(node, file);
	else if (file->type == OUTPUT)
		output(node, file);
}

static char	**ft_free(char **result, t_parser *node)
{
	size_t		i;
	t_parser	*tmp_node;
	t_file		*file;
	t_file		*tmp_file;

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	while (node != NULL)
	{
		file = node->redirect;
		while (file != NULL)
		{
			tmp_file = file->next;
			free(file->file_name);
			free(file);
			file = tmp_file;
		}
		tmp_node = node->next;
		free(node->cmd);
		free(node->option);
		free(node);
		node = tmp_node;
	}
	return (NULL);
}

int	main(void)
{
	t_parser	*node;
	t_parser	*head;
	char		**result;
	char		*str = "echo > a";

	result = lexer_main(str);
	node = parser_main(lexer_main(str));
	head = node;
	redirect_main(node);
	ft_free(result, head);
	return (0);
}
