/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:07:28 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/09/30 20:10:57 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"

static char	*one_phrase_malloc(char *str)
{
	char	*one_phrase;
	size_t	i;

	i = 0;
	one_phrase = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (one_phrase == NULL)
		return (char_malloc_error());
	while (str[i] != '\0')
	{
		one_phrase[i] = str[i];
		i++;
	}
	return (one_phrase);
}

t_parser	*split_pipe(char **str, char **one_phrase)
{
	t_parser	*new;
	t_parser	*node;
	size_t		i;
	size_t		j;

	i = 0;
	node = NULL;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i] != NULL && str[i][0] != '|')
			one_phrase[j++] = one_phrase_malloc(str[i++]);
		one_phrase[j] = NULL;
		new = ft_parsernew(ft_command(one_phrase), ft_option(one_phrase),
				ft_redirect(one_phrase));
		ft_parseradd_back(&node, new);
		if (str[i] != NULL)
			i++;
		j = 0;
		while (one_phrase[j] != NULL)
			free(one_phrase[j++]);
	}
	return (node);
}
