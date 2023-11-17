/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:40:38 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/17 21:47:53 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/error.h"

t_data	*init_minishell(t_data *data)
{
	t_exe		*exe_built;
	t_signal	*sig_act;

	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (!data)
		exit_malloc_error();
	exe_built = (t_exe *)ft_calloc(sizeof(t_exe), 1);
	if (!exe_built)
		exit_malloc_error();
	sig_act = (t_signal *)ft_calloc(sizeof(t_signal), 1);
	if (!sig_act)
		exit_malloc_error();
	data = init_env(data);
	data = init_exp(data);
	data->exe = exe_built;
	data->signal = sig_act;
	g_signal = 0;
	return (data);
}

	// ft_memset(data, 0, sizeof(t_data));
	// ft_memset(exe_built, 0, sizeof(t_exe));
	// ft_memset(sig_act, 0, sizeof(t_signal));