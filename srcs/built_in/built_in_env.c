/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:17 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/30 11:49:23 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	built_in_env(t_env *env_variable, t_parser *parser, char *file)
{
	size_t	len;

	len = 0;
	if (*file)
	{
		ft_printf("env: %s: No such file or directory\n", file);
		return ;
	}
	if (parser->option)
		len = ft_strlen(parser->option);
	if ((len == 1 && !ft_strncmp(parser->option, "-", len)) || len > 2)
		return ;
	env_variable = env_variable->next;
	if (env_variable->head)
	{
		ft_printf("minishell: env: No such file or directory");
		return ;
	}
	while (!env_variable->head)
	{
		ft_printf("%s\n", env_variable->variable);
		env_variable = env_variable->next;
	}
}
