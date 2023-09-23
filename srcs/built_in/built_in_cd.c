/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/24 06:07:46 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static t_env	*set_pwd(t_env *env_variable, char *head_variable)
{
	char	*wd_path;
	char	*variable;

	wd_path = NULL;
	wd_path = getcwd(wd_path, PATH_MAX);
	variable = ft_strjoin(head_variable, wd_path);
	free(env_variable->variable);
	env_variable->variable = variable;
	free(wd_path);
	return (env_variable);
}

static int	change_directory(t_parser *parser, char *file)
{
	char	*wd_path;
	char	*tmp_path;
	char	*absolute_path;

	if (!*file)
	{
		chdir("~/");
		return (0);
	}
	if (*parser->option)
		return (1);
	wd_path = NULL;
	wd_path = getcwd(wd_path, PATH_MAX);
	tmp_path = ft_strjoin(wd_path, "/");
	absolute_path = ft_strjoin(tmp_path, file);
	chdir(absolute_path);
	free(wd_path);
	free(tmp_path);
	free(absolute_path);
	return (0);
}

t_env	*built_in_cd(t_env *env_variable, t_parser *parser, char *file)
{
	t_env	*head;

	head = env_variable;
	env_variable = serch_env_variable(head, "OLDPWD=");
	if (env_variable != head)
		env_variable = set_pwd(env_variable, "OLDPWD=");
	if (change_directory(parser, file))
	{
		env_variable = serch_env_variable(head, "PWD=");
		if (env_variable != head)
			env_variable = set_pwd(env_variable, "PWD=");
	}
	return (head);
}
