/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:26 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/13 14:48:42 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"
#include "../../includes/error.h"

int	input(t_file *file)
{
	int	fd;

	if (access(file->file_name, R_OK) == -1)
		return (no_file(file->file_name));
	fd = open(file->file_name, O_RDONLY);
	if (fd != -1)
	{
		file->fd = fd;
		file->result = get_next_line(fd);
	}
	return (YES);
}
