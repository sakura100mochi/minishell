/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/30 12:18:18 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/pipe.h"
#include "../../includes/error.h"

void	pipe_free(t_pipe *pipelist)
{
	t_pipe	*head;
	t_pipe	*tmp;

	head = pipelist;
	tmp = NULL;
	pipelist = pipelist->next;
	while (!pipelist->head)
	{
		tmp = pipelist;
		if (pipelist->file)
			free(pipelist->file);
		if (pipelist->array)
			double_array_free(pipelist->array);
		pipelist = pipelist->next;
		free(tmp);
	}
	free(head->file);
	double_array_free(head->array);
	free (head);
	return ;
}
