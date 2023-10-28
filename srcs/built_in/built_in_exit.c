/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:15 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/28 16:10:54 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static int	ft_strdigit(char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (!ft_isdigit(str[index]))
			return (NO);
		index++;
	}
	return (YES);
}

static void	judge_exit_status(char **array, size_t index, size_t flag)
{
	if (!flag && index == 1)
	{
		ft_printf("exit\n");
		exit(ft_atoi(array[0]));
	}
	else if (flag && index == 0)
	{
		ft_printf("exit\nminishell: exit: %s: \
numeric argument required\n", array[0]);
		exit(255);
	}
	return ;
}

static void	check_file_array(char **array, size_t *index, size_t *flag)
{
	while (array[*index] != NULL)
	{
		if (!ft_strdigit(array[*index]))
		{
			*flag = 1;
			break ;
		}
		*index = *index + 1;
	}
	return ;
}

void	built_in_exit(t_env *env, t_parser *parser, char **array)
{
	size_t	index;
	size_t	flag;

	index = 0;
	flag = 0;
	if (parser->option != NULL)
	{
		ft_printf("exit\nminishell: exit: %s: numeric \
argument required\n", parser->option);
		exit(255);
	}
	check_file_array(array, &index, &flag);
	if ((!flag && index > 1) || (flag && index > 0))
	{
		ft_printf("exit\nminishell: exit: too many arguments\n");
		env->status = 1;
		return ;
	}
	judge_exit_status(array, index, flag);
	exit(env->status);
	return ;
}
