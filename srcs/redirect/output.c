/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:36 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/24 19:54:53 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	output(t_parser *node, t_file *file)
{
	if (file->file_name == NULL)
	{
		syntax();
		return ;
	}
	(void)node;
}
