/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:18:37 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/14 15:00:47 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static int	do_built_in(t_data *data, t_parser *parser, char *file)
{
	size_t	len;

	len = ft_strlen(parser->cmd);
	if (len == 2 && !ft_strncmp(parser->cmd, "cd", len))
		data->env = built_in_cd(data->env, data->parser, file);
	else if (len == 4 && !ft_strncmp(parser->cmd, "echo", len))
		built_in_echo(data->parser, file);
	else if (len == 3 && !ft_strncmp(parser->cmd, "env", len))
		built_in_env(data->env, data->parser, file);
	else if (len == 4 && !ft_strncmp(parser->cmd, "exit", len))
		built_in_exit(data, file);
	else if (len == 6 && !ft_strncmp(parser->cmd, "export", len))
		built_in_export(data->parser, data->env, data->exp, file);
	else if (len == 3 && !ft_strncmp(parser->cmd, "pwd", len))
		built_in_pwd(parser);
	else if (len == 5 && !ft_strncmp(parser->cmd, "unset", len))
		built_in_unset(data->parser, data->env, data->exp, file);
	else
		return (NO);
	return (YES);
}

static int	do_dup_built_in(t_data *data, t_file *file, int fd, char *str)
{
	int		status;
	pid_t	pid;

// 	backup = 0;
// 	if (file->type == OUTPUT || file->type == APPEND)
// 	{
// 		backup = dup(1);
// 		dup2(file->fd, STDOUT_FILENO);
// 		do_built_in(data, parser, str);
// 		close(file->fd);
// 		dup2(backup, STDOUT_FILENO);
// 		close(backup);
// 	}
// 	else if (file->type == INPUT)
// 	{
// 		dup2(STDIN_FILENO, file->fd);
// 		do_built_in(data, parser, str);
// 		close(file->fd);
// 	}
// 	return (NO);
// }

static void	check_fd(t_data *data, t_file *file, char *str)
{
	t_file	*head;
	int		fd;

// 	head = file;
// 	if (str == NULL)
// 		return ;
// 	while (file->next != NULL)
// 		file = file->next;
// 	do_dup_built_in(data, parser, file, str);
// 	while (head != NULL)
// 	{
// 		if (head->fd)
// 			close(head->fd);
// 		head = head->next;
// 	}
// }

int	judge_built_in(t_data *data, t_parser *parser, char *file)
{
	if (do_built_in(data, parser, file))
		return (YES);
	return (NO);
}
