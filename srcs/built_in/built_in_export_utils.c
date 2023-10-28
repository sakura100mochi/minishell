/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:55:19 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/28 12:09:56 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

int	check_wrap_with_quotes(char *str)
{
	size_t	index;
	size_t	single;
	size_t	twofold;

	single = 0;
	twofold = 0;
	index = 0;
	while (str[index] != '\0')
	{
		if (!single && !twofold && str[index] == '\'')
			single++;
		else if (!single && !twofold && str[index] == '"')
			twofold++;
		else if (single && str[index] == '\'')
			single = 0;
		else if (twofold && str[index] == '"')
			twofold = 0;
		index++;
	}
	if (single || twofold)
		return (0);
	return (1);
}

static char	*no_enclose_malloc(char *str)
{
	char	*result;
	size_t	len;
	size_t	single;
	size_t	twofold;

	len = 0;
	single = 0;
	twofold = 0;
	while (*str)
	{
		if (!single && !twofold && *str == '\'')
			single++;
		if (!single && !twofold && *str == '"')
			twofold++;
		if ((single && *str == '\'') || (twofold && *str == '"'))
		{
			len -= 2;
			single = 0;
			twofold = 0;
		}
		len++;
		str++;
	}
	result = ft_calloc(sizeof(char), len + 1);
	return (result);
}

static char	*input_no_enclose(char *result, char *str)
{
	size_t	single;
	size_t	twofold;

	single = 0;
	twofold = 0;
	while (*str)
	{
		if (!single && !twofold && *str == '\'')
			single++;
		if (!single && !twofold && *str == '"')
			twofold++;
		if ((single && *str == '\'') || (twofold && *str == '"'))
		{
			single = 0;
			twofold = 0;
			continue ;
		}
		if ((single && *str == '\'') || (twofold && *str == '"'))
			continue ;
		*result = *str;
		result++;
		str++;
	}
	*result = '\0';
	return (result);
}

char	*variable_format(t_env *env, char *str)
{
	size_t	index;
	size_t	flag;
	char	*result;

	index = 0;
	flag = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '\'' || str[index] == '"')
			flag++;
		index++;
	}
	if (!flag)
		return (ft_strdup(str));
	if (check_wrap_with_quotes(str))
	{
		env->status = 1;
		return ((char *)ft_calloc(sizeof(char), 0));
	}
	result = no_enclose_malloc(str);
	result = input_no_enclose(result, str);
	return (result);
}

void	export_no_command(t_env *env_variable, t_exp *exp_variable)
{
	exp_variable = exp_variable->next;
	while (!exp_variable->head)
	{
		ft_printf("%s\n", exp_variable->variable);
		exp_variable = exp_variable->next;
	}
	env_variable->status = 0;
	return ;
}
