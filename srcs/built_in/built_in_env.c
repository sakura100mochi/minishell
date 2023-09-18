/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:17 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/18 15:50:07 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/built_in.h"

void	built_in_env(t_init *state, t_env *env_variable)
{
	size_t		i;

	(void)state;
	i = 0;
	printf("%s", env_variable->variable);
	env_variable = env_variable->next;
	while (!env_variable->head)
	{
		printf("%s\n", env_variable->variable);
		env_variable = env_variable->next;
		i++;
	}
	return ;
}
