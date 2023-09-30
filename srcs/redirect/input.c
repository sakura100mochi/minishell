/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:26 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/30 19:49:04 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"

void	input(t_parser *node, t_file *file)
{
	int	fd;

	if (access(file->file_name, R_OK) == -1)
		no_file(file->file_name);
	fd = open(file->file_name, O_RDONLY);
	if (fd != -1)
		file->fd = fd;
	(void)node;
}
