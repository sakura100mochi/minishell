/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/20 13:57:15 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static t_env	*serch_env_variable(t_env *head, char *variable)
{
	size_t	len;
	t_env	*serch_variable;

	serch_variable = head;
	if (*variable == '\0')
		return (serch_variable->prev);
	serch_variable = serch_variable->next;
	len = ft_strlen(variable);
	while (!serch_variable->head)
	{
		if (!ft_strncmp(serch_variable->variable, variable, len))
			break ;
		serch_variable = serch_variable->next;
	}
	return (serch_variable);
}

static t_env	*set_oldpwd(t_env *env_variable)
{
	char	*wd_path;
	char	*variable;

	wd_path = NULL;
	wd_path = getcwd(wd_path, PATH_MAX);
	variable = ft_strjoin("OLDPWD=", wd_path);
	free(env_variable->variable);
	env_variable->variable = variable;
	free(wd_path);
	return (env_variable);
}

static void	charnge_derectory(t_parser *parser)
{
	size_t	len;
	char	*wd_path;
	char	*absolute_path;

	if (!*(parser)->str)
		chdir("~/");
	wd_path = NULL;
	wd_path = getcwd(wd_path, PATH_MAX);
	return ;
}

t_env	*built_in_cd(t_env *env_variable, t_parser *parser)
{
	t_env	*head;

	head = env_variable;
	env_variable = serch_env_variable(head, "OLDPWD=");
	if (env_variable != head)
		env_variable = set_oldpwd(env_variable);
	change_directory(parser);
	ft_printf("cd:Not yet implemented.\n");
	return (env_variable);
}
