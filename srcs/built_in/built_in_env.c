/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:17 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/24 21:45:38 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	built_in_env(t_init *state, t_env *env_variable, t_parser *parser)
{
	// size_t		i;

	(void)state;
	(void)parser;
	// i = 0;
	env_variable = env_variable->next;
	while (!env_variable->head)
	{
		ft_printf("%s\n", env_variable->variable);
		env_variable = env_variable->next;
		// i++;
	}
	return ;
}
