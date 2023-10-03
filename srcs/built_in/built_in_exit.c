/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:15 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/03 14:17:41 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static int	check_argument(char *file)
{
	size_t	flag;

	flag = 0;
	while (*file != '\0')
	{
		if (*file == ' ')
		{
			flag++;
			ft_printf("exit\nminishell: exit: numeric argument required\n");
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
	if (*file && check_argument(file))
		return ;
	if (!*file)
		ft_printf("exit\n");
	free(data->prompt);
	delete_all_env_node(data->env);
	exit(EXIT_SUCCESS);
	return ;
}
