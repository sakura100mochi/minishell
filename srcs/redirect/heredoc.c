/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:12 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/30 12:45:42 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	heredoc(t_parser *node, t_file *file)
{
	char	*exit;
	size_t	len;

	len = ft_strlen(exit) + ft_strlen(file->file_name);
	exit = readline(">");
	while (ft_strncmp(exit, file->file_name, len) != 0)
		exit = readline(">");
	(void)node;
}
