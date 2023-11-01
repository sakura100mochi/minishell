/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/29 18:04:54 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/pipe.h"
#include "../../includes/error.h"

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
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

t_pipe	*init_pipe(t_data *data, size_t len)
{
	size_t	index;
	t_pipe	*head;
	t_pipe	*new;
	t_pipe	*pipelist;

	(void)data;
	index = 0;
	pipelist = new_pipe_node(1);
	head = pipelist;
	while (index < len)
	{
		new = new_pipe_node(0);
		if (new == NULL)
			break ;
		pipe_nodeadd_back(&pipelist, new);
		index++;
	}
	head->prev = pipelist->next;
	pipelist->next->next = head;
	return (head);
}
