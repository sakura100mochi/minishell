/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:23:10 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/21 12:28:01 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/error.h"

size_t	count_file_nbr(char *file)
{
	size_t	index;
	size_t	count;
	size_t	flag;

	index = 0;
	count = 0;
	flag = 0;
	while (file[index] != '\0')
	{
		if (!flag && (file[index] != ' ' && file[index] != '	'))
		{
			count++;
			flag++;
		}
		else if (file[index] == ' ' || file[index] == '	')
			flag = 0;
		index++;
	}
	return (count);
}

char	**add_file_to_array(char **result, char *file, size_t index, size_t len)
{
	size_t	start;
	size_t	end;
	size_t	flag;

	start = 0;
	end = 0;
	flag = 0;
	while (index < len)
	{
		if (!flag && file[end] != ' ' && file[end] != '	')
		{
			flag++;
			start = end;
		}
		else if (flag && (file[end] == ' ' || file[end] == '	' || \
														file[end] == '\0'))
		{
			result[index++] = ft_substr(file, start, end - start);
			flag--;
		}
		end++;
	}
	return (result);
}

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

char	*check_cmd_access(t_parser *parser, char **path)
{
	size_t	index;
	char	*tmp;
	char	*full_path;

	index = 0;
	while (path[index] != NULL)
	{
		tmp = ft_strjoin(path[index], "/");
		full_path = ft_strjoin(tmp, parser->cmd);
		if (!access(full_path, X_OK))
		{
			double_array_free(path);
			free(tmp);
			return (full_path);
		}
		free(tmp);
		free(full_path);
		index++;
	}
	double_array_free(path);
	full_path = check_cwd_path(parser);
	if (full_path)
		return (full_path);
	return (NULL);
}
