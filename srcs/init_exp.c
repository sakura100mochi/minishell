/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:37:18 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/30 17:41:22 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*exp_variable_format(char *variable)
{
	int			flag;
	size_t		i;
	size_t		len;
	char		*tmp_str;
	char		*result;

	flag = 0;
	i = 0;
	len = ft_strlen(variable) + 2;
	tmp_str = (char *)ft_calloc(sizeof(char), (len + 1));
	while (i++ < len - 1)
	{
		if (!flag && i - 1 > 0 && tmp_str[i - 2] == '=')
		{
			tmp_str[i - 1] = '"';
			flag++;
		}
		else
			tmp_str[i - 1] = variable[i - 1 - flag];
	}
	tmp_str[i - 1] = '"';
	tmp_str[i] = '\0';
	result = ft_strjoin("declare -x ", tmp_str);
	free(tmp_str);
	return (result);
}

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

t_data	*init_exp(t_data *data)
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
		new = new_exp_node(exp_variable_format(environ[index]), 0);
		exp_nodeadd_back(&exp_variable, new);
		index++;
	}
	start->prev = exp_variable->next;
	exp_variable->next->next = start;
	data->exp = start;
	return (data);
}
