/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:03:54 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/22 15:43:42 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	pipe_count(char **str)
{
	size_t	count;
	size_t	max;
	size_t	i;

	count = 0;
	max = 0;
	i = 0;
	while (str[i] != NULL)
	{
		if (str[i][0] == '|')
		{
			if (max < count)
				max = count;
			count = 0;
		}
		count++;
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
	t_file		*file;
	char		**result;
	size_t		i;
	char		*str = "cat << a | cat < a | cat >> a | cat > a";

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
		file = node->redirect;
		while (file != NULL)
		{
			printf("redirect|type|[%u]\n", file->type);
			printf("redirect|name|[%s]\n", file->file_name);
			file = file->next;
		}
		printf("=============================\n");
		node = node->next;
	}
	ft_free(result, head);
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q minishell");
// }
