/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:26 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/30 13:41:11 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	input(t_parser *node, t_file *file)
{
	(void)node;
	(void)file;
	if (access(file->file_name, R_OK) == -1)
		no_file(file->file_name);
}
