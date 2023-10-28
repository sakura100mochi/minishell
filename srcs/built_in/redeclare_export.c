/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redeclare_export.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/28 16:42:16 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/built_in.h"
#include "../../includes/error.h"

t_env	*redeclare_env(t_env *env, char *variable, char *tmp)
{
	size_t	len;
	t_env	*head;

	len = ft_strlen(tmp);
	head = env;
	env = env->next;
	while (!env->head)
	{
		if (!ft_strncmp(tmp, env->variable, len))
		{
			printf("%s, %s\n", env->variable, variable);
			free (env->variable);
			env->variable = ft_strdup(variable);
			if (env->variable == NULL)
				exit_malloc_error();
		}
		env = env->next;
	}
	return (head);
}

t_exp	*redeclare_exp(t_exp *exp, char *variable, char *tmp)
{
	size_t	len;
	t_exp	*head;
	char	*input;

	len = ft_strlen(tmp);
	head = exp;
	exp = exp->next;
	input = NULL;
	while (!exp->head)
	{
		if (!ft_strncmp(tmp, exp->variable + 11, len))
		{
			input = ft_strjoin("declare -x ", variable);
			if (!input)
				exit_malloc_error();
			free(exp->variable);
			exp->variable = input;
		}
		exp = exp->next;
	}
	return (head);
}
