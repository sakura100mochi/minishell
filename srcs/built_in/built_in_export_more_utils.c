/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export_more_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:40:38 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/11 16:38:13 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"
#include "../../includes/error.h"

int	check_envvariable_exist(t_env *env, char *str)
{
	size_t	len;

	len = 0;
	env = env->next;
	while (!env->head)
	{
		len = ft_strlen(str);
		if (!ft_strncmp(str, env->variable, len))
			return (YES);
		env = env->next;
	}
	return (NO);
}

int	check_expvariable_exist(t_exp *exp, char *str)
{
	size_t	len;
	char	*tmp;

	tmp = ft_strjoin("declare -x ", str);
	if (!tmp)
		exit_malloc_error();
	len = ft_strlen(tmp);
	exp = exp->next;
	while (!exp->head)
	{
		if (!ft_strncmp(tmp, exp->variable, len) || \
		(ft_strlen(exp->variable) == len - 1 && \
		!ft_strncmp(tmp, exp->variable, len - 1)))
		{
			free(tmp);
			return (YES);
		}
		exp = exp->next;
	}
	free(tmp);
	return (NO);
}

t_env	*input_env_variable(char *str, t_env *env_variable)
{
	char	*tmp_str;
	t_env	*head;
	t_env	*new;

	head = env_variable;
	env_variable = env_variable->prev;
	tmp_str = ft_strdup(str);
	new = new_env_node(tmp_str, 0);
	head->prev = new;
	env_variable->next = new;
	new->prev = env_variable;
	new->next = head;
	return (head);
}

t_exp	*input_exp_variable(char *str, t_exp *exp_variable, int flag)
{
	char	*tmp_str;
	char	*variable;
	t_exp	*head;
	t_exp	*new;

	tmp_str = NULL;
	head = exp_variable;
	exp_variable = exp_variable->prev;
	if (flag)
	{
		tmp_str = wrap_with_quotes(str);
		variable = ft_strjoin("declare -x ", tmp_str);
		free(tmp_str);
	}
	else
		variable = ft_strjoin("declare -x ", str);
	new = new_exp_node(variable, 0);
	head->prev = new;
	exp_variable->next = new;
	new->prev = exp_variable;
	new->next = head;
	return (head);
}
