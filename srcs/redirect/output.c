/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:36 by yhirai            #+#    #+#             */
/*   Updated: 2023/11/12 18:34:05 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"
#include "../../includes/error.h"
#include "../../includes/unfold.h"
#include "../../includes/parser.h"

static char	*check_file_name(t_data *data, char *file_name)
{
	size_t	i;

	i = 0;
	if (file_name[i] != '$')
		return (file_name);
	file_name = unfold_main(data->env, file_name);
	if (file_name[0] == '\0')
		return (NULL);
	return (file_name);
}

int	output(t_data *data, t_file *file)
{
	int		fd;
	char	*tmp;

	tmp = NULL;
	tmp = ft_strjoin_minis(tmp, file->file_name, data->parser);
	if (tmp == NULL)
		return (int_malloc_error(data->parser));
	file->file_name = check_file_name(data, file->file_name);
	if (file->file_name == NULL)
		return (ambiguous(data, tmp));
	if (access(file->file_name, F_OK) == -1)
		fd = open(file->file_name, O_CREAT | O_WRONLY | O_TRUNC,
				S_IREAD | S_IWRITE | S_IRGRP | S_IROTH);
	else if (access(file->file_name, W_OK) == -1)
		return (permission(data, file->file_name));
	else
		fd = open(file->file_name, O_WRONLY | O_TRUNC);
	if (fd != -1)
		file->fd = fd;
	return (YES);
}
