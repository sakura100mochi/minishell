/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_access.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/29 06:16:44 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/built_in.h"
#include "../includes/error.h"

static char	*check_cwd_path(t_parser *parser)
{
	char	*cwd;
	char	*tmp;
	char	*full_path;

	cwd = NULL;
	cwd = getcwd(cwd, PATH_MAX);
	tmp = ft_strjoin(cwd, "/");
	full_path = ft_strjoin(tmp, parser->cmd);
	free(cwd);
	free(tmp);
	if (!access(full_path, X_OK))
		return (full_path);
	free(full_path);
	return (NULL);
}

static char	*path_cmd_access(char *full_path, char **path, char *tmp)
{
	if (!access(full_path, X_OK))
	{
		double_array_free(path);
		free(tmp);
		return (full_path);
	}
	free(tmp);
	free(full_path);
	return (NULL);
}

static char	*check_absolute_path(char *cmd, char **path)
{
	char	*tmp;

	tmp = ft_strdup(cmd);
	if (!tmp)
		exit_malloc_error();
	if (!access(tmp, X_OK))
	{
		double_array_free(path);
		return (tmp);
	}
	free(tmp);
	return (NULL);
}

char	*check_cmd_access(t_parser *parser, char **path)
{
	size_t	index;
	char	*tmp;
	char	*full_path;

	index = 0;
	full_path = check_absolute_path(parser->cmd, path);
	if (full_path)
		return (full_path);
	if (!path)
		return (NULL);
	while (path[index] != NULL)
	{
		tmp = create_file_path(parser->cmd);
		full_path = ft_strjoin(path[index], tmp);
		full_path = path_cmd_access(full_path, path, tmp);
		if (full_path)
			return (full_path);
		index++;
	}
	double_array_free(path);
	full_path = check_cwd_path(parser);
	if (full_path)
		return (full_path);
	return (NULL);
}
