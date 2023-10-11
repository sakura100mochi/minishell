/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:26 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/11 12:47:20 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"

void	input(t_file *file)
{
	int	fd;

	if (access(file->file_name, R_OK) == -1)
		no_file(file->file_name);
	fd = open(file->file_name, O_RDONLY);
	if (fd != -1)
		file->fd = fd;
}
