/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:03:54 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/11 13:12:17 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"

t_parser	*parser_main(char **str, char *prompt)
{
	t_parser	*node;
	size_t		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	node = split_pipe(str, prompt, NULL);
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
// 	char		*str = "ABC=\"AAA\"";

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
// 	node = parser_main(result, str);
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
