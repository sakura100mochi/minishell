/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:26:05 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/22 14:38:16 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static int	check_equal(char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '=')
			return (0);
		index++;
	}
	return (1);
}

static int	check_variable(t_env *env, char *variable)
{
	size_t	index;
	size_t	flag;

	index = 0;
	flag = 0;
	if (variable[index] == '=')
	{
		status = 1;
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
		status = 1;
		return (0);
	}
	(void)env;
	return (1);
}

static void	do_export(t_env *env_variable, t_exp *exp_variable, char *variable)
{
	if (*variable && !check_variable(env_variable, variable))
	{
		ft_printf("minishell: export: '=': not a valid identifier\n");
		status = 1;
	}
	else if (*variable && check_variable(env_variable, variable))
	{
		exp_variable = input_exp_variable(variable, env_variable, \
														exp_variable, 1);
		env_variable = input_env_variable(variable, env_variable);
	}
	return ;
}

void	built_in_export(t_parser *parser, t_env *env_variable, \
									t_exp *exp_variable, char *str)
{
	char	*variable;

	if (parser->option)
	{
		status = 1;
		ft_printf("minishell: export: '%s': not a valid identifier\n", \
														parser->option);
		status = 2;
		return ;
	}
	variable = variable_format(env_variable, str);
	if (!*str)
		export_no_command(env_variable, exp_variable);
	else if (!*variable)
	{
		ft_printf("minishell: export: enclose in quotation marks\n");
		status = 2;
	}
	else if (check_equal(str))
		exp_variable = input_exp_variable(str, env_variable, exp_variable, 0);
	else
		do_export(env_variable, exp_variable, variable);
	free(variable);
}
