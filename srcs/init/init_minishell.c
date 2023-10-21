/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:40:38 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/21 11:35:19 by csakamot         ###   ########.fr       */
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
	return (data);
}

	// ft_memset(data, 0, sizeof(t_data));
	// ft_memset(exe_built, 0, sizeof(t_exe));
	// ft_memset(sig_act, 0, sizeof(t_signal));