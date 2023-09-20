/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseradd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:58:27 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/09/20 14:18:04 by hiraiyuina       ###   ########.fr       */
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
	printf("corect _____command|%s\n", new->cmd);
	printf("corect _____option|%s\n", new->option);
	printf("#####command|%s\n", last->cmd);
	printf("#####option|%s\n", last->option);
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
