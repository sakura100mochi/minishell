/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:09:30 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/30 14:56:29 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe.h"

static void	pipe_nodeadd_back(t_pipe **pipe, t_pipe *new)
{
	while ((*pipe)-> next)
		*pipe = ((*pipe)-> next);
	(*pipe)-> next = new;
	new -> prev = *pipe;
}

static t_pipe	*new_pipe_node(size_t head)
{
	t_pipe	*new;

	new = (t_pipe *)ft_calloc(1, sizeof(t_pipe));
	if (!new)
		return (NULL);
	if (head)
	{
		new->head = 1;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		pipe(new->pipe_fd);
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

t_init	*init_pipe(t_init *state, size_t len)
{
	size_t	index;
	t_pipe	*head;
	t_pipe	*new;
	t_pipe	*pipe;

	index = 0;
	pipe = new_pipe_node(1);
	head = pipe;
	while (index < len)
	{
		new = new_pipe_node(0);
		pipe_nodeadd_back(&pipe, new);
		index++;
	}
	head->prev = pipe->next;
	pipe->next->next = head;
	state->pipe = head;
	return (state);
}
