/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:45 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/01 16:17:21 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"
#include "../../includes/parser.h"

void	quote_heredoc(t_file *file)
{
	char	*name;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	name = ft_calloc(sizeof(char), ft_strlen(file->file_name));
	if (name == NULL)
		return (void_malloc_error());
	while (file->file_name[i] != '\0')
	{
		if (file->file_name[i] != '\'' && file->file_name[i] != '\"')
		{
			name[j] = file->file_name[i];
			j++;
		}
		i++;
	}
	heredoc(file, name);
}
