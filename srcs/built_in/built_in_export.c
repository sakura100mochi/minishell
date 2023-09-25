/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:26:05 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/25 17:41:14 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static int	check_variable(char *variable)
{
	int		no_empty;
	size_t	index;
	size_t	flag;

	no_empty = 0;
	index = 0;
	while (variable[index] != '\0' && variable[index] != ' ' \
										&& variable[index] != '	')
		index++;
	while (variable[index] != '\0')
	{
		if (variable[index] == '=')
			flag = index;
		if (variable[flag + 1] != ' ' || variable[flag + 1] != '	')
			no_empty++;
		index++;
	}
	if (flag == 0)
		return (0);
	else if (variable[flag - 1] == ' ' || variable[flag - 1] == '	')
		return (0);
	return (1);
}

static void	export_no_command(t_exp *exp_variable)
{
	size_t	i;

	i = 0;
	exp_variable = exp_variable->next;
	while (!exp_variable->head)
	{
		ft_printf("%s\n", exp_variable->variable);
		exp_variable = exp_variable->next;
		i++;
	}
	return ;
}

static t_env	*input_env_variable(char *str, t_env *env_variable)
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
	return (head);
}

static t_exp	*input_exp_variable(char *str, t_exp *exp_variable, int flag)
{
	char	*tmp_str;
	char	*variable;
	t_exp	*head;
	t_exp	*new;

	tmp_str = NULL;
	head = exp_variable;
	exp_variable = exp_variable->prev;
	if (flag)
	{
		tmp_str = wrap_with_quotes(str);
		variable = ft_strjoin("declear -x ", tmp_str);
		free(tmp_str);
	}
	else
		variable = ft_strjoin("declear -x ", str);
	new = new_exp_node(variable, 0);
	head->prev = new;
	exp_variable->next = new;
	new->prev = exp_variable;
	new->next = head;
	return (head);
}

void	built_in_export(t_parser *parser, t_env *env_variable, \
									t_exp *exp_variable, char *str)
{
	if (parser->option)
	{
		ft_printf("minishell: export: %s: not a valid identifier\n", \
														parser->option);
		return ;
	}
	if (!*str)
		export_no_command(exp_variable);
	str = variable_fomet(str);
	if (!check_variable(str))
		ft_printf("minishell: export: '=': not a valid identifier\n");
	else if (check_variable(str))
	{
		exp_variable = input_exp_variable(str, exp_variable, 1);
		env_variable = input_env_variable(str, env_variable);
	}
	else
		exp_variable = input_exp_variable(str, exp_variable, 0);
	return ;
}
