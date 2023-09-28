/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:09:30 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/28 18:19:06 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe.h"

static t_pipe	*new_pipe_node(size_t head)
{
	t_pipe	*new;

	new = (t_pipe *)ft_calloc(1, sizeof(t_pipe));
	if (!new)
		return (NULL);
	if (head)
		new -> head = 1;
	new -> next = NULL;
	new -> prev = NULL;
	return (new);
}

t_pipe	*init_pipe(size_t len)
{
	size_t	index;
	t_pipe	*head;
	t_pipe	*pipe;

	index = 0;
	pipe = new_pipe_node(1);
	head = pipe;
	while (index < len)
	{
		index++;
	}
	return (head);
}
