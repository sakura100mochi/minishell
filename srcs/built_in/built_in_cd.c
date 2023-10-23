/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/23 19:46:53 by csakamot         ###   ########.fr       */
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

static int	change_home_directory(char *file)
{
	char	*home_path;
	char	*tmp_path;

	home_path = getenv("HOME");
	tmp_path = NULL;
	if (file[0] == '\0')
		chdir(home_path);
	else if (file[1] != '\0' && file[1] == '/')
	{
		tmp_path = ft_strjoin(home_path, file + 2);
		if (ft_strlen(tmp_path) < PATH_MAX)
			chdir (tmp_path);
		else
			ft_printf("minishell: cd: %s: File name too long\n", file);
		free(tmp_path);
	}
	else
		chdir(file);
	return (YES);
}

static void	change_cwd_directory(char *wd_path, char *file)
{
	char	*tmp_path;
	char	*absolute_path;

	if (*file)
		tmp_path = create_file_path(file++);
	else
		tmp_path = create_file_path(file);
	absolute_path = ft_strjoin(wd_path, tmp_path);
	if (!absolute_path)
		exit_malloc_error();
	if (ft_strlen(absolute_path) < PATH_MAX)
		chdir(absolute_path);
	else
		ft_printf("minishell: cd: %s: File name too long\n", absolute_path);
	free(wd_path);
	free(tmp_path);
	free(absolute_path);
	return ;
}

static int	change_directory(t_parser *parser, char *file)
{
	char	*wd_path;

	if (parser->option)
		return (NO);
	if ((file[0] != '\0' || file[0] == '~') && !parser->option)
	{
		if (ft_strlen(file) < PATH_MAX)
			change_home_directory(file);
		else
			ft_printf("minishell: cd: %s: File name too long\n", file);
		return (YES);
	}
	else if (file[0] == '/' && !parser->option)
	{
		chdir(file);
		return (YES);
	}
	wd_path = NULL;
	wd_path = getcwd(wd_path, PATH_MAX);
	change_cwd_directory(wd_path, file);
	return (YES);
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
		g_status = 0;
	}
	else
	{
		ft_printf("minishell: cd: %s: invalid option\n", parser->option);
		g_status = 2;
	}
	return (head);
}
