/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_do_export_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/04 14:30:42 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/built_in.h"
#include "../../includes/error.h"

static char	*split_variable(char *str)
{
	size_t	index;
	char	*result;

	index = 0;
	result = NULL;
	while (str[index] != '\0' && str[index] != '=')
		index++;
	if (str[index] != '\0')
		result = ft_substr(str, 0, index + 1);
	if (!result)
		exit_malloc_error();
	return (result);
}

static int	check_variable(t_env *env, char *variable)
{
	size_t	index;
	size_t	flag;

	index = 0;
	flag = 0;
	if (variable[index] == '=')
	{
		env->status = 1;
		return (0);
	}
	while (variable[index] != '\0')
	{
		if (variable[index] == '=')
			flag = index;
		index++;
	}
	if (variable[flag - 1] == ' ' || variable[flag - 1] == '	')
	{
		env->status = 1;
		return (0);
	}
	return (1);
}

void	do_export(t_env *env_variable, t_exp *exp_variable, \
										char *variable, char *str)
{
	char	*tmp;

	tmp = NULL;
	if (*variable && !check_variable(env_variable, variable))
	{
		ft_printf("minishell: export: '=': not a valid identifier\n");
		env_variable->status = 1;
	}
	else if (*variable && check_variable(env_variable, variable))
	{
		tmp = split_variable(str);
		if (check_expvariable_exist(exp_variable, tmp))
			exp_variable = redeclare_exp(exp_variable, variable, tmp);
		else
			exp_variable = input_exp_variable(variable, exp_variable, 1);
		if (check_envvariable_exist(env_variable, tmp))
			env_variable = redeclare_env(env_variable, variable, tmp);
		else
			env_variable = input_env_variable(variable, env_variable);
		free(tmp);
	}
	return ;
}
