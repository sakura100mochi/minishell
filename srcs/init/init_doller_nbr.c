/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doller_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/21 19:44:42 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	dolnbr_nodeadd_back(t_dolnbr **env, t_dolnbr *new)
{
	while ((*env)-> next)
		*env = ((*env)-> next);
	(*env)-> next = new;
	new -> prev = *env;
}

t_dolnbr	*new_dolnbr_node(char *content, size_t head)
{
	t_dolnbr	*new;

	new = (t_dolnbr *)ft_calloc(1, sizeof(t_env));
	if (!new)
		return (NULL);
	if (head)
		new->head = 1;
	new->variable = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
