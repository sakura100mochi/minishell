/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:17:53 by yhirai            #+#    #+#             */
/*   Updated: 2023/11/12 19:36:21 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"
#include "../../includes/error.h"

int	append(t_data *data, t_file *file)
{
	int	fd;

	if (access(file->file_name, F_OK) == -1)
		return (output(data, file));
	if (access(file->file_name, W_OK) == -1)
		return (permission(data, file->file_name));
	fd = open(file->file_name, O_WRONLY | O_APPEND);
	if (fd != -1)
		file->fd = fd;
	return (YES);
}
