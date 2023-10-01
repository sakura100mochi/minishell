/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfold_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:16:53 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/01 13:15:13 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/unfold.h"

static char	*unfold_variable(t_env *env, char *str)
{
	char	*variable;

	variable = get_variable(str);
	return (NULL);
}

static size_t	find_env_variable(char *str)
{
	size_t	index;
	size_t	nbr;

	index = 0;
	nbr = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '$' && str[index + 1] != '\0')
		{
			nbr++;
			index++;
		}
		index++;
	}
	if (nbr)
		return (0);
	return (1);
}

int	unfold_main(t_env *env, t_parser *parser, char *file)
{
	char	**strage;
	size_t	len;

	len = find_env_variable(parser->cmd);
	if (!len)
	{
		strage = (char **)ft_calloc(sizeof(char *), len + 1);
		unfold_variable(env, *parser->cmd);
		return ;
	}
	else if (!find_env_variable(file))
		unfold_variable(env, file);
	return (0);
}
