/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:07:28 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/10/01 12:47:27 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"

static char	**one_phrase_malloc(char **str, char **one_phrase, size_t *len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != NULL && str[i][0] != '|')
	{
		one_phrase[i] = ft_calloc(sizeof(char), ft_strlen(str[i]) + 1);
		if (one_phrase[i] == NULL)
			return (NULL);
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
		one_phrase = one_phrase_malloc(&str[i], one_phrase, &i);
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
