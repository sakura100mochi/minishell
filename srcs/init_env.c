/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:28:21 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/18 15:47:55 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	nodeadd_back(t_env **env, t_env *new)
{
	while ((*env)-> next)
		*env = ((*env)-> next);
	(*env)-> next = new;
	new -> prev = *env;
}

t_env	*new_node(char *content, size_t index)
{
	t_env	*new;

	new = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new)
		return (NULL);
	if (!index)
		new -> head = 1;
	new -> variable = content;
	new -> next = NULL;
	new -> prev = NULL;
	return (new);
}

t_init	*init_env(t_init *state)
{
	size_t		index;
	t_env		*env_variable;
	t_env		*start;
	t_env		*new;
	extern char	**environ;

	index = 0;
	while (environ[index])
	{
		if (!index)
		{
			env_variable = new_node(environ[index], index);
			start = env_variable;
			index++;
		}
		new = new_node(environ[index], index);
		nodeadd_back(&env_variable, new);
		index++;
	}
	start->prev = env_variable->next;
	env_variable->next->next = start;
	state->env = start;
	return (state);
}