/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standby_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:36:44 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/19 19:15:08 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// static t_parser	*kari(char **command)
// {
// 	t_parser	*parser;

// 	return (parser);
// }

void	standby_state(t_init *state)
{
	// t_parser	*parser;

	while (1)
	{
		state->prompt = readline("minishell$");
		add_history(state->prompt);
		if (!*(state)->prompt)
		{
			free(state->prompt);
			continue ;
		}
		state->exe->command = lexer_main(state->prompt);
		// parser = kari(lexer_main(state->prompt));
		if (judge_built_in(state, state->exe->command))
			external_command(state, state->exe);
		free(state->prompt);
	}
	return ;
}
