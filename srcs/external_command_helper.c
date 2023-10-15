/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:23:10 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/15 14:14:21 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	count_file_nbr(char *file)
{
	size_t	index;
	size_t	count;
	size_t	flag;

	index = 0;
	count = 0;
	flag = 0;
	while (file[index] != '\0')
	{
		if (!flag && (file[index] != ' ' && file[index] != '	'))
		{
			count++;
			flag++;
		}
		else if (file[index] == ' ' || file[index] == '	')
			flag = 0;
		index++;
	}
	return (count);
}

char	**add_file_to_array(char **result, char *file, size_t index, size_t len)
{
	size_t	start;
	size_t	end;
	size_t	flag;

	start = 0;
	end = 0;
	flag = 0;
	while (index < len)
	{
		if (!flag && file[end] != ' ' && file[end] != '	')
		{
			flag++;
			start = end;
		}
		else if (flag && (file[end] == ' ' || file[end] == '	'))
		{
			result[index++] = ft_substr(file, start, end - start);
			flag--;
		}
		end++;
	}
	return (result);
}
