/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:18:37 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/23 19:34:11 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

int	judge_built_in(t_init *state, t_parser *parser, char *file)
{
	size_t	len;

	len = ft_strlen(parser->cmd);
	if (len == 2 && !ft_strncmp(parser->cmd, "cd", len))
		state->env = built_in_cd(state->env, state->parser, file);
	else if (len == 4 && !ft_strncmp(parser->cmd, "echo", len))
		built_in_echo(state, state->parser);
	else if (len == 3 && !ft_strncmp(parser->cmd, "env", len))
		built_in_env(state, state->env);
	else if (len == 4 && !ft_strncmp(parser->cmd, "exit", len))
		built_in_exit(state);
	else if (len == 6 && !ft_strncmp(parser->cmd, "export", len))
		built_in_export(state->exe, state->env, state->exp);
	else if (len == 3 && !ft_strncmp(parser->cmd, "pwd", len))
		built_in_pwd();
	else if (len == 5 && !ft_strncmp(parser->cmd, "unset", len))
		built_in_unset(state->exe, state->env, state->exp);
	else
		return (1);
	double_array_free(state->exe->command);
	return (0);
}
