/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:28:21 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/29 04:09:02 by csakamot         ###   ########.fr       */
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

static void	judge_env_pointer(t_env *start, t_env *env, size_t index)
{
	if (!index)
	{
		start->prev = env;
		start->next = env;
	}
	else
	{
		start->prev = env->next;
		env->next->next = start;
	}
	return ;
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
	while (environ[index])
	{
		if (!environ[index + 1])
			break ;
		new = new_env_node(ft_strdup(environ[index]), 0);
		if (!new)
			exit_malloc_error();
		env_nodeadd_back(&env_variable, new);
		index++;
	}
	judge_env_pointer(start, env_variable, index);
	data->env = start;
	return (data);
}
