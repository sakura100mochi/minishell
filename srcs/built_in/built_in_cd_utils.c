/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cd_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/28 03:51:35 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"
#include "../../includes/error.h"

static void	do_chdir(t_env *head, char *file_path)
{
	if (chdir(file_path) == -1)
	{
		perror("minishell");
		head->status = 1;
	}
	else
		head->status = 0;
	return ;
}

static int	change_home_directory(t_env *head, char *file)
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
			do_chdir(head, tmp_path);
		else
		{
			ft_printf("minishell: cd: %s: File name too long\n", file);
			head->status = 1;
		}
		free(tmp_path);
	}
	else
	{
		if (chdir(file) == -1)
			perror("minishell");
	}
	return (YES);
}

static void	change_cwd_directory(t_env *head, char *wd_path, char *file)
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
		do_chdir(head, absolute_path);
	else
	{
		ft_printf("minishell: cd: %s: File name too long\n", absolute_path);
		head->status = 1;
	}
	free(wd_path);
	free(tmp_path);
	free(absolute_path);
	return ;
}

int	change_directory(t_env *head, t_parser *parser, char *file)
{
	char	*wd_path;

	if (parser->option)
		return (NO);
	if (((file[0] != '\0' && file[0] == '~') || !*file) && !parser->option)
	{
		change_home_directory(head, file);
		return (YES);
	}
	else if (file[0] == '/' && !parser->option)
	{
		do_chdir(head, file);
		return (YES);
	}
	wd_path = NULL;
	wd_path = getcwd(wd_path, PATH_MAX);
	change_cwd_directory(head, wd_path, file);
	return (YES);
}
