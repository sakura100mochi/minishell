/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:02:09 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/11/12 18:31:33 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/error.h"

t_parser	*parser_malloc_error(t_parser *node)
{
	write(STDOUT_FILENO, "malloc_error\n", 13);
	parser_free(node);
	exit(EXIT_FAILURE);
	return (NULL);
}

char	*char_malloc_error(t_parser *node)
{
	write(STDOUT_FILENO, "malloc_error\n", 13);
	parser_free(node);
	exit(EXIT_FAILURE);
	return (NULL);
}

char	**onephrase_malloc_error(char **one_phrase, t_parser *node)
{
	size_t	i;

	i = 0;
	write(STDOUT_FILENO, "malloc_error\n", 13);
	parser_free(node);
	while (one_phrase[i] != NULL)
	{
		free(one_phrase[i]);
		i++;
	}
	if (one_phrase != NULL)
		free(one_phrase);
	exit(EXIT_FAILURE);
	return (NULL);
}

int	int_malloc_error(t_parser *node)
{
	write(STDOUT_FILENO, "malloc_error\n", 13);
	parser_free(node);
	exit(EXIT_FAILURE);
	return (NO);
}
