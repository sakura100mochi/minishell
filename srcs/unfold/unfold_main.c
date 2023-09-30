/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfold_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:16:53 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/30 18:48:36 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/unfold.h"

static int	find_env_variable(char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != NULL)
	{
		index++;
	}
	return (1);
}

int	unfold_main(t_parser *parser, char *file)
{
	(void)parser;
	(void)file;
	if (!find_env_variable(parser->cmd))
	{
		return ;
	}
	return (0);
}
