/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:26:05 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/21 12:26:16 by csakamot         ###   ########.fr       */
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

static t_env	*input_env_variable(t_exe *exe_built, t_env *env_variable)
{
	char	*str;
	t_env	*head;
	t_env	*new;

	head = env_variable;
	env_variable = env_variable->prev;
	str = ft_strdup(exe_built->command[1]);
	new = new_env_node(str, 0);
	head->prev = new;
	env_variable->next = new;
	new->prev = env_variable;
	new->next = head;
	return (head);
}

static t_exp	*input_exp_variable(t_exe *exe_built, t_exp *exp_variable)
{
	char	*str;
	t_exp	*head;
	t_exp	*new;

	head = exp_variable;
	exp_variable = exp_variable->prev;
	str = ft_strdup(exe_built->command[1]);
	new = new_exp_node(str, 0);
	head->prev = new;
	exp_variable->next = new;
	new->prev = exp_variable;
	new->next = head;
	return (head);
}

static int	check_option(t_exe *exe_buit, t_env *env_variable)
{
	(void)exe_buit;
	(void)env_variable;
	return (1);
}

void	built_in_export(t_exe *exe_built, t_env *env_variable, \
												t_exp *exp_variable)
{
	if (!exe_built->command[1])
		export_no_command(exp_variable);
	else
		exp_variable = input_exp_variable(exe_built, exp_variable);
	if (exe_built->command[1] && check_option(exe_built, env_variable))
	{
		env_variable = input_env_variable(exe_built, env_variable);
	}
	return ;
}
