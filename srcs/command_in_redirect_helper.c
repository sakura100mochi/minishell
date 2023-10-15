/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_in_redirect_helper.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:38:01 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/15 17:11:22 by csakamot         ###   ########.fr       */
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
		else if (file->type == HEREDOC || file->type == QUOTE_HEREDOC)
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
