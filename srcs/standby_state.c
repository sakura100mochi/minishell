/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standby_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:36:44 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/24 17:23:12 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/built_in.h"

// static t_init	*kari(t_init *state, char **command)
// {
// 	char		*tmp;
// 	t_parser	*parser;

// 	parser = (t_parser *)ft_calloc(sizeof(t_parser), 1);
// 	parser->option = "";
// 	if (command[1])
// 	{
// 		tmp = ft_strjoin(command[0], " ");
// 		parser->cmd = ft_strjoin(tmp, command[1]);
// 	}
// 	else
// 		parser->cmd = command[0];
// 	state->parser = parser;
// 	return (state);
// }

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
		execution_main(state);
		free(state->prompt);
	}
	return ;
}
