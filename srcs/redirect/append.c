/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:17:53 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/30 19:47:04 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"

void	append(t_parser *node, t_file *file)
{
	int	fd;

	if (access(file->file_name, F_OK) == -1)
		return (output(node, file));
	fd = open(file->file_name, O_WRONLY | O_APPEND);
	if (fd != -1)
		file->fd = fd;
}
