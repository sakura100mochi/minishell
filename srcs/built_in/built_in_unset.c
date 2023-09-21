/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:10 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/21 12:25:07 by csakamot         ###   ########.fr       */
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
		rm_env_variable(exe_built, env_variable);
	}
	ft_printf("unset:Not yet implemented.\n");
	return ;
}
