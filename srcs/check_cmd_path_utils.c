/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_path_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/23 20:23:54 by csakamot         ###   ########.fr       */
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

char	*check_cmd_path(t_env *env_variable, t_parser *parser)
{
	size_t	len;
	char	**path;
	char	*full_path;

	path = NULL;
	env_variable = env_variable->next;
	while (!env_variable->head)
	{
		len = ft_strlen(env_variable->variable);
		if (len < 5)
			return (NULL);
		path = ch_cmd_path_loop(env_variable, path, len);
		if (path)
			break ;
		env_variable = env_variable->next;
	}
	full_path = check_cmd_access(parser, path);
	if (!env_variable->head && full_path)
		return (full_path);
	return (NULL);
}
