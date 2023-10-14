/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:12 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/14 19:26:55 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"

static void	interactive_heredoc(t_file *file, char *name, t_parser *node)
{
	char	*prompt;
	char	*str;
	size_t	len;

	file->fd = open("/tmp/tmp", O_CREAT | O_RDWR | O_TRUNC,
			S_IREAD | S_IWRITE | S_IRGRP | S_IROTH);
	prompt = readline(">");
	if (prompt == NULL)
		exit(EXIT_SUCCESS);
	free(prompt);
	len = ft_strlen(prompt) + ft_strlen(name);
	str = NULL;
	while (ft_strncmp(prompt, name, len) != 0)
	{
		str = ft_strjoin_red(str, prompt, node);
		prompt = readline(">");
		if (prompt == NULL)
			exit(EXIT_SUCCESS);
		free(prompt);
	}
	write(file->fd, str, ft_strlen(str));
	exit(EXIT_SUCCESS);
}

int	heredoc(t_data *data, t_file *file, char *name)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == -1)
	{
		exit(EXIT_FAILURE);
		return (NO);
	}
	else if (pid == 0)
	{
		signal_heredoc(data->signal);
		interactive_heredoc(file, name, data->parser);
	}
	waitpid(pid, &status, 0);
	return (YES);
}
