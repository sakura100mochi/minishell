/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/18 00:26:19 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_status_format(t_env *env, int status)
{
	env->status = status;
	if (g_signal != 0)
	{
		env->status = g_signal;
		g_signal = 0;
	}
	else if (status == 512)
		env->status = 2;
	else if (status == 256)
		env->status = 1;
	else if (status == 32512)
		env->status = 127;
	return ;
}
