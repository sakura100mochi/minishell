/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_in_redirect_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:38:01 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/23 20:28:38 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/built_in.h"

int	last_input_fd(t_file *file)
{
	int	fd;

	fd = 0;
	while (file != NULL)
	{
		if (file->type == INPUT)
			fd = file->fd;
		else if (file->type == HEREDOC || file->type == Q_H)
		{
			close(file->fd);
			file->fd = open("/tmp/tmp", O_RDONLY);
			fd = file->fd;
		}
		file = file->next;
	}
	return (fd);
}

int	last_output_fd(t_file *file)
{
	int	fd;

	fd = 0;
	while (file != NULL)
	{
		if (file->type == OUTPUT || file->type == APPEND)
			fd = file->fd;
		file = file->next;
	}
	return (fd);
}

void	close_fd(t_file *file)
{
	while (file != NULL)
	{
		if (file->type == HEREDOC || file->type == Q_H)
			unlink("/tmp/tmp");
		if (file->fd)
			close(file->fd);
		file = file->next;
	}
	return ;
}
