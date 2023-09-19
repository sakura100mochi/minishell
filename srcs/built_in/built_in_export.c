/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:26:05 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/20 01:33:35 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static void	export_no_command(t_env *env_variable)
{
	size_t		i;

	i = 0;
	env_variable = env_variable->next;
	while (!env_variable->head)
	{
		ft_printf("%s\n", env_variable->variable);
		env_variable = env_variable->next;
		i++;
	}
	return ;
}

static t_env	*input_env_variable(t_exe *exe_built, t_env *env_variable)
{
	char	*str;
	t_env	*start;
	t_env	*new;

	start = env_variable;
	env_variable = env_variable->prev;
	str = ft_strdup(exe_built->command[1]);
	new = new_node(str, 0);
	start->prev = new;
	env_variable->next = new;
	new->prev = env_variable;
	new->next = start;
	return (start);
}

static int	check_option(t_exe *exe_buit, t_env *env_variable)
{
	(void)exe_buit;
	(void)env_variable;
	return (1);
}

t_env	*built_in_export(t_exe *exe_built, t_env *env_variable)
{
	if (!exe_built->command[1])
		export_no_command(env_variable);
	else if (check_option(exe_built, env_variable))
	{
		env_variable = input_env_variable(exe_built, env_variable);
	}
	return (env_variable);
}
