/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:12 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/08 20:08:12 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"

static void	interactive_heredoc(t_file *file, char *name)
{
	char	*prompt;
	char	*str;
	size_t	len;

	file->fd = open("/tmp", O_CREAT | O_RDWR | O_TRUNC,
			S_IREAD | S_IWRITE | S_IRGRP | S_IROTH);
	printf("%d\n", file->fd);
	prompt = readline(">");
	if (prompt == NULL)
		exit(EXIT_SUCCESS);
	free(prompt);
	len = ft_strlen(prompt) + ft_strlen(name);
	str = NULL;
	while (ft_strncmp(prompt, name, len) != 0)
	{
		str = ft_strjoin_red(str, prompt);
		prompt = readline(">");
		if (prompt == NULL)
			exit(EXIT_SUCCESS);
		free(prompt);
	}
	file->result = str;
	write(file->fd, str, ft_strlen(str));
	exit(EXIT_SUCCESS);
}

void	heredoc(t_data *data, t_file *file, char *name)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == -1)
	{
		exit(EXIT_FAILURE);
		return ;
	}
	else if (pid == 0)
	{
		signal_heredoc(data->signal);
		interactive_heredoc(file, name);
	}
	waitpid(pid, &status, 0);
}
