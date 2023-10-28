/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:10 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/28 16:47:18 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static t_env	*rm_env_variable(char *str, t_env *env_variable)
{
	size_t	len;
	char	*tmp_str;
	t_env	*head;
	t_env	*current_location;

	head = env_variable;
	len = ft_strlen(str);
	tmp_str = ft_strjoin(str, "=");
	env_variable = env_variable->next;
	while (!env_variable->head)
	{
		if (!ft_strncmp(env_variable->variable, tmp_str, len + 1))
		{
			free(env_variable->variable);
			current_location = env_variable;
			env_variable = env_variable->next;
			current_location->prev->next = env_variable;
			env_variable->prev = current_location->prev;
			free(current_location);
			continue ;
		}
		env_variable = env_variable->next;
	}
	free(tmp_str);
	return (head);
}

static char	*exp_variable_format(char *str)
{
	char	*tmp_str;
	char	*result;

	tmp_str = ft_strjoin("declare -x ", str);
	result = ft_strjoin(tmp_str, "=");
	free(tmp_str);
	return (result);
}

static t_exp	*rm_exp_variable(char *str, t_exp *exp_variable)
{
	size_t	len;
	char	*tmp_str;
	t_exp	*head;
	t_exp	*current_location;

	head = exp_variable;
	len = ft_strlen(str);
	tmp_str = exp_variable_format(str);
	exp_variable = exp_variable->next;
	while (!exp_variable->head)
	{
		if (!ft_strncmp(exp_variable->variable, tmp_str, len + 11))
		{
			free(exp_variable->variable);
			current_location = exp_variable;
			exp_variable = exp_variable->next;
			current_location->prev->next = exp_variable;
			exp_variable->prev = current_location->prev;
			free(current_location);
			continue ;
		}
		exp_variable = exp_variable->next;
	}
	free(tmp_str);
	return (head);
}

static t_exp	*rm_exp_str(char *str, t_exp *exp_variable)
{
	size_t	len;
	char	*tmp_str;
	t_exp	*head;
	t_exp	*current_location;

	head = exp_variable;
	len = ft_strlen(str);
	tmp_str = ft_strjoin("declare -x ", str);
	exp_variable = exp_variable->next;
	while (!exp_variable->head)
	{
		if (!ft_strncmp(exp_variable->variable, tmp_str, len + 11))
		{
			free(exp_variable->variable);
			current_location = exp_variable;
			exp_variable = exp_variable->next;
			current_location->prev->next = exp_variable;
			exp_variable->prev = current_location->prev;
			free(current_location);
			continue ;
		}
		exp_variable = exp_variable->next;
	}
	free(tmp_str);
	return (head);
}

void	built_in_unset(t_parser *parser, t_env *env_variable, \
									t_exp *exp_variable, char **array)
{
	size_t	index;

	index = 0;
	while (array[index] != NULL)
	{
		if (!*array[index] && !parser->option)
		{
			env_variable->status = 0;
			return ;
		}
		else if (!parser->option || (parser->option && \
							ft_strlen(parser->option) == 1))
		{
			env_variable = rm_env_variable(array[index], env_variable);
			exp_variable = rm_exp_variable(array[index], exp_variable);
			exp_variable = rm_exp_str(array[index], exp_variable);
			env_variable->status = 0;
		}
		else if (parser->option && ft_strlen(parser->option) > 1)
		{
			ft_printf("minishell: unset: -%c: invalid option\n", \
													parser->option[1]);
			env_variable->status = 2;
		}
		index++;
	}
}
