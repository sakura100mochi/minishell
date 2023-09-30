/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:45 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/30 12:45:37 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	quote_heredoc(t_parser *node, t_file *file)
{
	char	*exit;
	char	*name;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	name = ft_calloc(sizeof(char), ft_strlen(file->file_name));
	if (name == NULL)
		return ;
	while (file->file_name[i] != '\0')
	{
		if (file->file_name[i] != '\'' && file->file_name[i] != '\"')
		{
			name[j] = file->file_name[i];
			j++;
		}
		i++;
	}
	len = ft_strlen(exit) + ft_strlen(name);
	exit = readline(">");
	while (ft_strncmp(exit, name, len) != 0)
		exit = readline(">");
	(void)node;
}
