/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:29:12 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/21 15:54:34 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_all(t_data *data)
{
	parser_free(data->parser);
	delete_all_env_node(data->env);
	delete_all_exp_node(data->exp);
	free(data->exe);
	free(data->signal);
	free(data);
}

void	parser_free(t_parser *node)
{
	t_parser	*tmp_node;
	t_file		*file;
	t_file		*tmp_file;

	while (node != NULL)
	{
		file = node->redirect;
		while (file != NULL)
		{
			tmp_file = file->next;
			if (file->file_name != NULL)
				free(file->file_name);
			free(file);
			file = tmp_file;
		}
		tmp_node = node->next;
		free(node->all);
		free(node->cmd);
		free(node->option);
		free(node);
		node = tmp_node;
	}
}

void	double_array_free(char **array)
{
	size_t	index;

	index = 0;
	if (array != NULL)
	{
		while (array[index] != NULL)
		{
			free(array[index]);
			index++;
		}
		free(array);
	}
	return ;
}

void	delete_all_env_node(t_env *env_variable)
{
	t_env	*start;
	t_env	*current_location;

	start = env_variable;
	if (env_variable != NULL)
	{
		if (env_variable -> next == env_variable)
		{
			free(env_variable);
			return ;
		}
		env_variable = env_variable -> next;
		while (!(env_variable -> head))
		{
			if (env_variable != NULL)
				free(env_variable->variable);
			current_location = env_variable;
			env_variable = (env_variable -> next);
			free(current_location);
		}
		free(start);
	}
	return ;
}

void	delete_all_exp_node(t_exp *exp_variable)
{
	t_exp	*start;
	t_exp	*current_location;

	start = exp_variable;
	if (exp_variable != NULL)
	{
		if (exp_variable -> next == exp_variable)
		{
			free(exp_variable);
			return ;
		}
		exp_variable = exp_variable -> next;
		while (!(exp_variable -> head))
		{
			if (exp_variable != NULL)
				free(exp_variable->variable);
			current_location = exp_variable;
			exp_variable = (exp_variable -> next);
			free(current_location);
		}
		free(start);
	}
	return ;
}
