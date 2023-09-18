/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:03:54 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/18 22:21:30 by hiraiyuina       ###   ########.fr       */
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

t_parser	*parser_main(char **str)
{
	t_parser	*parse;
	char		**phrase;
	size_t		i;
	size_t		j;

	parse = ft_calloc(sizeof(t_parser), pipe_count(str));
	if (parse == NULL)
		return (NULL);
	phrase = ft_calloc(sizeof(char *), pipe_count(str));
	if (phrase == NULL)
		return (NULL);
	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i] != NULL && str[i][0] != '|')
		{
			phrase[j] = str[i];
			printf("+++++%s\n", phrase[j]);
			i++;
			j++;
		}
		parse = parsing(parse, phrase);
		if (str[i] != NULL)
			i++;
		ft_bzero_double(phrase);
	}
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
	char		str[] = "echo 'orld' \"hello\" | cat < file";
	int			i;

	result = lexer_main(str);
	i = 0;
	while (result[i] != NULL)
	{
		printf("lexer : [%s]\n", result[i]);
		i++;
	}
	parser_main(lexer_main(str));
	ft_free(result);
	return (0);
}