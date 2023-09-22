/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:10 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/21 13:23:03 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static t_env	*rm_env_variable(t_exe *exe_built, t_env *env_variable)
{
	size_t	len;
	char	*tmp_str;
	t_env	*head;
	t_env	*current_location;

	head = env_variable;
	len = ft_strlen(exe_built->command[1]);
	tmp_str = ft_strjoin(exe_built->command[1], "=");
	env_variable = env_variable->next;
	while (!env_variable->head)
	{
		if (!ft_strncmp(env_variable->variable, tmp_str, len + 1))
		{
			free(env_variable->variable);
			current_location = env_variable;
			env_variable = env_variable->next;
			current_location->prev->next = env_variable;
			env_variable->prev = current_location->prev;
			free(current_location);
			continue ;
		}
		env_variable = env_variable->next;
	}
	free(tmp_str);
	return (head);
}

static char	*exp_variable_format(t_exe *exe_built)
{
	char	*tmp_str;
	char	*result;

	tmp_str = ft_strjoin("declare -x ", exe_built->command[1]);
	result = ft_strjoin(tmp_str, "=");
	free(tmp_str);
	return (result);
}

static t_exp	*rm_exp_variable(t_exe *exe_built, t_exp *exp_variable)
{
	size_t	len;
	char	*tmp_str;
	t_exp	*head;
	t_exp	*current_location;

	head = exp_variable;
	len = ft_strlen(exe_built->command[1]);
	tmp_str = exp_variable_format(exe_built);
	exp_variable = exp_variable->next;
	while (!exp_variable->head)
	{
		if (!ft_strncmp(exp_variable->variable, tmp_str, len + 11))
		{
			free(exp_variable->variable);
			current_location = exp_variable;
			exp_variable = exp_variable->next;
			current_location->prev->next = exp_variable;
			exp_variable->prev = current_location->prev;
			free(current_location);
			continue ;
		}
		exp_variable = exp_variable->next;
	}
	free(tmp_str);
	return (head);
}

static t_exp	*rm_exp_str(t_exe *exe_built, t_exp *exp_variable)
{
	size_t	len;
	char	*tmp_str;
	t_exp	*head;
	t_exp	*current_location;

	head = exp_variable;
	len = ft_strlen(exe_built->command[1]);
	tmp_str = ft_strjoin("declare -x ", exe_built->command[1]);
	exp_variable = exp_variable->next;
	while (!exp_variable->head)
	{
		if (!ft_strncmp(exp_variable->variable, tmp_str, len + 11))
		{
			free(exp_variable->variable);
			current_location = exp_variable;
			exp_variable = exp_variable->next;
			current_location->prev->next = exp_variable;
			exp_variable->prev = current_location->prev;
			free(current_location);
			continue ;
		}
		exp_variable = exp_variable->next;
	}
	free(tmp_str);
	return (head);
}

void	built_in_unset(t_exe *exe_built, t_env *env_variable, \
											t_exp *exp_variable)
{
	(void)exp_variable;
	if (!exe_built->command[1])
		return ;
	else
	{
		env_variable = rm_env_variable(exe_built, env_variable);
		exp_variable = rm_exp_variable(exe_built, exp_variable);
		exp_variable = rm_exp_str(exe_built, exp_variable);
	}
	ft_printf("unset:Not yet implemented.\n");
	return ;
}
