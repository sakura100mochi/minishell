/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:22:32 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/21 09:52:48 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	double_array_free(char **array)
{
	size_t	index;

	index = 0;
	while (array[index] != NULL)
	{
		free(array[index]);
		index++;
	}
	free(array);
	return ;
}

void	delete_all_env_node(t_env *env_variable)
{
	t_env	*start;
	t_env	*current_location;

	start = env_variable;
	if (env_variable -> next == env_variable)
	{
		free(env_variable);
		return ;
	}
	env_variable = env_variable -> next;
	while (!(env_variable -> head))
	{
		free(env_variable->variable);
		current_location = env_variable;
		env_variable = (env_variable -> next);
		free(current_location);
	}
	free(start);
	return ;
}

void	delete_all_exp_node(t_exp *exp_variable)
{
	t_exp	*start;
	t_exp	*current_location;

	start = exp_variable;
	if (exp_variable -> next == exp_variable)
	{
		free(exp_variable);
		return ;
	}
	exp_variable = exp_variable -> next;
	while (!(exp_variable -> head))
	{
		free(exp_variable->variable);
		current_location = exp_variable;
		exp_variable = (exp_variable -> next);
		free(current_location);
	}
	free(start);
	return ;
}