/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:03:54 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/19 20:09:13 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	pipe_count(char **str)
{
	size_t	count;
	size_t	i;
	size_t	j;

	count = 0;
	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '|')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_parser	**parser_main(char **str)
{
	t_parser	**parse;
	char		**phrase;
	size_t		i;
	size_t		j;
	size_t		k;

	parse = ft_calloc(sizeof(t_parser *), pipe_count(str) + 1);
	if (parse == NULL)
		return ((t_parser **)MALLOC_ERROR);
	phrase = ft_calloc(sizeof(char *), pipe_count(str));
	if (phrase == NULL)
		return ((t_parser **)MALLOC_ERROR);
	i = 0;
	k = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i] != NULL && str[i][0] != '|')
			phrase[j++] = str[i++];
		parse[k] = parsing(parse[k], phrase);
		printf("%ld|cmd___%s|option___%s\n", k, parse[k]->cmd, parse[k]->option);
		k++;
		if (str[i] != NULL)
			i++;
		ft_bzero_double(phrase);
	}
	parse[k] = NULL;
	return (parse);
}

static char	**ft_free(char **result)
{
	size_t	i;

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

int	main(void)
{
	char		**result;
	char		str[] = "cat < file | echo -n a | echo -n -n -n \"Hello World\"";

	result = lexer_main(str);
	parser_main(lexer_main(str));
	ft_free(result);
	return (0);
}
