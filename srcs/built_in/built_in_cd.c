/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/03 17:53:26 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"
#include "../../includes/error.h"

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

t_env	*built_in_cd(t_env *env_variable, t_parser *parser, char **array)
{
	t_env	*head;

	head = env_variable;
	env_variable = serch_env_variable(head, "OLDPWD=");
	if (env_variable != head)
		env_variable = set_pwd(env_variable, "OLDPWD=");
	if (array[0] != NULL && array[1] != NULL)
	{
		ft_printf("minishell: cd: too many arguments\n");
		head->status = 1;
		return (head);
	}
	if (change_directory(head, parser, array[0]))
	{
		env_variable = serch_env_variable(head, "PWD=");
		if (env_variable != head)
			env_variable = set_pwd(env_variable, "PWD=");
	}
	else
	{
		ft_printf("minishell: cd: %s: invalid option\n", parser->option);
		head->status = 2;
	}
	return (head);
}
