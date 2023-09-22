/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/20 19:42:39 by csakamot         ###   ########.fr       */
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

static void	change_directory(t_parser *parser)
{
	size_t	len;
	char	*wd_path;
	char	*tmp_path;
	char	*absolute_path;

	if (!*(parser)->str)
	{
		chdir("~/");
		return ;
	}
	len = ft_strlen(parser->str);
	if (len == 1 && ft_strncmp(parser->str, "-", 1))
		return ;
	wd_path = NULL;
	wd_path = getcwd(wd_path, PATH_MAX);
	tmp_path = ft_strjoin(wd_path, "/");
	absolute_path = ft_strjoin(tmp_path, parser->str);
	chdir(absolute_path);
	free(wd_path);
	free(tmp_path);
	free(absolute_path);
}

t_env	*built_in_cd(t_env *env_variable, t_parser *parser)
{
	t_env	*head;

	head = env_variable;
	env_variable = serch_env_variable(head, "OLDPWD=");
	if (env_variable != head)
		env_variable = set_pwd(env_variable, "OLDPWD=");
	change_directory(parser);
	env_variable = serch_env_variable(head, "PWD=");
	if (env_variable != head)
		env_variable = set_pwd(env_variable, "PWD=");
	return (head);
}
