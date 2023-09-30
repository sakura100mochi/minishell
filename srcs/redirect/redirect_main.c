/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:09:45 by yhirai            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/09/30 17:55:39 by csakamot         ###   ########.fr       */
=======
/*   Updated: 2023/09/30 17:58:54 by yhirai           ###   ########.fr       */
>>>>>>> 8b77250ee73b5fc47e5efb8c0a0a213b4585f7ca
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"
#include "../../includes/parser.h"
#include "../../includes/built_in.h"

void	redirect_main(t_data *data, t_parser *node)
{
	t_file	*file;
	char	*str;

	file = node->redirect;
	str = NULL;
	while (file != NULL)
	{
		if (file->type == UNKNOWN)
			return ;
		if (file->file_name == NULL)
			return (syntax(NULL));
		else if (file->type == QUOTE_HEREDOC)
			str = quote_heredoc(node, file);
		else if (file->type == HEREDOC)
			str = heredoc(node, file->file_name);
		else if (file->type == INPUT)
			input(node, file);
		else if (file->type == APPEND)
			append(node, file);
		else if (file->type == OUTPUT)
			output(node, file);
		file = file->next;
	}
	check_fd(data, node, node->redirect, str);
}

void	check_fd(t_data *data, t_parser *node, t_file *file, char *str)
{
	int		fd;
	t_file	*head;

	(void)node;
	head = file;
	if (str == NULL)
		return ;
	while (file != NULL)
	{
		if (file->fd)
			fd = file->fd;
		file = file->next;
	}
	cmd_redirect(data, node, fd, str);
	while (head != NULL)
	{
		if (head->fd)
			close(head->fd);
		head = head->next;
	}
	(void)node;
}

void	cmd_redirect(t_data *data, t_parser *node, int fd, char *str)
{
	char	*file;

	if (node->cmd == NULL)
		return ;
	if (ft_strncmp(node->cmd, "cat", ft_strlen(node->cmd)) == 0)
	{
		dup2(fd, STDOUT_FILENO);
		ft_printf("%s\n", str);
	}
	else
	{
		file = format_command(data->parser);
		if (!judge_built_in(data, data->parser, file))
			fork_and_execve(data, data->exe, data->parser, file);
		free(file);
	}
}

// static char	**ft_free(char **result, t_parser *node)
// {
// 	size_t		i;
// 	t_parser	*tmp_node;
// 	t_file		*file;
// 	t_file		*tmp_file;

// 	i = 0;
// 	while (result[i] != NULL)
// 	{
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
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
// 	char		**result;
// 	char		*str = "cat << a << \"b\" > a > b";

// 	result = lexer_main(str);
// 	node = parser_main(lexer_main(str));
// 	head = node;
// 	redirect_main(node);
// 	ft_free(result, head);
// 	return (0);
// }
