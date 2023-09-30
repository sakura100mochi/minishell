/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:58:27 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/09/30 17:25:13 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"

void	ft_parseradd_back(t_parser **node, t_parser *new)
{
	t_parser	*last;

	if (node == NULL || new == NULL)
		return ;
	if (*node == NULL)
		*node = new;
	else
	{
		last = ft_parserlast(*node);
		last->next = new;
		new->prev = last;
	}
}

t_parser	*ft_parserlast(t_parser *node)
{
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	ft_fileadd_back(t_file **file, t_file *new)
{
	t_file	*last;

	if (file == NULL || new == NULL)
		return ;
	if (*file == NULL)
		*file = new;
	else
	{
		last = ft_filelast(*file);
		last->next = new;
	}
}

t_file	*ft_filelast(t_file *file)
{
	while (file->next != NULL)
		file = file->next;
	return (file);
}
