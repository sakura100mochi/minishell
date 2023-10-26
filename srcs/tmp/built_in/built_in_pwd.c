/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/22 18:03:19 by yhirai           ###   ########.fr       */
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
		g_status = 2;
		return ;
	}
	wd_path = getcwd(wd_path, PATH_MAX);
	if (!wd_path)
	{
		g_status = 1;
		perror("");
		return ;
	}
	ft_printf("%s\n", wd_path);
	free(wd_path);
	g_status = 0;
	(void)env;
	return ;
}
