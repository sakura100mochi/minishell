/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:03:54 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/20 22:53:13 by hiraiyuina       ###   ########.fr       */
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
	t_parser	*node;
	char		**one_phrase;

	one_phrase = ft_calloc(sizeof(char *), pipe_count(str));
	if (one_phrase == NULL)
		return ((t_parser *)MALLOC_ERROR);
	node = split_pipe(str, one_phrase);
	return (node);
}

static char	**ft_free(char **result, t_parser *node)
{
	size_t		i;
	t_parser	*tmp;

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	while (node != NULL)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	return (NULL);
}

int	main(void)
{
	t_parser	*node;
	t_parser	*head;
	char		**result;
	size_t		i;
	char		str[] = "cat < file | echo -n a | echo -n -n -n \"Hello World\"";

	i = 0;
	result = lexer_main(str);
	while (result[i] != NULL)
	{
		printf("lexer:[%s]\n", result[i]);
		if (result[i][0] == '|')
			printf("=============================\n");
		i++;
	}
	printf("\n---------------------------\n\n");
	node = parser_main(lexer_main(str));
	head = node;
	while (node != NULL)
	{
		printf("cmd|[%s]\n", node->cmd);
		printf("option|[%s]\n", node->option);
		printf("str|[%s]\n", node->str);
		printf("redirect|[%p]\n", node->redirect);
		printf("=============================\n");
		node = node->next;
	}
	ft_free(result, head);
	return (0);
}
