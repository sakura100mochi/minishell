/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:36 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/30 17:27:25 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"

void	output(t_parser *node, t_file *file)
{
	int	fd;

	if (access(file->file_name, F_OK) == -1)
		fd = open(file->file_name, O_CREAT | O_WRONLY | O_TRUNC,
				S_IREAD | S_IWRITE | S_IRGRP | S_IROTH);
	else if (access(file->file_name, W_OK) == -1)
		return (permission(file->file_name));
	else
		fd = open(file->file_name, O_WRONLY | O_TRUNC);
	if (fd != -1)
		file->fd = fd;
	(void)node;
}
