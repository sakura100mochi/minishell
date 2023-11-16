/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_path_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/16 11:24:35 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built_in.h"
#include "../includes/error.h"

static char	**ch_cmd_path_loop(t_env *env_variable, char **path, size_t len)
{
	char	*tmp;

	if (!ft_strncmp(env_variable->variable, "PATH=", 5))
	{
		tmp = ft_substr(env_variable->variable, 5, len);
		if (!tmp)
			exit_malloc_error();
		path = ft_split(tmp, ':');
		free(tmp);
		return (path);
	}
	return (NULL);
}

int	check_absolute_path(char *cmd)
{
	size_t	index;
	size_t	flag;

	index = 0;
	flag = 0;
	while (cmd[index] != '\0')
	{
		if (cmd[index] == '/')
			flag = 1;
		index++;
	}
	if (flag)
		return (YES);
	return (NO);
}

char	*check_cmd_path(t_env *env_variable, t_parser *parser)
{
	size_t	len;
	t_env	*head;
	char	**path;
	char	*full_path;

	path = NULL;
	head = env_variable;
	env_variable = env_variable->next;
	if (!*parser->cmd)
		return (NULL);
	while (!env_variable->head && !path)
	{
		len = ft_strlen(env_variable->variable);
		if (len < 5)
		{
			env_variable = env_variable->next;
			continue ;
		}
		path = ch_cmd_path_loop(env_variable, path, len);
		env_variable = env_variable->next;
	}
	full_path = check_cmd_access(parser, path);
	if (!full_path)
		command_not_found(head, parser->cmd);
	return (full_path);
}
