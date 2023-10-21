/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:15 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/21 08:29:16 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static int	check_argument(t_env *env, char *file)
{
	while (*file != '\0')
	{
		if (*file == ' ')
		{
			ft_printf("exit\nminishell: exit: numeric argument required\n");
			env->status = 1;
			return (1);
		}
		if (!ft_isdigit(*file))
		{
			ft_printf("exit\n");
			ft_printf("minishell: exit: %s: numeric argument required\n", file);
			return (0);
		}
		file++;
	}
	ft_printf("exit\n");
	return (0);
}

void	built_in_exit(t_data *data, char *file)
{
	if (*file && check_argument(data->env, file))
		return ;
	if (!*file)
		ft_printf("exit\n");
	free(data->prompt);
	free_all(data);
	exit(EXIT_SUCCESS);
	return ;
}
