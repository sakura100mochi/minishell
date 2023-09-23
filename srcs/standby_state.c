/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standby_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:36:44 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/23 16:14:07 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/built_in.h"

static t_init	*kari(t_init *state, char **command)
{
	t_parser	*parser;

	parser = (t_parser *)ft_calloc(sizeof(t_parser), 1);
	parser->option = "";
	if (command[1])
		parser->cmd = ft_strjoin("cd", command[1]);
	state->parser = parser;
	return (state);
}

static void	kari_free(t_parser *parser)
{
	free(parser);
}

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
		state->exe->command = lexer_main(state->prompt);
		state = kari(state, lexer_main(state->prompt));
		execution_main(state);
		free(state->prompt);
		kari_free(state->parser);
	}
	return ;
}
