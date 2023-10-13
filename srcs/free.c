/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:29:12 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/13 14:20:09 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	parser_free(t_parser *node)
{
	t_parser	*tmp_node;
	t_file		*file;
	t_file		*tmp_file;

	while (node != NULL)
	{
		file = node->redirect;
		while (file != NULL)
		{
			tmp_file = file->next;
			if (file->file_name)
				free(file->file_name);
			if (file->result)
				free(file->result);
			free(file);
			file = tmp_file;
		}
		tmp_node = node->next;
		free(node->cmd);
		free(node->option);
		free(node);
		node = tmp_node;
	}
}

void	free_all(t_data *data)
{
	parser_free(data->parser);
	free(data->exe);
	free(data->signal);
	free(data);
}
