/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:28:21 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/28 11:59:59 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/error.h"

void	env_nodeadd_back(t_env **env, t_env *new)
{
	while ((*env)-> next)
		*env = ((*env)-> next);
	(*env)-> next = new;
	new -> prev = *env;
}

t_env	*new_env_node(char *content, size_t head)
{
	t_env	*new;

	new = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new)
		return (NULL);
	if (head)
		new->head = 1;
	new->variable = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_data	*init_env(t_data *data)
{
	size_t		index;
	t_env		*env_variable;
	t_env		*start;
	t_env		*new;
	extern char	**environ;

	index = 0;
	env_variable = new_env_node("head", 1);
	if (!env_variable)
		exit_malloc_error();
	start = env_variable;
	while (environ[index + 1])
	{
		new = new_env_node(ft_strdup(environ[index]), 0);
		if (!new)
			exit_malloc_error();
		env_nodeadd_back(&env_variable, new);
		index++;
	}
	start->prev = env_variable->next;
	env_variable->next->next = start;
	data->env = start;
	return (data);
}
