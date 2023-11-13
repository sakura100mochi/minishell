/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:23:10 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/14 06:13:24 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/built_in.h"
#include "../includes/error.h"

size_t	optionlen(char *option)
{
	size_t	index;
	size_t	result;

	index = 0;
	result = 1;
	while (option[index] != '\0')
	{
		if (option[index] == ' ')
			result++;
		index++;
	}
	return (result);
}

size_t	arraylen(char **array)
{
	size_t	result;

	result = 0;
	if (!array)
		return (0);
	while (array[result] != NULL)
		result++;
	return (result);
}

void	add_option_to_array(char **result, char *option, size_t *index)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = 0;
	while (option[end] != '\0')
	{
		if (option[end] == ' ')
		{
			result[*index] = ft_substr(option, start, end);
			start = end + 1;
			*index = *index + 1;
		}
		end++;
	}
	result[*index] = ft_substr(option, start, end);
	*index = *index + 1;
	return ;
}

void	add_file_to_array(char **result, char **array, \
										size_t index, size_t len)
{
	while (index < len)
	{
		result[index] = ft_strdup(*array++);
		index++;
	}
	return ;
}
