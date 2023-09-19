/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:26:05 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/18 20:33:43 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

t_env	*built_in_export(t_exe *exe_built, t_env *env_variable)
{
	size_t	i;
	char	*str;
	t_env	*start;
	t_env	*new;

	i = 0;
	start = env_variable;
	env_variable = env_variable->prev;
	str = ft_strdup(exe_built->command[1]);
	new = new_node(str, 1);
	start->prev = new;
	env_variable->next = new;
	new->prev = env_variable;
	new->next = start;
	return (start);
}
