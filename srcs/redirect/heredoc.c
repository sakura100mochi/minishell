/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:12 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/30 17:27:16 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"

char	*heredoc(t_parser *node, char *file_name)
{
	char	*exit;
	char	*str;
	size_t	len;

	exit = readline(">");
	len = ft_strlen(exit) + ft_strlen(file_name);
	str = NULL;
	while (ft_strncmp(exit, file_name, len) != 0)
	{
		str = ft_strjoin_red(str, exit);
		exit = readline(">");
	}
	(void)node;
	return (str);
}
