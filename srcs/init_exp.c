/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:37:18 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/21 09:54:33 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exp_nodeadd_back(t_exp **env, t_exp *new)
{
	while ((*env)-> next)
		*env = ((*env)-> next);
	(*env)-> next = new;
	new -> prev = *env;
}

t_exp	*new_exp_node(char *content, size_t head)
{
	t_exp	*new;

	new = (t_exp *)ft_calloc(1, sizeof(t_exp));
	if (!new)
		return (NULL);
	if (head)
		new -> head = 1;
	new -> variable = content;
	new -> next = NULL;
	new -> prev = NULL;
	return (new);
}

t_init	*init_exp(t_init *state)
{
	size_t		index;
	t_exp		*exp_variable;
	t_exp		*start;
	t_exp		*new;
	extern char	**environ;

	index = 0;
	exp_variable = new_exp_node("head", 1);
	start = exp_variable;
	while (environ[index])
	{
		new = new_exp_node(ft_strjoin("dexlare -x ", environ[index]), 0);
		exp_nodeadd_back(&exp_variable, new);
		index++;
	}
	start->prev = exp_variable->next;
	exp_variable->next->next = start;
	state->exp = start;
	return (state);
}
