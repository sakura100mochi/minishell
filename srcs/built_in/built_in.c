/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:18:37 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/28 16:45:42 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"
#include "../../includes/error.h"

int	judge_built_in(t_data *data, t_parser *parser, char *file, char **array)
{
	size_t	len;

	(void)array;
	len = ft_strlen(parser->cmd);
	if (len == 2 && !ft_strncmp(parser->cmd, "cd", len))
		data->env = built_in_cd(data->env, data->parser, array);
	else if (len == 4 && !ft_strncmp(parser->cmd, "echo", len))
		built_in_echo(data->env, data->parser, file);
	else if (len == 3 && !ft_strncmp(parser->cmd, "env", len))
		built_in_env(data->env, data->parser, file);
	else if (len == 4 && !ft_strncmp(parser->cmd, "exit", len))
		built_in_exit(data->env, parser, array);
	else if (len == 6 && !ft_strncmp(parser->cmd, "export", len))
		built_in_export(data->parser, data->env, data->exp, array);
	else if (len == 3 && !ft_strncmp(parser->cmd, "pwd", len))
		built_in_pwd(data->env, parser);
	else if (len == 5 && !ft_strncmp(parser->cmd, "unset", len))
		built_in_unset(data->parser, data->env, data->exp, array);
	else
		return (NO);
	return (YES);
}
