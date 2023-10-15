/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:03:54 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/15 17:59:15 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"

t_parser	*parser_main(char **str)
{
	t_parser	*node;
	size_t		i;

	i = 0;
	node = split_pipe(str);
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
	return (node);
}

// static char	**ft_free(t_parser *node)
// {
// 	t_parser	*tmp_node;
// 	t_file		*file;
// 	t_file		*tmp_file;

// 	while (node != NULL)
// 	{
// 		file = node->redirect;
// 		while (file != NULL)
// 		{
// 			tmp_file = file->next;
// 			free(file->file_name);
// 			free(file);
// 			file = tmp_file;
// 		}
// 		tmp_node = node->next;
// 		free(node->cmd);
// 		free(node->option);
// 		free(node);
// 		node = tmp_node;
// 	}
// 	return (NULL);
// }

// int	main(void)
// {
// 	t_parser	*node;
// 	t_parser	*head;
// 	t_file		*file;
// 	char		**result;
// 	size_t		i;
// 	char		*str = "          cat << a |        ls 			-l  |   ";

// 	i = 0;
// 	result = lexer_main(str);
// 	printf("script:[%s]\n", str);
// 	while (result[i] != NULL)
// 	{
// 		printf("lexer:[%s]\n", result[i]);
// 		if (result[i][0] == '|')
// 			printf("=============================\n");
// 		i++;
// 	}
// 	printf("\n---------------------------\n\n");
// 	node = parser_main(result);
// 	head = node;
// 	while (node != NULL)
// 	{
// 		printf("cmd|[%s]\n", node->cmd);
// 		printf("option|[%s]\n", node->option);
// 		file = node->redirect;
// 		while (file != NULL)
// 		{
// 			printf("redirect|type|[%u]\n", file->type);
// 			printf("redirect|name|[%s]\n", file->file_name);
// 			file = file->next;
// 		}
// 		printf("=============================\n");
// 		node = node->next;
// 	}
// 	ft_free(head);
// 	return (0);
// }

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q minishell");
// }
