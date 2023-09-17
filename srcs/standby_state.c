/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standby_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:36:44 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/17 20:13:06 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	standby_state(t_init *state)
{
	while (1)
	{
		state->prompt = readline("minishell$");
		printf("%p, %p\n", state->exe, state->signal);
		add_history(state->prompt);
		if (!*(state)->prompt)
		{
			free(state->prompt);
			continue ;
		}
		state->exe->command = lexer_main(state->prompt);
		if (judge_built_in(state, state->exe->command))
			external_command(state, state->exe);
		printf("");
		free(state->prompt);
	}
	return ;
}
