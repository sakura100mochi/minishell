/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/20 11:29:29 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static t_env	*serch_env_variable(t_env *head, char *variable)
{
	size_t	len;
	t_env	*serch_variable;

	(void)head;
	serch_variable = NULL;
	len = ft_strlen(variable);
	return (serch_variable);
}

t_env	*built_in_cd(t_env *env_variable, t_parser *parser)
{
	t_env	*head;

	head = env_variable;
	env_variable = serch_env_variable(head, "OLDPWD=");
	(void)parser;
	ft_printf("cd:Not yet implemented.\n");
	return (env_variable);
}
