/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:17 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/28 16:38:09 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static void	end_status_echo(t_env *env, char *path, char *file)
{
	if (access(path, F_OK) == 0)
	{
		ft_printf("env: '%s': Permission denied\n", file);
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
		perror("minishell");
		return ;
	}
	tmp = create_file_path(file);
	full_path = ft_strjoin(cwd, tmp);
	if (!full_path)
		exit(EXIT_FAILURE);
	end_status_echo(env, full_path, file);
	free(cwd);
	free(tmp);
	free(full_path);
	return ;
}

static void	judge_check_option(t_env *head, char *option, \
									size_t index, size_t flag)
{
	if (flag && index == 1)
	{
		ft_printf("env: invalid option -- '%c'\n", option[1]);
		head->status = 125;
	}
	else if (flag && index > 1)
	{
		ft_printf("env: unrecognized option '%s'\n", option);
		head->status = 125;
	}
	return ;
}

static int	check_option(t_env *head, char *option)
{
	size_t	index;
	size_t	flag;

	index = 0;
	flag = 0;
	if (option == NULL)
		return (YES);
	while (option[index] != '\0')
	{
		if (option[index] != '-')
		{
			flag = 1;
			break ;
		}
		index++;
	}
	if (!flag && (index == 1 || index > 2))
		return (NO);
	if (!flag && index == 2)
		return (YES);
	judge_check_option(head, option, index, flag);
	return (NO);
}

void	built_in_env(t_env *env_variable, t_parser *parser, char *file)
{
	env_variable->status = 0;
	if (*file)
	{
		check_cwd_file(env_variable, file);
		return ;
	}
	if (!check_option(env_variable, parser->option))
		return ;
	env_variable = env_variable->next;
	while (!env_variable->head)
	{
		ft_printf("%s\n", env_variable->variable);
		env_variable = env_variable->next;
	}
}
