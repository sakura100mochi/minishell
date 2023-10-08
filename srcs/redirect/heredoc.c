/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:12 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/08 17:14:18 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"

void	heredoc(t_data *data, t_file *file, char *name)
{
	char	*prompt;
	char	*str;
	size_t	len;
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == -1)
		return ;
	else if (pid == 0)
	{
		signal_heredoc(data->signal);
		prompt = readline(">");
		len = ft_strlen(prompt) + ft_strlen(name);
		str = NULL;
		while (ft_strncmp(prompt, name, len) != 0)
		{
			str = ft_strjoin_red(str, prompt);
			prompt = readline(">");
		}
		file->result = str;
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, &status, 0);
}
