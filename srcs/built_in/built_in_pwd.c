/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/21 19:03:52 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	built_in_pwd(t_env *env, t_parser *parser)
{
	char	*wd_path;

	wd_path = NULL;
	if (parser->option && ft_strlen(parser->option) > 1)
	{
		ft_printf("minishell: pwd: -%c: not a valid identifier\n", \
														parser->option[1]);
		env->status = 2;
		return ;
	}
	wd_path = getcwd(wd_path, PATH_MAX);
	if (!wd_path)
	{
		env->status = 1;
		perror("");
		return ;
	}
	ft_printf("%s\n", wd_path);
	free(wd_path);
	env->status = 0;
	return ;
}
