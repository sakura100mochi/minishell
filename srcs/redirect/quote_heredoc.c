/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:45 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/30 16:38:46 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*quote_heredoc(t_parser *node, t_file *file)
{
	char	*name;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	name = ft_calloc(sizeof(char), ft_strlen(file->file_name));
	if (name == NULL)
		return (char_malloc_error());
	while (file->file_name[i] != '\0')
	{
		if (file->file_name[i] != '\'' && file->file_name[i] != '\"')
		{
			name[j] = file->file_name[i];
			j++;
		}
		i++;
	}
	return (heredoc(node, name));
	(void)node;
}
