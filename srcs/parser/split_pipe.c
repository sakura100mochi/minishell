/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:07:28 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/10/13 14:34:36 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"
#include "../../includes/error.h"

static size_t	count_pointer(char **str)
{
	size_t	count;

	count = 0;
	while (str[count] != NULL && str[count][0] != '|')
		count++;
	return (count);
}

static char	**one_phrase_malloc(char **str, size_t *len, t_parser *node)
{
	char	**one_phrase;
	size_t	i;
	size_t	j;

	i = 0;
	one_phrase = malloc(sizeof(char *) * (count_pointer(str) + 1));
	if (one_phrase == NULL)
		return (onephrase_malloc_error(one_phrase, node));
	while (str[i] != NULL && str[i][0] != '|')
	{
		one_phrase[i] = ft_calloc(sizeof(char), ft_strlen(str[i]) + 1);
		if (one_phrase[i] == NULL)
			return (onephrase_malloc_error(one_phrase, node));
		j = 0;
		while (str[i][j] != '\0')
		{
			one_phrase[i][j] = str[i][j];
			j++;
		}
		i++;
	}
	one_phrase[i] = NULL;
	*len += i;
	return (one_phrase);
}

t_parser	*split_pipe(char **str)
{
	char		**one_phrase;
	t_parser	*new;
	t_parser	*node;
	size_t		i;
	size_t		j;

	i = 0;
	node = NULL;
	while (str[i] != NULL)
	{
		one_phrase = one_phrase_malloc(&str[i], &i, node);
		new = ft_parsernew(ft_command(one_phrase, node),
				ft_option(one_phrase, node), ft_redirect(one_phrase, node));
		if (new == NULL)
			return (parser_malloc_error(node));
		ft_parseradd_back(&node, new);
		if (str[i] != NULL)
			i++;
		j = 0;
		while (one_phrase[j] != NULL)
			free(one_phrase[j++]);
		free(one_phrase);
	}
	return (node);
}
