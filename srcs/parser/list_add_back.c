/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:58:27 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/09/21 15:00:34 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	t_parser	*head;
	size_t		size;

	size = 0;
	head = node;
	while (head != NULL)
	{
		head = head->next;
		size++;
	}
	while (size > 1)
	{
		node = node->next;
		size--;
	}
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
	t_file	*head;
	size_t	size;

	size = 0;
	head = file;
	while (head != NULL)
	{
		head = head->next;
		size++;
	}
	while (size > 1)
	{
		file = file->next;
		size--;
	}
	return (file);
}
