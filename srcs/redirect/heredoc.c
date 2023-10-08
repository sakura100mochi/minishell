/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:12 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/04 14:28:40 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"

void	heredoc(t_data *data, t_file *file, char *name)
{
	char	*prompt;
	char	*str;
	size_t	len;

	prompt = readline(">");
	len = ft_strlen(prompt) + ft_strlen(name);
	str = NULL;
	while (ft_strncmp(prompt, name, len) != 0)
	{
		str = ft_strjoin_red(str, prompt);
		prompt = readline(">");
	}
	file->result = str;
	(void)data;
}
