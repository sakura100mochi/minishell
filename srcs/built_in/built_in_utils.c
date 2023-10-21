/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:42:14 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/21 06:25:24 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

t_env	*serch_env_variable(t_env *head, char *variable)
{
	size_t	len;
	t_env	*serch_variable;

	serch_variable = head;
	if (*variable == '\0')
		return (serch_variable->prev);
	serch_variable = serch_variable->next;
	len = ft_strlen(variable);
	while (!serch_variable->head)
	{
		if (!ft_strncmp(serch_variable->variable, variable, len))
			break ;
		serch_variable = serch_variable->next;
	}
	return (serch_variable);
}

char	*wrap_with_quotes(char *str)
{
	int		flag;
	size_t	i;
	size_t	len;
	char	*result;

	flag = 0;
	i = 0;
	len = ft_strlen(str) + 2;
	result = (char *)ft_calloc(sizeof(char), (len + 1));
	while (i++ < len - 1)
	{
		if (!flag && i - 1 > 0 && result[i - 2] == '=')
		{
			result[i - 1] = '"';
			flag++;
		}
		else
			result[i - 1] = str[i - 1 - flag];
	}
	result[i - 1] = '"';
	result[i] = '\0';
	return (result);
}

char	*create_file_path(char *file)
{
	char	*result;

	result = ft_strjoin("/", file);
	if (!result)
		exit (EXIT_FAILURE);
	return (result);
}
