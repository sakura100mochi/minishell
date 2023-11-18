/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/18 11:38:36 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/pipe.h"
#include "../../includes/error.h"

void	pipe_print_error(int *status, char *cmd)
{
	if (*status == 127 && !check_absolute_path(cmd))
		ft_printf("minishell: %s: command not found\n", cmd);
	else if (*status == 127)
		ft_printf("minishell: %s: No such file or directory\n", cmd);
	else if (*status == -1)
	{
		ft_printf("minishell: %s: No such file or directory\n", cmd);
		*status = 127;
	}
	return ;
}
