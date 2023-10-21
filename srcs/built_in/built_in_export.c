/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:26:05 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/21 09:37:23 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static int	check_equal(char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '=')
			return (0);
		index++;
	}
	return (1);
}

static int	check_variable(t_env *env, char *variable)
{
	size_t	index;
	size_t	flag;

	index = 0;
	flag = 0;
	if (variable[index] == '=')
	{
		env->status = 1;
		return (0);
	}
	while (variable[index] != '\0')
	{
		if (variable[index] == '=')
			flag = index;
		index++;
	}
	if (variable[flag - 1] == ' ' || variable[flag - 1] == '	')
	{
		env->status = 1;
		return (0);
	}
	return (1);
}

void	export_no_command(t_exp *exp_variable)
{
	exp_variable = exp_variable->next;
	while (!exp_variable->head)
	{
		ft_printf("%s\n", exp_variable->variable);
		exp_variable = exp_variable->next;
	}
	return ;
}

t_env	*input_env_variable(char *str, t_env *env_variable)
{
	char	*tmp_str;
	t_env	*head;
	t_env	*new;

	head = env_variable;
	env_variable = env_variable->prev;
	tmp_str = ft_strdup(str);
	new = new_env_node(tmp_str, 0);
	head->prev = new;
	env_variable->next = new;
	new->prev = env_variable;
	new->next = head;
	head->status = 0;
	return (head);
}

void	built_in_export(t_parser *parser, t_env *env_variable, \
									t_exp *exp_variable, char *str)
{
	char	*variable;

	if (parser->option)
	{
		env_variable->status = 1;
		ft_printf("minishell: export: '%s': not a valid identifier\n", \
														parser->option);
		return ;
	}
	variable = variable_format(env_variable, str);
	if (!*str)
		export_no_command(exp_variable);
	else if (!*variable)
		ft_printf("minishell: export: enclose in quotation marks\n");
	else if (check_equal(str))
		exp_variable = input_exp_variable(str, env_variable, exp_variable, 0);
	else if (*variable && !check_variable(env_variable, variable))
		ft_printf("minishell: export: '=': not a valid identifier\n");
	else if (*variable && check_variable(env_variable, variable))
	{
		exp_variable = input_exp_variable(variable, env_variable, \
														exp_variable, 1);
		env_variable = input_env_variable(variable, env_variable);
	}
	free(variable);
}
