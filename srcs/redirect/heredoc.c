/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:18:12 by yhirai            #+#    #+#             */
/*   Updated: 2023/11/17 21:58:29 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/unfold.h"
#include "../../includes/redirect.h"

static char	*unfold_variable(t_env *env, t_file *file, char *prompt)
{
	size_t	index;

	index = 0;
	if (file->type == Q_H)
		return (prompt);
	while (prompt[index] != '\0')
	{
		if (prompt[index] == '$' && prompt[index + 1] != '\0' && \
			(ft_isalnum(prompt[index + 1]) || prompt[index + 1] == '?'))
			prompt = unfold_str(prompt, env, &index);
		index++;
	}
	return (prompt);
}

static void	interactive_heredoc(t_env *env, t_file *file, \
									char *name, t_parser *node)
{
	char	*prompt;
	char	*str;
	size_t	len;

	str = NULL;
	while (1)
	{
		prompt = readline(">");
		if (prompt == NULL)
			exit(EXIT_SUCCESS);
		len = ft_strlen(prompt) + ft_strlen(name);
		if (ft_strncmp(prompt, name, len) == 0)
		{
			free(prompt);
			break ;
		}
		prompt = unfold_variable(env, file, prompt);
		str = ft_strjoin_red(str, prompt, node);
		free(prompt);
	}
	if (str != NULL)
		write(file->fd, str, ft_strlen(str));
	exit(EXIT_SUCCESS);
}

int	heredoc(t_data *data, t_file *file, char *name)
{
	pid_t	pid;
	int		status;

	file->fd = open("/tmp/tmp", O_CREAT | O_RDWR | O_TRUNC,
			S_IREAD | S_IWRITE | S_IRGRP | S_IROTH);
	status = 0;
	signal_minishell(data->signal, IGN);
	pid = fork();
	if (pid == -1)
	{
		exit(EXIT_FAILURE);
		perror("");
		return (NO);
	}
	else if (pid == 0)
	{
		signal_minishell(data->signal, REDIRECT);
		interactive_heredoc(data->env, file, name, data->parser);
	}
	waitpid(pid, &status, 0);
	signal_minishell(data->signal, NORMAL);
	return (YES);
}
