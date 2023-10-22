/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:08:01 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/22 13:58:35 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/error.h"

int	no_file(t_data *data, char *file_name)
{
	ft_printf("minishell: no such file or directory : %s\n", file_name);
	data->env->status = 1;
	return (NO);
}

int	permission(t_data *data, char *file_name)
{
	ft_printf("minishell: %s: Permission denied\n", file_name);
	data->env->status = 126;
	return (NO);
}
