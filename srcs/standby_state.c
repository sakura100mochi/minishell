/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standby_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:36:44 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/28 11:01:00 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/pipe.h"

void	standby_state(t_init *state)
{
	while (1)
	{
		state->prompt = readline("minishell$");
		add_history(state->prompt);
		if (!*(state)->prompt)
		{
			free(state->prompt);
			continue ;
		}
		else if (state->prompt == NULL)
		{
			printf("^D\n");
			continue ;
		}
		state->parser = parser_main(lexer_main(state->prompt));
		pipe_main(state, state->parser);
		free(state->prompt);
	}
	return ;
}
