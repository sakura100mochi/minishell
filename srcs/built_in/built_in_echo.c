/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:20 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/14 18:21:01 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static void	do_built_in_echo(t_parser *parser, char *str)
{
	size_t	len;

	len = 0;
	if (parser->option)
		len = ft_strlen(parser->option);
	if (!parser->option && !*str)
		ft_printf("\n");
	else if (!parser->option && *str)
		ft_printf("%s\n", str);
	if (!len)
		return ;
	if (!ft_strncmp((parser->option), "-n", len) && !*str)
		return ;
	else if (!ft_strncmp((parser->option), "-n", len) && *str)
		ft_printf("%s", str);
	else if (ft_strncmp((parser->option), "-n", len) && !*str)
		ft_printf("%s\n", parser->option);
	else if (ft_strncmp((parser->option), "-n", len) && *str)
		ft_printf("%s %s\n", parser->option, str);
	return ;
}

// static void	redirect_echo(t_parser *parser, t_file *redirect, char *str)
// {
// 	int		status;
// 	pid_t	pid;

// 	status = 0;
// 	pid = fork();
// 	if (pid == -1)
// 		exit (EXIT_FAILURE);
// 	if (pid == 0)
// 	{
// 		if (redirect->type == OUTPUT || redirect->type == APPEND)
// 		{
// 			dup2(redirect->fd, STDOUT_FILENO);
// 			do_built_in_echo(parser, str);
// 			close(redirect->fd);
// 		}
// 		else if (redirect->type == INPUT)
// 		{
// 			dup2(STDIN_FILENO, redirect->fd);
// 			do_built_in_echo(parser, str);
// 		}
// 		exit(EXIT_SUCCESS);
// 	}
// 	waitpid(pid, &status, 0);
// 	return ;
// }

// static void	check_fd(t_parser *parser, t_file *file, char *str)
// {
// 	t_file	*head;

// 	head = file;
// 	if (str == NULL)
// 		return ;
// 	while (file->next != NULL)
// 		file = file->next;
// 	redirect_echo(parser, file, str);
// 	while (head != NULL)
// 	{
// 		if (head->fd)
// 			close(head->fd);
// 		head = head->next;
// 	}
// }

void	built_in_echo(t_parser *parser, char *str)
{
	// if (parser->redirect)
	// 	check_fd(parser, parser->redirect, str);
	// else
	do_built_in_echo(parser, str);
	return ;
}
