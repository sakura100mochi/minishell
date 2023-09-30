/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:28:21 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/30 17:41:22 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	start = env_variable;
	while (environ[index])
	{
		new = new_env_node(ft_strdup(environ[index]), 0);
		env_nodeadd_back(&env_variable, new);
		index++;
	}
	start->prev = env_variable->next;
	env_variable->next->next = start;
	data->env = start;
	return (data);
}
