/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:12 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/03 14:45:22 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"

void	heredoc(t_data *data, t_file *file, char *name)
{
	char	*exit;
	char	*str;
	size_t	len;

	exit = readline(">");
	len = ft_strlen(exit) + ft_strlen(name);
	str = NULL;
	data->signal->interactive_mode = YES;
	while (ft_strncmp(exit, name, len) != 0)
	{
		str = ft_strjoin_red(str, exit);
		exit = readline(">");
	}
	data->signal->interactive_mode = NO;
	file->result = str;
}
