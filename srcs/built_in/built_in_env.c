/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:17 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/21 06:28:48 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static void	end_status_echo(t_env *env, char *path, char *file)
{
	if (!access(path, F_OK))
	{
		ft_printf("env: '%s/': Permission denied\n", file);
		env->status = 126;
	}
	else
	{
		ft_printf("env: '%s': No such file or directory\n", file);
		env->status = 127;
	}
	return ;
}

static void	check_cwd_file(t_env *env, char *file)
{
	char	*cwd;
	char	*tmp;
	char	*full_path;

	cwd = NULL;
	cwd = getcwd(cwd, PATH_MAX);
	if (!cwd)
	{
		perror("minishell: ");
		return ;
	}
	tmp = create_file_path(file);
	full_path = ft_strjoin(tmp, file);
	if (!full_path)
		exit(EXIT_FAILURE);
	end_status_echo(env, full_path, file);
	free(cwd);
	free(tmp);
	free(full_path);
	return ;
}

void	built_in_env(t_env *env_variable, t_parser *parser, char *file)
{
	size_t	len;

	len = 0;
	if (*file)
	{
		check_cwd_file(env_variable, file);
		return ;
	}
	if (parser->option)
		len = ft_strlen(parser->option);
	if ((len == 1 && !ft_strncmp(parser->option, "-", len)) || len > 2)
		return ;
	env_variable = env_variable->next;
	while (!env_variable->head)
	{
		ft_printf("%s\n", env_variable->variable);
		env_variable = env_variable->next;
	}
}
