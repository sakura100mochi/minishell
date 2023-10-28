/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:37:18 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/28 12:00:05 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/error.h"

static void	variable_format_loop(const char *variable, \
									char *tmp_str, size_t len)
{
	size_t	i;
	size_t	flag;

	i = 0;
	flag = 0;
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
	return ;
}

static char	*exp_variable_format(const char *variable)
{
	size_t		len;
	char		*tmp_str;
	char		*result;

	len = ft_strlen(variable) + 2;
	tmp_str = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!tmp_str)
		exit_malloc_error();
	variable_format_loop(variable, tmp_str, len);
	result = ft_strjoin("declare -x ", tmp_str);
	if (!result)
		exit_malloc_error();
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
	if (!exp_variable)
		exit_malloc_error();
	start = exp_variable;
	while (environ[index + 1])
	{
		new = new_exp_node(exp_variable_format(environ[index]), 0);
		if (!new)
			exit_malloc_error();
		exp_nodeadd_back(&exp_variable, new);
		index++;
	}
	start->prev = exp_variable->next;
	exp_variable->next->next = start;
	data->exp = start;
	return (data);
}
