/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfold_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:16:53 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/30 20:11:58 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/unfold.h"

static char	*unfold_variable(t_env *env, char *str)
{
	char	*variable;

	variable = get_variable(str);
	return (NULL);
}

static int	find_env_variable(char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '$')
			return (0);
		index++;
	}
	return (1);
}

int	unfold_main(t_env *env, t_parser *parser, char *file)
{
	(void)parser;
	(void)file;
	(void)file;
	if (!find_env_variable(parser->cmd))
	{
		unfold_variable(env, *parser->cmd);
		return ;
	}
	else if (!find_env_variable(file))
		unfold_variable(env, file);
	return (0);
}
