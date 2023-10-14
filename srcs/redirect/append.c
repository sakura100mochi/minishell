/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:17:53 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/13 14:47:40 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"

int	append(t_file *file)
{
	int	fd;

	if (access(file->file_name, F_OK) == -1)
		return (output(file));
	fd = open(file->file_name, O_WRONLY | O_APPEND);
	if (fd != -1)
		file->fd = fd;
	return (YES);
}
