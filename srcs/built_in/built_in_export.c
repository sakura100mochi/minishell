/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:26:05 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/24 05:14:30 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

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

static t_exp	*input_exp_variable(char *str, t_exp *exp_variable)
{
	char	*tmp_str;
	t_exp	*head;
	t_exp	*new;

	head = exp_variable;
	exp_variable = exp_variable->prev;
	tmp_str = ft_strdup(str);
	new = new_exp_node(tmp_str, 0);
	head->prev = new;
	exp_variable->next = new;
	new->prev = exp_variable;
	new->next = head;
	return (head);
}

void	built_in_export(t_parser *parser, t_env *env_variable, \
									t_exp *exp_variable, char *str)
{
	if (!*str)
		export_no_command(exp_variable);
	else
		exp_variable = input_exp_variable(str, exp_variable);
	if (str && !*(parser)->option)
	{
		env_variable = input_env_variable(str, env_variable);
	}
	return ;
}
