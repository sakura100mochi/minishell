/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:26:05 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/28 16:41:20 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"
#include "../../includes/error.h"

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

void	built_in_export(t_parser *parser, t_env *env_variable, \
									t_exp *exp_variable, char **array)
{
	size_t	index;
	char	*variable;

	index = 0;
	if (parser->option)
	{
		if (ft_strlen(parser->option) == 1)
		{
			ft_printf("minishell: export: '-': not a valid identifier\n");
			env_variable->status = 1;
		}
		else
		{
			ft_printf("minishell: export: '-%c': not a valid identifier\n", \
															parser->option[1]);
			env_variable->status = 2;
		}
		return ;
	}
	if (array[0] == NULL)
		export_no_command(env_variable, exp_variable);
	while (array[index] != NULL)
	{
		variable = variable_format(env_variable, array[index]);
		printf("##%s##\n", variable);
		if (!variable)
			exit_malloc_error();
		if (!*variable)
		{
			ft_printf("minishell: export: enclose in quotation marks\n");
			env_variable->status = 2;
		}
		else if (check_equal(array[index]))
		{
			if (check_expvariable_exist(exp_variable, array[index]))
			{
				free(variable);
				return ;
			}
			else
				exp_variable = input_exp_variable(variable, \
													exp_variable, 0);
			env_variable->status = 0;
		}
		else
			do_export(env_variable, exp_variable, variable, array[index]);
		free(variable);
		index++;
	}
}
