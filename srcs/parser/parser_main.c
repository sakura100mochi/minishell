/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:03:54 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/24 15:26:51 by yhirai           ###   ########.fr       */
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
	size_t		i;

	i = 0;
	one_phrase = ft_calloc(sizeof(char *), pipe_count(str) + 1);
	if (one_phrase == NULL)
		return (parser_malloc_error());
	node = split_pipe(str, one_phrase);
	free(one_phrase);
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
	return (node);
}

static char	**ft_free(char **result, t_parser *node)
{
	size_t		i;
	t_parser	*tmp_node;
	t_file		*file;
	t_file		*tmp_file;

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	while (node != NULL)
	{
		file = node->redirect;
		while (file != NULL)
		{
			tmp_file = file->next;
			free(file->file_name);
			free(file);
			file = tmp_file;
		}
		tmp_node = node->next;
		free(node->cmd);
		free(node->option);
		free(node);
		node = tmp_node;
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
	char		*str = "echo >";

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
