/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:55:19 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/26 13:48:03 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

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
		variable = ft_strjoin("declear -x ", tmp_str);
		free(tmp_str);
	}
	else
		variable = ft_strjoin("declear -x ", str);
	new = new_exp_node(variable, 0);
	head->prev = new;
	exp_variable->next = new;
	new->prev = exp_variable;
	new->next = head;
	return (head);
}


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

char	*variable_format(char *str)
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
		return ((char *)ft_calloc(sizeof(char), 0));
	result = no_enclose_malloc(str);
	result = input_no_enclose(result, str);
	return (result);
}
